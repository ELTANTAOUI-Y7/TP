#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Graphe {
    int sommets; // Nombre de sommets
    vector<int>* listeAdj; // Tableau de listes d'adjacence

    Graphe(int sommets) {
        this->sommets = sommets;
        listeAdj = new vector<int>[sommets];
    }

    ~Graphe() {
        delete[] listeAdj;
    }
};

void ajouterArete(Graphe& graphe, int u, int v) {
    graphe.listeAdj[u].push_back(v); // Ajouter v à la liste d'adjacence de u
}

void parcoursDFSUtil(Graphe& graphe, int sommet, bool visites[]) {
    stack<int> pile;
    pile.push(sommet);

    while (!pile.empty()) {
        sommet = pile.top();
        pile.pop();

        if (!visites[sommet]) {
            cout << sommet << " ";
            visites[sommet] = true;
        }

        for (auto i = graphe.listeAdj[sommet].rbegin(); i != graphe.listeAdj[sommet].rend(); ++i) {
            if (!visites[*i]) {
                pile.push(*i);
            }
        }
    }
}

void parcoursDFS(Graphe& graphe, int sommet) {
    bool* visites = new bool[graphe.sommets];
    for (int i = 0; i < graphe.sommets; i++) {
        visites[i] = false;
    }

    parcoursDFSUtil(graphe, sommet, visites);

    delete[] visites;
}

int main() {
    Graphe graphe(4);
    ajouterArete(graphe, 0, 1);
    ajouterArete(graphe, 0, 2);
    ajouterArete(graphe, 1, 2);
    ajouterArete(graphe, 2, 0);
    ajouterArete(graphe, 2, 3);
    ajouterArete(graphe, 3, 3);

    cout << "Parcours en profondeur à partir du sommet 0 :" << endl;
    parcoursDFS(graphe, 0);

    return 0;
}

