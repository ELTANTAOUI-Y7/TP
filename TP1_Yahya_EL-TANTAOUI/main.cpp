#ifndef EXO
#define EXO 1
#endif

#if EXO==1 

#include <iostream>  // Inclusion de la bibliothèque standard pour l'affichage
int main() {
    // Affichage du message sur la console
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Bienvenue en C++!" << std::endl;
    
    return 0;  // Retourne 0 pour indiquer que le programme s'est bien exécuté
}



#elif EXO == 2

#include <iostream>  // Inclusion de la bibliothèque standard pour l'entrée/sortie

int main() {
    int nombre;  // Déclaration d'une variable pour stocker le nombre saisi par l'utilisateur

    // Demande à l'utilisateur d'entrer un nombre
    std::cout << "Entrez un nombre: ";
    std::cin >> nombre;  // Lecture de l'entrée utilisateur et stockage dans la variable 'nombre'

    // Affichage du nombre saisi
    std::cout << "Vous avez entre: " << nombre << std::endl;

    return 0;  // Indique que le programme s'est terminé avec succès
}


#elif EXO == 3

#include <iostream>  // Inclusion de la bibliothèque standard pour l'entrée/sortie

int main() {
    double nombre1, nombre2;  // Déclaration de deux variables pour stocker les nombres saisis

    // Demande à l'utilisateur d'entrer deux nombres
    std::cout << "Entrez deux nombres: ";
    std::cin >> nombre1 >> nombre2;  // Lecture des deux nombres

    // Calcul et affichage des résultats
    std::cout << "Somme: " << (nombre1 + nombre2) << std::endl;
    std::cout << "Difference: " << (nombre1 - nombre2) << std::endl;
    std::cout << "Produit: " << (nombre1 * nombre2) << std::endl;

    // Vérification pour éviter la division par zéro
    if (nombre2 != 0) {
        std::cout << "Quotient: " << (nombre1 / nombre2) << std::endl;
    } else {
        std::cout << "Erreur: Division par zéro impossible !" << std::endl;
    }

    return 0;  // Indique que le programme s'est terminé avec succès
}
#elif EXO == 4

#include <iostream>  // Inclusion de la bibliothèque pour l'entrée/sortie

int main() {
    std::cout << "Entrez un nombre: ";  // Ajout du guillemet fermant et correction de la syntaxe

    int nombre;  // Déclaration de la variable pour stocker l'entrée utilisateur
    std::cin >> nombre;  // Lecture du nombre saisi par l'utilisateur

    std::cout << "Vous avez entré: " << nombre << std::endl;  // Ajout du point-virgule manquant

    return 0;  // Indique que le programme s'est bien exécuté
}



#elif EXO == 5

#include <iostream>  // Inclusion de la bibliothèque standard pour l'entrée/sortie

int main() {
    double celsius, fahrenheit;  // Déclaration des variables pour stocker la température

    // Demande à l'utilisateur d'entrer une température en Celsius
    std::cout << "Entrez une temperature en Celsius: ";
    std::cin >> celsius;  // Lecture de la température entrée par l'utilisateur

    // Conversion en Fahrenheit selon la formule F = (9.0 / 5.0) * C + 32
    fahrenheit = (9.0 / 5.0) * celsius + 32;

    // Affichage du résultat
    std::cout << "Temperature en Fahrenheit: " << fahrenheit << std::endl;

    return 0;  // Indique que le programme s'est terminé avec succès
}


#else

#error "Veuillez définir EX0 à 1, 2, 3 ou 4 (exemple : -DEX0-1, -DEX0-2, etc.)"

#endif


