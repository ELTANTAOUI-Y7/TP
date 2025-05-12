#include "Resource.hpp"
#include "Container.hpp"
#include "Pod.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
using namespace std;

Pod::Pod(string name, unordered_map<string, string> labels):
    name_(name), labels_(labels){}

void Pod::addContainer(unique_ptr<Container> container){
    containers_.push_back(move(container));
    cout << "Container " << containers_.back()->getMetrics() << " added to Pod: " << name_ << endl;

};

bool Pod::removeContainer(const string& id){
    for (int i = 0; i < containers_.size(); i++){
        if (containers_[i]->get_id() == id){
            cout << "Container " << *containers_[i] << " removed from Pod: " << name_ << endl;

            containers_.erase(containers_.begin() + i);
            return true;
        }
    }
    cout << "Container with id: " << id << " not found in " << this << endl;
    return false;
};

void Pod::deploy(){
    for(auto& c : containers_ ){
        c->start();
    }
    cout << "Pod " << name_ << " successfully deployed" << endl;

};

string Pod::getMetrics() const{
    string metrics = "[Pod: " + name_ + "]";
    for(auto& c : containers_){
        metrics += c->getMetrics() + "\n"; 
    }
    return metrics;
};

ostream& operator<<(ostream& os, const Pod& p){
    os << p.getMetrics();
    return os;
};