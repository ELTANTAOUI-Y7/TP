#include <array>
#include <iostream>
#include <type_traits>

template<typename T, size_t M, size_t N>
class Matrix {
    std::array<std::array<T, N>, M> data;
public:
    void set(size_t i, size_t j, T val) { data[i][j] = val; }
    T get(size_t i, size_t j) const { return data[i][j]; }

    template<size_t M2, size_t N2>
    auto add(const Matrix<T, M2, N2>& other) const {
        static_assert(M == M2 && N == N2, "Dimensions incompatibles");
        Matrix<T, M, N> result;
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                result.set(i, j, get(i, j) + other.get(i, j));
        return result;
    }
};