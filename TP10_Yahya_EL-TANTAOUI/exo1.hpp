#include <string>

template<typename T>
T maximum(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template<>
std::string maximum<std::string>(const std::string& a, const std::string& b) {
    return (a.compare(b) > 0) ? a : b;
}