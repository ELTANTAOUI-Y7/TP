#include <iostream>
#include <string>

std::string encode_rle(const std::string& text) {
    if (text.empty()) return ""; // Si la chaîne est vide, retourner une chaîne vide
    
    std::string encoded;
    char current_char = text[0];
    int count = 1;
    
    for (size_t i = 1; i < text.size(); ++i) {
        if (text[i] == current_char) {
            count++;
        } else {
            encoded += current_char;
            if (count > 1) encoded += std::to_string(count); // Ajouter le nombre de répétitions
            current_char = text[i];
            count = 1;
        }
    }
    
    // Ajouter le dernier groupe
    encoded += current_char;
    if (count > 1) encoded += std::to_string(count);
    
    return encoded;
}

int main() {
    std::string text = "aaabbccccddee";
    std::string encoded = encode_rle(text);
    std::cout << "Encodé : " << encoded << std::endl;
    return 0;
}
