#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Fichier {
private:
    string nom_fichier;

public:
    Fichier(string nom) : nom_fichier(nom) {}

    void sauvegarder(const string& contenu) {
        cout << "Sauvegarde des données..." << endl;
        ofstream fichier(nom_fichier, ios::app); // Ouvre en mode ajout (append)
        if (!fichier) {
            cerr << "Erreur : impossible d'ouvrir le fichier pour l'écriture." << endl;
            return;
        }
        fichier << contenu << endl;
    }

    void charger() {
        cout << "Lecture des données..." << endl;
        ifstream fichier(nom_fichier);
        if (!fichier) {
            cerr << "Erreur : impossible d'ouvrir le fichier pour la lecture." << endl;
            return;
        }
        cout << "Contenu du fichier :" << endl;
        string ligne;
        while (getline(fichier, ligne)) {
            cout << ligne << endl;
        }
    }

    ~Fichier() {
        cout << "Fin de l'utilisation du fichier." << endl;
    }
};

int main() {
    Fichier fichier("test.txt");
    fichier.sauvegarder("Bonjour, ceci est un test.");
    fichier.charger();
    return 0;
}
