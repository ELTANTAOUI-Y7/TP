#include <iostream>
#include <vector>
using namespace std;

class Etudiant {
public:
    string nom;
    vector<float> notes;

    Etudiant(string name, const vector<float>& grades) : nom{name}, notes{grades} {}

    float moyenne() const {
        if (notes.empty()) return 0; // Évite la division par zéro
        float moy = 0;
        for (const auto& note : notes) moy += note;
        return moy / notes.size();
    }

    ~Etudiant() {
        cout << "Nom : " << nom << endl << "Notes : ";
        for (const auto& note : notes) cout << note << " ";
        cout << endl << "Moyenne : " << moyenne() << endl;
    }
};

int main() {
    vector<float> grades{15, 18, 12};
    Etudiant karim("Karim", grades);
    return 0;
}
