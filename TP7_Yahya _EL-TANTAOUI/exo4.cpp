#include <iostream>
#include <vector>
using namespace std;

class Objet {
public:
    string nom;
    int quantite;
    
    Objet(string n, int q) : nom{n}, quantite{q} {}
};

class Inventaire {
private:
    vector<Objet*> objets;

public:
    void ajouter(Objet* ob) {
        for (auto &O : objets) {
            if (O->nom == ob->nom) {
                O->quantite += ob->quantite;
                delete ob; // Libération mémoire
                return;
            }
        }
        objets.push_back(ob);
        cout << "Ajout de " << ob->nom << " (x" << ob->quantite << ")" << endl;
    }

    void retirer(Objet* ob) {
        for (auto it = objets.begin(); it != objets.end(); ++it) {
            Objet* O = *it;
            if (O->nom == ob->nom) {
                if (O->quantite > ob->quantite) {
                    O->quantite -= ob->quantite;
                    cout << "La quantité de " << O->nom << " est décrémentée." << endl;
                } else if (O->quantite == ob->quantite) {
                    cout << O->nom << " retiré avec succès" << endl;
                    delete O;
                    objets.erase(it);
                } else {
                    cout << "Impossible : quantité insuffisante pour " << O->nom << "." << endl;
                }
                delete ob; // Libération mémoire
                return;
            }
        }
        cout << "L'objet à retirer n'existe pas." << endl;
        delete ob; // Libération mémoire
    }

    void afficher() const {
        cout << "Inventaire :" << endl;
        for (const auto& O : objets) {
            cout << "- " << O->nom << " (x" << O->quantite << ")" << endl;
        }
    }

    ~Inventaire() {
        for (auto &O : objets) delete O;
        cout << "Mémoire de l'inventaire libérée." << endl;
    }
};

int main() {
    Inventaire Inv;

    Inv.ajouter(new Objet("Ananas", 4));
    Inv.ajouter(new Objet("Pomme", 3));
    Inv.ajouter(new Objet("Epée", 1));

    Inv.retirer(new Objet("Ananas", 2));
    Inv.retirer(new Objet("Pomme", 4));
    Inv.retirer(new Objet("Epée", 1));

    Inv.afficher();

    return 0;
}
