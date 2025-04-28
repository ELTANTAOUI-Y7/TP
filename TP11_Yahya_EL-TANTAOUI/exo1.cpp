#include <iostream>

class DivideByZeroException : public std::exception {
    public:
    virtual const char* what() const noexcept {
       return "Error : Division by zero." ;
    }
};

class InvalidOperationException : public std::exception {
    public:
    virtual const char* what() const noexcept {
        return "Error : Invalid operation." ;
     }
};

double calculate(double number1, double number2, char operatorSymbol) {
    switch (operatorSymbol) {
        case '+':
            return number1 + number2;
        case '-':
            return number1 - number2;
        case '*':
            return number1 * number2;
        case '/':
            if (number2 == 0) throw DivideByZeroException();
            else return number1 / number2;
        default:
            throw InvalidOperationException();
    }
}

int main() {
    double firstNumber, secondNumber;
    char operationSymbol;

    std::cout << "Enter first number: ";
    std::cin >> firstNumber;

    std::cout << "Enter second number: ";
    std::cin >> secondNumber;

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operationSymbol;

    try {
        double result = calculate(firstNumber, secondNumber, operationSymbol);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const DivideByZeroException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (const InvalidOperationException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    std::cout << "Program completed" << std::endl;
    return 0;
}