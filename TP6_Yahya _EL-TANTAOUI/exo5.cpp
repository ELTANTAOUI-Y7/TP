#include <iostream>
#include <list>
#include <unordered_map>
#include <memory>

using namespace std;

struct ElementCache {
    int cle;
    int valeur;

    ElementCache(int c, int v) : cle(c), valeur(v) {}
};

struct MemoireLRU {
    int capacite;
    list<shared_ptr<ElementCache>> listeCache;
    unordered_map<int, weak_ptr<ElementCache>> mapCache;

    MemoireLRU(int cap) : capacite(cap) {}

    void deplacerEnTete(shared_ptr<ElementCache> element) {
        listeCache.remove(element);
        listeCache.push_front(element);
    }

    int obtenir(int cle) {
        auto it = mapCache.find(cle);
        if (it == mapCache.end() || it->second.expired()) {
            return -1; // Clé non trouvée
        }
        auto element = it->second.lock();
        deplacerEnTete(element);
        return element->valeur;
    }

    void ajouter(int cle, int valeur) {
        auto it = mapCache.find(cle);
        if (it != mapCache.end() && !it->second.expired()) {
            auto element = it->second.lock();
            element->valeur = valeur;
            deplacerEnTete(element);
        } else {
            if (listeCache.size() == capacite) {
                auto dernier = listeCache.back();
                mapCache.erase(dernier->cle);
                listeCache.pop_back();
            }
            auto nouvelElement = make_shared<ElementCache>(cle, valeur);
            listeCache.push_front(nouvelElement);
            mapCache[cle] = nouvelElement;
        }
    }

    void afficher() {
        for (auto& element : listeCache) {
            cout << element->cle << " ";
        }
        cout << endl;
    }
};

int main() {
    MemoireLRU cache(4);

    cache.ajouter(1, 1);
    cache.ajouter(2, 2);
    cache.ajouter(3, 3);
    cache.ajouter(1, 1); // Accès à la clé 1
    cache.ajouter(4, 4);

    cout << "État actuel du cache :" << endl;
    cache.afficher();

    cache.ajouter(5, 5); // Cela doit éjecter la clé 2

    cout << "Accès à la clé 5 -> Éviction de la clé 2" << endl;
    cout << "État actuel du cache :" << endl;
    cache.afficher();

    return 0;
}
