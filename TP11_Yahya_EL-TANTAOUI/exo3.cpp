#include <iostream>
#include <vector>

class StackFullException : public std::exception {
    public:
    virtual const char* what() const noexcept {
       return "Error : The stack is full." ;
    }
};

class StackEmptyException : public std::exception {
    public:
    virtual const char* what() const noexcept {
       return "Error : The stack is empty." ;
    }
};

class Stack {
    private:
        std::vector<int> elements;
        int maxCapacity;
    public:
        Stack(int maxCapacity) : maxCapacity(maxCapacity) {}
        void push(int value) {
            if (maxCapacity == elements.size()) throw StackFullException(); 
            elements.push_back(value);
        }
        void pop() {
            if (elements.size() == 0) throw StackEmptyException();
            elements.pop_back();
        }
        int getSize() {
            return elements.size();
        }
};

void functionC() {
    std::cout << "Starting function C" << std::endl;
    throw StackFullException();
    std::cout << "Ending function C" << std::endl;
}
void functionB() {
    std::cout << "Starting function B" << std::endl;
    functionC();
    std::cout << "Ending function B" << std::endl;
}
void functionA(Stack stack) {
    std::cout << "Starting function A" << std::endl;
    functionB();
    std::cout << "Ending function A" << std::endl;
}

int main() {
    // Test 1: Demonstrate StackFullException via functionA
    try {
        Stack stack(2); // Stack with capacity of 2
        stack.push(1);
        stack.push(2);
        std::cout << "Stack size: " << stack.getSize() << std::endl;
        functionA(stack); // Will throw StackFullException
    }
    catch (const StackFullException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    // Test 2: Demonstrate StackEmptyException with pop
    try {
        Stack stack(2); // New empty stack
        std::cout << "Stack size: " << stack.getSize() << std::endl;
        stack.pop(); // Will throw StackEmptyException
    }
    catch (const StackEmptyException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    std::cout << "Program completed" << std::endl;
    return 0;
}