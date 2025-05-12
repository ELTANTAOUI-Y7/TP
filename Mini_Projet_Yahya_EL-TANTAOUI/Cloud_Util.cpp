#include "Resource.hpp"
#include "Container.hpp"
#include "Pod.hpp"
#include "Server.hpp"
#include "Cloud_Util.hpp"
#include "KubernetesCluster.hpp"

#include <memory>
#include <vector>
using namespace std;

void display(const KubernetesCluster& cluster){
    cout << cluster << endl;
};

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods){
    for(auto& p: pods){
        cluster.deployPod(move(p));
    }
    pods.clear();
};