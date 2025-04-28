#include "exo4.hpp"

int main() {
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);

    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);

    auto m3 = m1.add(m2);
    std::cout << m3.get(0, 0) << " " << m3.get(0, 1) << std::endl; // 6 8
    std::cout << m3.get(1, 0) << " " << m3.get(1, 1) << std::endl; // 10 12

    // Matrix<int, 2, 3> m4;
    // m1.add(m4); // Erreur de compilation (static_assert)
    return 0;
}