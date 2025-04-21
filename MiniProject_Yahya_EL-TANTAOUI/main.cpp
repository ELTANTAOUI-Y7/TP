#include "Cloud_Util.h"
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;

    std::cout << "\n=== Cluster 1 ===\n";
    
    // Creer un vecteur de clusters
    std::vector<KubernetesCluster> clusters(2); // Deux clusters

    //=== Configurer le premier cluster ===
    KubernetesCluster& cluster1 = clusters[0];
    cluster1.addNode(std::make_shared<Server>("node1-1", 4.0, 8192.0));
    cluster1.addNode(std::make_shared<Server>("node1-2", 8.0, 14096.0));

    // Creer des conteneurs pour le premier cluster
    auto c1_1 = std::make_unique<Container>("c1-1", "nginx:latest", 2, 5120.0);
    auto c1_2 = std::make_unique<Container>("c1-2", "redis:latest", 6, 2560.0);

    // Creer un pod pour le premier cluster
    auto pod1_1 = std::make_unique<Pod>("web-pod", std::unordered_map<std::string, std::string>{{"app", "nginx"}});
    pod1_1->addContainer(std::move(c1_1));
    pod1_1->addContainer(std::move(c1_2));

    // Creer un autre pod pour le premier cluster
    auto c1_3 = std::make_unique<Container>("c1-3", "mysql:latest", 0.7, 1024.0);
    auto pod1_2 = std::make_unique<Pod>("db-pod", std::unordered_map<std::string, std::string>{{"app", "mysql"}});
    pod1_2->addContainer(std::move(c1_3));

    // Deployer les pods dans le premier cluster
    std::vector<std::unique_ptr<Pod>> pods1;
    pods1.push_back(std::move(pod1_1));
    pods1.push_back(std::move(pod1_2));
    deployPods(cluster1, pods1);

    //=== Test des fonctionnalites ===
    // Test 0: Deploiement d'un pod avec ressources insuffisantes
    std::cout << "\n=== Test 0 : Deploiement d'un pod avec ressources insuffisantes ===\n";
    auto large_container = std::make_unique<Container>("large-c1", "large-app:latest", 5.0, 10000.0);
    auto large_pod = std::make_unique<Pod>("large-pod", std::unordered_map<std::string, std::string>{{"app", "large"}});
    large_pod->addContainer(std::move(large_container));
    cluster1.deployPod(std::move(large_pod));

    std::cout << "\n=== Cluster 2 ===\n";
    
    //=== Configurer le second cluster ===
    KubernetesCluster& cluster2 = clusters[1];
    cluster2.addNode(std::make_shared<Server>("node2-1", 3.0, 6144.0));
    cluster2.addNode(std::make_shared<Server>("node2-2", 1.5, 2048.0));

    // Creer des conteneurs pour le second cluster
    auto c2_1 = std::make_unique<Container>("c2-1", "node:latest", 0.6, 768.0);
    auto c2_2 = std::make_unique<Container>("c2-2-2", "memcached:latest", 0.4, 384.0);

    // Creer un pod pour le second cluster
    auto pod2_1 = std::make_unique<Pod>("api-pod", std::unordered_map<std::string, std::string>{{"app", "node"}});
    pod2_1->addContainer(std::move(c2_1));

    // Creer un autre pod pour le second cluster
    auto pod2_2 = std::make_unique<Pod>("cache-pod", std::unordered_map<std::string, std::string>{{"app", "memcached"}});
    pod2_2->addContainer(std::move(c2_2));

    // Deployer les pods dans le second cluster
    std::vector<std::unique_ptr<Pod>> pods2;
    pods2.push_back(std::move(pod2_1));
    pods2.push_back(std::move(pod2_2));
    deployPods(cluster2, pods2);

    // Afficher l'etat initial
    std::cout << "\n=== Etat initial ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }

    // Test 1: Supprimer un conteneur (c1-2 du web-pod dans cluster1)
    std::cout << "\n=== Test 1 : Suppression du conteneur c1-2 (redis) ===\n";
    Pod* web_pod = clusters[0].getPod("web-pod");
    if (web_pod && web_pod->removeContainer("c1-2")) {
        std::cout << "Conteneur c1-2 supprime du web-pod\n";
    } else {
        std::cout << "Conteneur c1-2 ou web-pod non trouve\n";
    }

    // Afficher l'etat apres suppression du conteneur
    std::cout << "\n=== Etat apres suppression du conteneur ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }

    // Test 2: Supprimer un pod (db-pod du cluster1)
    std::cout << "\n=== Test 2 : Suppression du pod db-pod ===\n";
    if (clusters[0].removePod("db-pod")) {
        std::cout << "Pod db-pod supprime du cluster 1\n";
    } else {
        std::cout << "Pod db-pod non trouve\n";
    }

    // Afficher l'etat apres suppression du pod
    std::cout << "\n=== Etat apres suppression du pod ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }

    // Test 3: Supprimer un cluster (cluster2)
    std::cout << "\n=== Test 3 : Suppression du cluster 2 ===\n";
    clusters.erase(clusters.begin() + 1);

    // Afficher l'etat final
    std::cout << "\n=== Etat apres suppression du cluster ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }

    return 0;
}