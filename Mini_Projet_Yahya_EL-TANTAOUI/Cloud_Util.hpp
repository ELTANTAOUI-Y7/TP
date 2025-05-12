#ifndef CLOUD_UTIL_HPP
#define CLOUD_UTIL_HPP

#include "Resource.hpp"
#include "Container.hpp"
#include "Pod.hpp"
#include "Server.hpp"
#include "KubernetesCluster.hpp"

#include <memory>
#include <vector>

void display(const KubernetesCluster& cluster);
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);

#endif