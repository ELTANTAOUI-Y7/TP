#include <iostream>

class NegativeQuantityException : public std::exception {
    public:
    virtual const char* what() const noexcept {
       return "Error : Negative Quantity." ;
    }
};
class InsufficientStockException : public std::exception {
    public:
    virtual const char* what() const noexcept {
       return "Error : Insufficient Stock." ;
    }
};

class Inventory {
    private:
        int currentStock;
    public:
        Inventory(int initialStock) : currentStock(initialStock) {
            if(initialStock < 0) throw NegativeQuantityException();
        }
        int getStock() {
            return currentStock;
        }
        void addItems(int quantity) {
            if (quantity < 0) throw NegativeQuantityException();
            currentStock += quantity;
        }
        void removeItems(int quantity) {
            if (quantity < 0) throw NegativeQuantityException();
            if (quantity > currentStock) throw InsufficientStockException();
            currentStock -= quantity;
        }
};

int main() {
    Inventory inventory(100); // Initial stock of 100 items
    std::cout << "Initial stock: " << inventory.getStock() << std::endl;

    try {
        inventory.addItems(50);
        std::cout << "After adding 50 items: " << inventory.getStock() << std::endl;
    }
    catch (const NegativeQuantityException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    try {
        inventory.removeItems(160); // Should throw InsufficientStockException
        std::cout << "After removing 160 items: " << inventory.getStock() << std::endl;
    }
    catch (const InsufficientStockException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    try {
        inventory.addItems(-10); // Should throw NegativeQuantityException
        std::cout << "After adding -10 items: " << inventory.getStock() << std::endl;
    }
    catch (const NegativeQuantityException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    std::cout << "Program completed" << std::endl;
    return 0;
}