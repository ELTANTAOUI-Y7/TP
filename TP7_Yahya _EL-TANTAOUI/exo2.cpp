#include <iostream>
class Player {
private:
    std::string name;
    int score;

public:
    Player(std::string n, int s) {
        name=n;
        score=s;
    }

    void display() {
        std::cout << "Nom: " << name << std::endl;
        std::cout << "Score: " << score << std::endl;
    }
};

int main() {
    Player* player = new Player("Alice", 100);
    player->display();
    (*player).display();
    delete player;
    std::cout << "Objet dynamique supprime." << std::endl;
    return 0;
}