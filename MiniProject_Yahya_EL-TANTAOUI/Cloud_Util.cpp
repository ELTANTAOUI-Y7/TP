#include "Cloud_Util.h"
#include <iostream>

void display(const KubernetesCluster& cluster) {
    std::cout << cluster.getMetrics();
}

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods) {
    for (auto& pod : pods) {
        cluster.deployPod(std::move(pod));
    }
} 