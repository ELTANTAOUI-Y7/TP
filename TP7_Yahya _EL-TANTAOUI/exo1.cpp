#include <iostream>

class Joueur {

public:

    std::string nom;
    int score;
    Joueur(std::string n, int s) : nom(n), score(s) {}
    void afficher() {
        std::cout << "Joueur: " << nom << ", Score: " << score << std::endl;
    }
};

int main() {
    Joueur joueur1("Alice", 100);
    Joueur joueur2("Bob", 200);

    joueur1.afficher();
    joueur2.afficher();

    return 0;
}