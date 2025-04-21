#include "KubernetesCluster.h"
#include <sstream>
#include <algorithm>
#include <iostream>

void KubernetesCluster::addNode(std::shared_ptr<Server> node) {
    nodes_.push_back(std::move(node));
}

bool KubernetesCluster::removePod(const std::string& name) {
    auto it = std::find_if(pods_.begin(), pods_.end(),
        [&name](const auto& pod) { return pod->getMetrics().find(name) != std::string::npos; });
    
    if (it != pods_.end()) {
        pods_.erase(it);
        return true;
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    std::cout << "-> Déploiement du " << *pod;
    
    if (schedulePod(*pod)) {
        pods_.push_back(std::move(pod));
        std::cout << "déployé avec succès." << std::endl;
    } else {
        std::cout << "Échec du déploiement du " << *pod << ": ressources insuffisantes." << std::endl;
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    double total_cpu = 0.0;
    double total_memory = 0.0;
    
    // Calculate total resources needed
    for (const auto& container : pod.getContainers()) {
        total_cpu += container->getMetrics().find("CPU:") != std::string::npos ? 
            std::stod(container->getMetrics().substr(container->getMetrics().find("CPU:") + 4)) : 0.0;
        total_memory += container->getMetrics().find("Memory:") != std::string::npos ? 
            std::stod(container->getMetrics().substr(container->getMetrics().find("Memory:") + 8)) : 0.0;
    }
    
    // Find a node with sufficient resources
    for (auto& node : nodes_) {
        if (node->allocate(total_cpu, total_memory)) {
            std::cout << "sur le noeud " << *node << std::endl;
            pod.deploy();
            return true;
        }
    }
    return false;
}

Pod* KubernetesCluster::getPod(const std::string& name) {
    auto it = std::find_if(pods_.begin(), pods_.end(),
        [&name](const auto& pod) { return pod->getMetrics().find(name) != std::string::npos; });
    
    return it != pods_.end() ? it->get() : nullptr;
}

std::string KubernetesCluster::getMetrics() const {
    std::stringstream ss;
    ss << "=== Cluster Metrics ===\n";
    for (const auto& node : nodes_) {
        ss << *node << "\n";
    }
    for (const auto& pod : pods_) {
        ss << *pod;
    }
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
} 