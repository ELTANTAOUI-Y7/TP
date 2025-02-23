#include <iostream>
#include <unordered_map>
#include <sstream>  // Pour std::istringstream
#include <string>

void word_frequency(const std::string& text) {
    std::unordered_map<std::string, int> freq;
    std::istringstream stream(text);
    std::string word;

    // Lecture mot par mot
    while (stream >> word) {
        freq[word]++;  // Incrémente la fréquence du mot
    }

    // Affichage des fréquences
    std::cout << "Frequence des mots :\n";
    for (const auto& pair : freq) {
        std::cout << pair.first << " -> " << pair.second << '\n';
    }
}

int main() {
    std::string text;
    
    // Demander à l'utilisateur d'entrer une phrase
    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, text);

    // Appel de la fonction
    word_frequency(text);

    return 0;
}



