#include "Account.h"
#include <stdexcept>
#include <iostream>

int main() {
    // Create a CheckingAccount with an initial balance of $1000 and an overdraft limit of $500.
    CheckingAccount checking("Alice Smith", 1000.0, 500.0);

    // Test 1: Deposit $200
    checking.deposit(200.0);
    std::cout << "Test 1: Deposit $200." << std::endl;
    std::cout << "Current balance: $" << checking.getBalance() << std::endl;
    checking.printTransactionHistory();

    // Test 2: Withdraw $800 (within overdraft limit).
    try {
        checking.withdraw(800.0);
        std::cout << "\nTest 2: Withdraw $800 (within overdraft limit)." << std::endl;
        std::cout << "Current balance: $" << checking.getBalance() << std::endl;
        checking.printTransactionHistory();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 3: Withdraw $800 (exceeding overdraft limit)
    try {
        checking.withdraw(800.0);
        std::cout << "\nTest 3: Withdraw $800 (exceeding overdraft limit)." << std::endl;
        std::cout << "Current balance: $" << checking.getBalance() << std::endl;
        checking.printTransactionHistory();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
