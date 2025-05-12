#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <iomanip>
#include <algorithm>

#include "Container.hpp"
#include "Pod.hpp"
#include "Server.hpp"
#include "KubernetesCluster.hpp"
#include "Cloud_Util.hpp"
#include "CloudExceptions.hpp"
#include "MetricLogger.hpp"

int main() {
    // Produit une exception AllocationException


    //std::cout << "=== Test AllocationException direct ===\n";
    /* Modifier cette partie pour gérer l'exception*/
    //Server failNode("fail-node", 1.0, 1024.0);
    //failNode.allocate(4.0, 4096.0); // 
    

    std::cout << "\n=== Test FileException ===\n";
    KubernetesCluster cluster;
    auto nodeX = std::make_shared<Server>("nodeX", 12.0, 12048.0);
    nodeX->start(); // activer le noeud
    cluster.addNode(nodeX); // cluster non vide

    /* Gérer l'erreur d'ouverture du fichier */
    saveClusterMetrics(cluster, "cluster1_metrics.txt");

    std::cout << "\n=== Test Lambda : serveurs inactifs ===\n";
    KubernetesCluster cluster1;
    auto inactiveServer = std::make_shared<Server>("node3", 2.0, 4096.0); // Ne sera pas activé
    cluster1.addNode(inactiveServer);

    /* Filtrer et afficher les serveurs inactifs à l'aide de la fonction getFilteredServers */
    auto inactifs = cluster1.getFilteredServers([](const Server& s) {
            return !s.isActive();
    });

    std::cout << "\n=== Déploiement sur un serveur inactif ===\n";

    auto c = std::make_unique<Container>("inactive-c1", "busybox", 1.0, 1024.0);
    auto pod = std::make_unique<Pod>("test-pod");
    pod->addContainer(std::move(c));

    /* Gérer l'erreur ici du deploiement */
    cluster1.deployPod(std::move(pod));
    std::cout << "\n=== Pods triés par nombre de conteneurs ===\n";
    
    // Création des conteneurs
    auto c1 = std::make_unique<Container>("c1", "nginx", 2.0, 1024.0);
    auto c2 = std::make_unique<Container>("c2", "redis", 4, 2048.0);
    auto c3 = std::make_unique<Container>("c3", "mysql", 2, 1024.0);
    auto c4 = std::make_unique<Container>("c4", "myapp", 10, 12024.0);

    // Création des pods
    auto pod1 = std::make_unique<Pod>("web-pod");
    pod1->addContainer(std::move(c1));
    pod1->addContainer(std::move(c2));
    
    auto pod2 = std::make_unique<Pod>("db-pod");
    pod2->addContainer(std::move(c3));
    
    // Déploiement sans planification réelle, on injecte les pods manuellement
    std::vector<std::unique_ptr<Pod>> pods;
    pods.push_back(std::move(pod1));
    pods.push_back(std::move(pod2));
    

    /* Gérer le deploiement */
    
    
    std::cout << "\n=== Tri des pods ===\n";
    std::sort(pods.begin(), pods.end(), [](const std::unique_ptr<Pod>& a, const std::unique_ptr<Pod>& b) {
        return a->getContainers().size() < b->getContainers().size();
    });
    std::vector<const Pod*> podRefs;
    
    for(const auto& pod : pods) {
        cout << *pod << endl;
    }


    std::cout << "\n=== Tous les conteneurs du cluster 1 ===\n";
    for (const auto& pod : cluster.get_pods()) {
        std::cout << *pod << std::endl;
        const auto& containers = pod->getContainers();
        for (const auto& container : containers) {
            std::cout << *container << std::endl;
        }
    }
    
}
