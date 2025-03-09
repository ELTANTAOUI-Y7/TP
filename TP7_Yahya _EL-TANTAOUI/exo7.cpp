#include <iostream>
using namespace std;

class SharedPtr {
private:
    int* ptr;   // Pointeur vers l'objet
    int* count; // Pointeur vers le compteur de références

public:
    // Constructeur prenant un entier directement
    SharedPtr(int val) : ptr(new int(val)), count(new int(1)) {
        cout << "Création d'un SharedPtr vers " << val << endl;
        cout << "Nombre de références : " << *count << endl;
    }

    // Constructeur prenant un pointeur (évite une double allocation)
    explicit SharedPtr(int* p) : ptr(p), count(new int(1)) {
        cout << "Création d'un SharedPtr vers " << *p << endl;
        cout << "Nombre de références : " << *count << endl;
    }

    // Constructeur de copie
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), count(other.count) {
        (*count)++;  // Incrémentation du compteur de références
        cout << "Création d'une copie" << endl;
        cout << "Nombre de références : " << *count << endl;
    }

    // Opérateur d'affectation
    SharedPtr& operator=(const SharedPtr& other) {
        if (this == &other) return *this; // Évite l'auto-affectation

        // Décrémenter l'ancien pointeur
        (*count)--;
        if (*count == 0) {
            delete ptr;
            delete count;
            cout << "Objet supprimé." << endl;
        }

        // Copier les nouvelles références
        ptr = other.ptr;
        count = other.count;
        (*count)++;

        cout << "Assignation d'un SharedPtr" << endl;
        cout << "Nombre de références : " << *count << endl;
        return *this;
    }

    // Méthode pour accéder à la valeur stockée
    int get() const {
        return *ptr;
    }

    // Destructeur
    ~SharedPtr() {
        cout << "Destruction d'un SharedPtr" << endl;
        (*count)--;  // Décrémentation du compteur de références
        if (*count == 0) {
            delete ptr;
            delete count;
            cout << "Objet supprimé." << endl;
        } else {
            cout << "Nombre de références : " << *count << endl;
        }
    }
};

int main() {
    SharedPtr ptr1(10);     // Utilisation du constructeur avec un entier
    SharedPtr ptr2 = ptr1;  // Copie (compteur de références augmente)
    SharedPtr ptr3(20);
    ptr3 = ptr1;            // Assignation (ancien objet de ptr3 supprimé)

    cout << "Valeur de ptr1 : " << ptr1.get() << endl;

    return 0;
}

