#include <iostream>
using namespace std;
#include <array>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

#ifndef EXERCICE
#define EXERCICE 1
#endif

#if EXERCICE == 1
int main() {
    int valeurs[5] = {10, 20, 30, 40, 50};
    int total = 0;
    cout << "Éléments : ";
    for (int i = 0; i < 5; i++) {
        cout << valeurs[i] << " ";
        total += valeurs[i];
    }
    cout << "\nSomme : " << total << endl;
}

#elif EXERCICE == 2
int main() {
    int matrice[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int somme_diag = 0;
    cout << "Matrice : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
        somme_diag += matrice[i][i];
    }
    cout << "Somme diagonale : " << somme_diag << endl;
    return 0;
}

#elif EXERCICE == 3
int main() {
    std::array<int, 5> tableau = {1, 2, 3, 4, 5};
    cout << "Original : ";
    for (int val : tableau) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inversé : ";
    for (auto it = tableau.rbegin(); it != tableau.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

#elif EXERCICE == 4
int main() {
    vector<int> nombres;
    int entree;
    cout << "Entrez des nombres (entrez -1 pour terminer) : ";
    while (cin >> entree && entree != -1) {
        nombres.push_back(entree);
    }

    cout << "Doublé : ";
    for (int nombre : nombres) {
        cout << nombre * 2 << " ";
    }
    cout << endl;

    return 0;
}

#elif EXERCICE == 5
int main() {
    std::list<int> liste = {10, 20, 30, 40, 50};
    liste.push_front(0);
    liste.push_back(60);

    cout << "Après insertion : ";
    for (int nombre : liste) {
        cout << nombre << " ";
    }
    cout << endl;
    return 0;
}

#elif EXERCICE == 6
int main() {
    set<int> ensemble = {5, 10, 15, 20};
    ensemble.insert(10);
    for (int val : ensemble) {
        cout << val << " ";
    }
    cout << endl;
}

#elif EXERCICE == 7
int main() {
    map<string, int> notes = {{"John", 85}, {"Bob", 78}, {"Alice", 90}};
    for (const auto& element : notes) {
        cout << element.first << " : " << element.second << endl;
    }
}

#elif EXERCICE == 8
int main() {
    string phrase = "pomme banane pomme orange banane banane";
    unordered_map<string, int> compteur;
    stringstream ss(phrase);
    string mot;

    while (ss >> mot) {
        compteur[mot]++;
    }

    for (const auto& element : compteur) {
        cout << element.first << " : " << element.second << endl;
    }

    return 0;
}

#elif EXERCICE == 9
int main() {
    vector<int> valeurs = {30, 10, 50, 20, 40};
    cout << "Original : ";
    for (int nombre : valeurs) {
        cout << nombre << " ";
    }
    cout << endl;

    sort(valeurs.begin(), valeurs.end());

    cout << "Trié : ";
    for (int nombre : valeurs) {
        cout << nombre << " ";
    }
    cout << endl;

    return 0;
}

#elif EXERCICE == 10
int main() {
    set<int> valeurs = {100, 4, 200, 1, 3, 2};
    set<int> sequence_max;
    int longueur_max = 0;

    for (int val : valeurs) {
        if (valeurs.find(val - 1) == valeurs.end()) {
            int courant = val, taille = 1;
            set<int> sequence;
            sequence.insert(courant);

            while (valeurs.find(courant + 1) != valeurs.end()) {
                courant++;
                taille++;
                sequence.insert(courant);
            }

            if (taille > longueur_max) {
                sequence_max = sequence;
                longueur_max = taille;
            }
        }
    }

    cout << "Plus longue séquence : " << longueur_max << " (";
    for (int val : sequence_max) {
        cout << val << ", ";
    }
    cout << ")" << endl;

    return 0;
}

#elif EXERCICE == 11
void ajouter(unordered_map<int, list<pair<int, int>>::iterator>& cache,
              list<pair<int, int>>& lru, int& capacite, int cle, int valeur) {
    if (cache.find(cle) != cache.end()) {
        cache[cle]->second = valeur;
        lru.splice(lru.begin(), lru, cache[cle]);
    } else {
        if (lru.size() == capacite) {
            auto dernier = lru.back();
            cache.erase(dernier.first);
            lru.pop_back();
        }
        lru.push_front({cle, valeur});
        cache[cle] = lru.begin();
    }
}

int obtenir(unordered_map<int, list<pair<int, int>>::iterator>& cache,
            list<pair<int, int>>& lru, int cle) {
    if (cache.find(cle) == cache.end()) return -1;
    lru.splice(lru.begin(), lru, cache[cle]);
    return cache[cle]->second;
}

int main() {
    int capacite = 2;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> lru;
    
    ajouter(cache, lru, capacite, 1, 10);
    ajouter(cache, lru, capacite, 2, 20);
    cout << "Cache : ";
    for (auto p : lru) cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;
    return 0;
}
#endif
