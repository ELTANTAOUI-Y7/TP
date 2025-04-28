#include "exo3.hpp"
#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<PaireBase>> paires;
    paires.push_back(std::make_unique<Paire<double, int>>(3.14, 42));
    paires.push_back(std::make_unique<Paire<int, bool>>(0, true));
    paires.push_back(std::make_unique<Paire<std::string, double>>("Test", 2.71));

    for (const auto& p : paires)
        p->Afficher();
    return 0;
}