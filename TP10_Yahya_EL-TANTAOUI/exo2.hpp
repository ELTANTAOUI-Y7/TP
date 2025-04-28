#include <vector>
#include <iostream>

template<typename T>
class Conteneur {
    std::vector<T> data;
    size_t capacite;
public:
    Conteneur(size_t cap) : capacite(cap) {}

    void ajouter(const T& val) {
        if (data.size() < capacite)
            data.push_back(val);
        else
            std::cerr << "Capacité dépassée\n";
    }

    T obtenir(size_t i) const {
        return data.at(i);
    }
};