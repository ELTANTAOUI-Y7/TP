#include <iostream>
#include "exo1.hpp"

int main() {
    std::cout << maximum(5, 10) << std::endl; // Affiche 10
    std::cout << maximum(3.14, 2.71) << std::endl; // Affiche 3.14
    std::cout << maximum(std::string("chat"), std::string("chien")) << std::endl; // Affiche chien
    return 0;
}