#include <iostream>

using namespace std;

struct Noeud {
    int valeur;
    Noeud* gauche;
    Noeud* droite;

    Noeud(int val) : valeur(val), gauche(nullptr), droite(nullptr) {}
};

struct ArbreBST {
    Noeud* racine;

    ArbreBST() : racine(nullptr) {}

    void inserer(int val) {
        racine = insererRec(racine, val);
    }

    bool rechercher(int val) {
        return rechercherRec(racine, val);
    }

    void supprimer(int val) {
        racine = supprimerRec(racine, val);
    }

    void parcoursInfixe() {
        parcoursInfixeRec(racine);
        cout << endl;
    }

private:
    Noeud* insererRec(Noeud* noeud, int val) {
        if (noeud == nullptr) {
            return new Noeud(val);
        }
        if (val < noeud->valeur) {
            noeud->gauche = insererRec(noeud->gauche, val);
        } else if (val > noeud->valeur) {
            noeud->droite = insererRec(noeud->droite, val);
        }
        return noeud;
    }

    bool rechercherRec(Noeud* noeud, int val) {
        if (noeud == nullptr) {
            return false;
        }
        if (val == noeud->valeur) {
            return true;
        }
        if (val < noeud->valeur) {
            return rechercherRec(noeud->gauche, val);
        } else {
            return rechercherRec(noeud->droite, val);
        }
    }

    Noeud* supprimerRec(Noeud* noeud, int val) {
        if (noeud == nullptr) {
            return noeud;
        }
        if (val < noeud->valeur) {
            noeud->gauche = supprimerRec(noeud->gauche, val);
        } else if (val > noeud->valeur) {
            noeud->droite = supprimerRec(noeud->droite, val);
        } else {
            if (noeud->gauche == nullptr) {
                Noeud* temp = noeud->droite;
                delete noeud;
                return temp;
            } else if (noeud->droite == nullptr) {
                Noeud* temp = noeud->gauche;
                delete noeud;
                return temp;
            }
            Noeud* temp = noeudMinValeur(noeud->droite);
            noeud->valeur = temp->valeur;
            noeud->droite = supprimerRec(noeud->droite, temp->valeur);
        }
        return noeud;
    }

    Noeud* noeudMinValeur(Noeud* noeud) {
        Noeud* courant = noeud;
        while (courant && courant->gauche != nullptr) {
            courant = courant->gauche;
        }
        return courant;
    }

    void parcoursInfixeRec(Noeud* noeud) {
        if (noeud != nullptr) {
            parcoursInfixeRec(noeud->gauche);
            cout << noeud->valeur << " ";
            parcoursInfixeRec(noeud->droite);
        }
    }
};

int main() {
    ArbreBST arbre;
    arbre.inserer(5);
    arbre.inserer(3);
    arbre.inserer(7);
    arbre.inserer(2);
    arbre.inserer(4);
    arbre.inserer(6);
    arbre.inserer(8);

    cout << "Parcours infixe :" << endl;
    arbre.parcoursInfixe();

    cout << "Recherche de 4 : " << (arbre.rechercher(4) ? "Trouvé" : "Non trouvé") << endl;

    arbre.supprimer(4);
    cout << "Parcours infixe après suppression :" << endl;
    arbre.parcoursInfixe();

    return 0;
}
