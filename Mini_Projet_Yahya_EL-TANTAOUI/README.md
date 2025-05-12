# Mini_Projet_Anir_Achibane
## Partie 1 et 2:

veuillez choisir entre `main.cpp` et `main2.cpp` pour executer soit le main de la 1ère ou la 2ème partie du Mini Projet.

## Compilation

Pour compiler tous les fichiers `.cpp` :

```sh
make
```

Pour supprimer les fichiers générés (ex. : `main.exe`) :

```sh
make clean
```

## Exécution

Pour exécuter le programme principal :

```sh
.\main
```

## Objectif

Implémenter un simulateur C++ d’une infrastructure cloud minimaliste en modélisant les entités suivantes :

- `Resource` (classe de base abstraite)
- `Container` (hérite de `Resource`)
- `Pod` (agrège des `Container`)
- `Server` (hérite de `Resource`)
- `KubernetesCluster` (agrège des `Server` et `Pod`)
- Utilisation des smart pointers : `std::unique_ptr`, `std::shared_ptr`
- Manipulations et tests sur `main.cpp`

## Structure des fichiers

```sh
Mini_Projet_Anir_Achibane/
├── Resource.hpp / Resource.cpp
│   - Classe abstraite avec id, cpu, memory, active
│   - Méthodes virtuelles : start(), stop(), getMetrics()
│
├── Container.hpp / Container.cpp
│   - Hérite de Resource
│   - Attribut : image
│   - Surcharge de operator<<
│
├── Pod.hpp / Pod.cpp
│   - Contient des std::unique_ptr<Container>
│   - Méthodes : addContainer(), removeContainer(), deploy(), getMetrics()
│
├── Server.hpp / Server.cpp
│   - Hérite de Resource
│   - Gestion des ressources disponibles
│
├── KubernetesCluster.hpp / KubernetesCluster.cpp
│   - Gère les Server et Pod
│   - Méthodes : addNode(), deployPod(), removePod(), getMetrics()
│
├── Cloud_Util.hpp / Cloud_Util.cpp
│   - Fonctions utilitaires : display(), deployPods()
│
├── main.cpp
│   - Tests des fonctionnalités de déploiement, suppression et affichage
│   - Deux clusters testés avec divers cas (succès / échec)
│
├── Cloud Exception.cpp
│   - Création des exceptions d'allocation des serveurs et accès aux fichiers
│
├── MetricLogger.hpp / MetricLogger.cpp
│   - classe template pour écrire les métriques d'un objet quelconque dans un flux au choix
│
├── Makefile
```

## Fonctionnalités testées

- Déploiement de pods avec vérification des ressources
- Affichage détaillé des métriques des clusters
- Suppression dynamique de conteneurs, pods, et clusters
- Utilisation de plusieurs clusters simultanément
