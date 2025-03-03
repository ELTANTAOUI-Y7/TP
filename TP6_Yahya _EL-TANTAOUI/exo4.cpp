#include <iostream>
#include <memory>

using namespace std;

struct BlocMemoire {
    int taille;

    BlocMemoire(int t) : taille(t) {
        cout << "Bloc de mémoire alloué de " << taille << " unités." << endl;
    }

    ~BlocMemoire() {
        cout << "Bloc de mémoire de " << taille << " unités libéré." << endl;
    }
};

unique_ptr<BlocMemoire> fusionnerBlocs(unique_ptr<BlocMemoire> blocA, unique_ptr<BlocMemoire> blocB) {
    int nouvelleTaille = blocA->taille + blocB->taille;
    blocA.reset(); // Libérer le premier bloc
    blocB.reset(); // Libérer le second bloc
    return make_unique<BlocMemoire>(nouvelleTaille); // Retourner un nouveau bloc fusionné
}

int main() {
    unique_ptr<BlocMemoire> blocA = make_unique<BlocMemoire>(100);
    unique_ptr<BlocMemoire> blocB = make_unique<BlocMemoire>(200);

    unique_ptr<BlocMemoire> blocFusionne = fusionnerBlocs(move(blocA), move(blocB));
    cout << "Fusion des deux blocs : " << blocFusionne->taille << " unités." << endl;

    // La mémoire sera automatiquement libérée lorsque unique_ptr sortira du scope
    return 0;
}
