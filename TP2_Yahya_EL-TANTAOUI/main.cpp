#include <iostream>  // Inclusion de la bibliothèque standard pour l'entrée/sortie

// Définition de la constante pour PI
#define PI 3.141592653589793

// Vérification si la macro DEBUG est définie
#ifdef DEBUG
#define DEBUG_MSG std::cout << "Mode Debug active !" << std::endl;
#else
#define DEBUG_MSG
#endif

// Sélection de l'exercice en fonction de la macro EXO
#ifndef EXO
#define EXO 1  // Par défaut, l'exercice 1 est compilé
#endif

#if EXO == 1
// Exercice 1 : Utilisation des directives du préprocesseur
int main() {
    DEBUG_MSG  // Affichage si DEBUG est activé
    std::cout << "Valeur de PI : " << PI << std::endl;
    return 0;
}

#elif EXO == 2
// Exercice 2 : Utilisation de la fonction main avec argc et argv
int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {  // Boucle à travers les arguments
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}

#elif EXO == 3
// Exercice 3 : Espaces de noms et portée des variables
namespace MonEspace {
    int maVariable = 10;  // Déclaration d'une variable dans un espace de noms
}

int main() {
    std::cout << "Valeur de maVariable Sans using namespace std : " << MonEspace::maVariable << std::endl;

    using namespace std;
    cout << "Valeur de maVariable Avec using namespace std  : " << MonEspace::maVariable << endl;
    return 0;
}

#elif EXO == 4
// Exercice 4 : Entrée et sortie avec cin et cout
int main() {
    int entier;
    double decimal;

    // Demande à l'utilisateur de saisir les valeurs
    std::cout << "Entrez un entier: ";
    std::cin >> entier;
    
    std::cout << "Entrez un nombre decimal: ";
    std::cin >> decimal;

    // Affichage des valeurs saisies
    std::cout << "Valeurs saisies: " << entier << " et " << decimal << std::endl;
    return 0;
}

#else
#error "Exercice non reconnu, définissez -DEXO=n avec n entre 1 et 4."
#endif
