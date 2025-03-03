#include <iostream>
using namespace std;

void alloc_tableau(int** &grille, int lignes, int colonnes) {
    grille = new int*[lignes];
    for (int i = 0; i < lignes; i++) {
        grille[i] = new int[colonnes];
    }
}

void remplir_tableau(int** &grille, int lignes, int colonnes) {
    int compteur = 1;
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            grille[i][j] = compteur++;
        }
    }
}

void afficher_tableau(int** &grille, int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            cout << grille[i][j] << " ";
        }
        cout << endl;
    }
}

void inverser_tableau(int** &grille, int lignes, int colonnes) {
    int** grille_temp = new int*[colonnes];
    for (int i = 0; i < colonnes; i++) {
        grille_temp[i] = new int[lignes];
        for (int j = 0; j < lignes; j++) {
            grille_temp[i][j] = grille[j][i];
        }
    }
    delete[] grille;
    grille = grille_temp;
}

int main() {
    int** tableau;
    int hauteur = 3;
    int largeur = 4;
    
    alloc_tableau(tableau, hauteur, largeur);
    remplir_tableau(tableau, hauteur, largeur);
    inverser_tableau(tableau, hauteur, largeur);
    afficher_tableau(tableau, largeur, hauteur);
    
    return 0;
}
