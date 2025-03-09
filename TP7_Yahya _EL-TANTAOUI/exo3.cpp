#include <iostream>
#include <string>

class Joueur {
private:
    std::string nom;
    int score;

public:
    // Constructeur
    Joueur( std::string n, int s)  {
        nom = n;
        score = s;
        std::cout << "Constructeur appele" << std::endl;
    }

    // Destructeur
    ~Joueur() {
        std::cout << "Destructeur appele" << std::endl;
    }

    // Méthode pour afficher les informations du joueur
    void afficher() const {
        std::cout << "Joueur: " << nom << ", Score: " << score << std::endl;
    }
};

int main() {
    Joueur joueur("Alice", 100);
    joueur.afficher();
    return 0;
}