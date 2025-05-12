#include "KubernetesCluster.hpp"
#include "Resource.hpp"
#include "Container.hpp"
#include "Pod.hpp"
#include "Server.hpp"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

void KubernetesCluster::addNode(shared_ptr<Server> node){
    nodes_.push_back(node);
    cout << *node << "added to KubernetesCluster" << endl;
}

bool KubernetesCluster::removePod(const string& name){
    for(int i = 0; i < pods_.size(); i++){
        if (pods_[i]->get_name() == name){
            cout << *pods_[i] << " removed from " << this << endl;
            pods_.erase(pods_.begin() + i);
            return true;
        }
    }
    cout << "Couldn't find pod " << name << " in " << this << endl;
    return false;
    
}

void KubernetesCluster::deployPod(unique_ptr<Pod> pod){
    string serverID = schedulePod(*pod);
    if (serverID != "none"){
        double pod_cpu = 0;
        double pod_memory = 0;
        const vector< unique_ptr<Container>>& containers = pod->getContainers();
        for (int i = 0; i < containers.size(); i++){
            pod_cpu += containers[i]->get_cpu();
            pod_memory += containers[i]->get_memory();
        }
    
        for(auto& s : nodes_ ){
            if (s->get_id() == serverID){
                s->allocate(pod_cpu, pod_memory);
                cout << *pod << " deployed in KubernetesCluster" << *this << endl;
                pods_.push_back(move(pod));
                
                return;
            }
        }
    }
    else{
        cout << "Can't deploy " << *pod << " in KubenetesCluster" << endl;
    }

}

string KubernetesCluster::schedulePod(Pod& pod){
    double pod_cpu = 0;
    double pod_memory = 0;
    const vector< unique_ptr<Container>>& containers = pod.getContainers();
    for (int i = 0; i < containers.size(); i++){
        pod_cpu += containers[i]->get_cpu();
        pod_memory += containers[i]->get_memory();
    }

    for(auto& s: nodes_){
        if (pod_cpu <= s->get_available_cpu() &&
            pod_memory <= s->get_available_memory() ){
                return s->get_id();
        }
    }

    return "none";
}

Pod* KubernetesCluster::getPod(const string& name){
    for (auto& p : pods_){
        if (p->get_name() == name){
            cout << "Pod " << name << " found in KubernetesCluster:" << *this << endl;
            return p.get();
        }
    }
    cout << "Pod " << name << " not found in KubernetesCluster: " << *this << endl;
    return nullptr;
}

string KubernetesCluster::getMetrics() const{
    string metrics = "=== Cluster Metrics ===\n";
    for (const auto& s: nodes_){
        metrics += s->getMetrics() + "\n"; 
    }
    for(const auto& p: pods_){
        metrics += p->getMetrics() + "\n";
    }
    return metrics;
}

ostream& operator<<(ostream& os, const KubernetesCluster& c){
    os << c.getMetrics();
    return os;
}