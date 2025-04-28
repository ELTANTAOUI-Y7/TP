#include <iostream>
#include <string>
#include <memory>

class PaireBase {
public:
    virtual void Afficher() const = 0;
    virtual ~PaireBase() = default;
};

template<typename T, typename U>
class Paire : public PaireBase {
    T premier;
    U second;
public:
    Paire(const T& a, const U& b) : premier(a), second(b) {}

    void Afficher() const override {
        if constexpr (std::is_same<U, bool>::value)
            std::cout << premier << " " << (second ? "vrai" : "faux") << std::endl;
        else
            std::cout << premier << " " << second << std::endl;
    }
};

// Partial specialization for Paire<T, int>
template<typename T>
class Paire<T, int> : public PaireBase {
    T premier;
    int second;
public:
    Paire(const T& a, int b) : premier(a), second(b) {}

    void Afficher() const override {
        std::cout << "Le second paramètre est un int: " << second << std::endl;
    }
};