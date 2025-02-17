#include <iostream>
#include <limits>

// Définir EXO à 1 par défaut si non spécifié
#ifndef EXO
#define EXO 1
#endif

#if EXO == 1
void exercice1() {
    int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Taille totale du tableau : " << sizeof(tab) << " octet(s)\n";
    std::cout << "Taille d'un élément : " << sizeof(tab[0]) << " octet(s)\n";
    std::cout << "Nombre d'éléments : " << sizeof(tab) / sizeof(tab[0]) << "\n";
}
#elif EXO == 2
void exercice2() {
    const int prixPetitePiece = 250;
    const int prixGrandePiece = 350;
    const double taxeVente = 0.06;
    const int validite = 30;

    int nbPetites, nbGrandes;
    std::cout << "Nombre de petites pièces : ";
    std::cin >> nbPetites;
    std::cout << "Nombre de grandes pièces : ";
    std::cin >> nbGrandes;

    double cout = (nbPetites * prixPetitePiece) + (nbGrandes * prixGrandePiece);
    double taxe = cout * taxeVente;
    double total = cout + taxe;

    std::cout << "Cost : " << cout << "dh\n";
    std::cout << "Tax: " << taxe << "dh\n";
    std::cout << "===============================\n";
    std::cout << "Total estimate: " << total << "dh\n";
    std::cout << "This estimate is valid for " << validite << " days\n";
}
#elif EXO == 3
constexpr int factorielle(int n) {
    return (n <= 1) ? 1 : n * factorielle(n - 1);
}

void exercice3() {
    constexpr int fact5 = factorielle(5);
    static_assert(fact5 == 120, "Erreur de calcul de la factorielle");
    std::cout << "5! = " << fact5 << "\n";
}
#elif EXO == 4
int value = 100;

void exercice4() {
    int value = 50;
    std::cout << "Valeur locale : " << value << "\n";
    std::cout << "Valeur globale : " << ::value << "\n";
}
#elif EXO == 5
#define PI 3.14159

void exercice5() {
    const int moisAnnee = 12;
    constexpr double rayon = 7.0;
    double aire = PI * rayon * rayon;

    std::cout << "Nombre de mois dans une année : " << moisAnnee << "\n";
    std::cout << "Rayon du cercle : " << rayon << "\n";
    std::cout << "Aire du cercle : " << aire << "\n";
}
#elif EXO == 6
#include <limits>

int safeMultiply(int a, int b) {
    if (a > 0 && b > 0 && a > std::numeric_limits<int>::max() / b) {
        std::cout << "Erreur : Overflow détecté !\n";
        return -1;
    }
    return a * b;
}

void exercice6() {
    int a = 30000, b = 1000;
    std::cout << "Résultat : " << safeMultiply(a, b) << "\n";
    a = 300000; b = 10000;
    std::cout << "Résultat : " << safeMultiply(a, b) << "\n";
}
#endif

int main() {
#if EXO == 1
    exercice1();
#elif EXO == 2
    exercice2();
#elif EXO == 3
    exercice3();
#elif EXO == 4
    exercice4();
#elif EXO == 5
    exercice5();
#elif EXO == 6
    exercice6();
#endif
    return 0;
}
