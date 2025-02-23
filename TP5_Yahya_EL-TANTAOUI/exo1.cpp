#include <iostream>
#include <algorithm>
#include <cctype>

// Fonction pour vérifier si une chaîne est un palindrome
bool is_palindrome( std::string& text) {
    std::string filtered_text;
    
    // Supprimer les espaces et mettre en minuscules
    for (char c : text) {
        if (!std::isspace(c)) {
            filtered_text += std::tolower(c);
        }
    }
    
    // Créer une version inversée de la chaîne filtrée
    std::string reversed_text = filtered_text;
    std::reverse(reversed_text.begin(), reversed_text.end());
    
    // Comparer les deux chaînes
    return filtered_text == reversed_text;
}

int main() {
    std::string input;
    std::cout << "Entrez un mot ou une phrase : ";
    std::getline(std::cin, input);
    
    if (is_palindrome(input)) {
        std::cout << '\"' << input << "\" est un palindrome." << std::endl;
    } else {
        std::cout << '\"' << input << "\" n'est pas un palindrome." << std::endl;
    }
    
    return 0;
}
