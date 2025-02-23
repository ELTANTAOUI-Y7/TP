#include <iostream>
#include <sstream>
#include <map>
#include <string>

void sort_by_length(const std::string& text) {
    std::multimap<int, std::string> word_map;
    std::istringstream iss(text);
    std::string word;
    
    // Lire chaque mot et l'insérer dans la multimap avec sa longueur comme clé
    while (iss >> word) {
        word_map.insert({word.length(), word});
    }
    
    // Afficher les mots triés par longueur
    std::cout << "Trie par longueur : ";
    for (const auto& pair : word_map) {
        std::cout << pair.second << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string phrase = "Le langage C++ est rapide et efficace";
    sort_by_length(phrase);
    return 0;
}
