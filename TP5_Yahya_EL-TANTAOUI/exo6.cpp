#include <iostream>
#include <regex>
#include <string>

bool contains_email(const std::string& text) {
    // Expression régulière pour détecter une adresse email basique
    std::regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    std::smatch match;
    
    if (std::regex_search(text, match, email_regex)) {
        std::cout << "Adresse email detectee : " << match.str() << std::endl;
        return true;
    }
    
    return false;
}

int main() {
    std::string phrase = "Mon email est user@example.com";
    if (!contains_email(phrase)) {
        std::cout << "Aucune adresse email detectee." << std::endl;
    }
    return 0;
}
