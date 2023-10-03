#include <iostream>
#include "Account.h" // Include the header file for the Account class

int main() {
    // Create an Account object and add sample transactions to its transactionHistory
    Account myAccount("John Doe", 1000.0); // Set an initial balance

    // Add transactions to the transactionHistory using the deposit and withdraw methods
    myAccount.deposit(500.0); // Initial deposit
    myAccount.deposit(300.0); // Additional deposit
    myAccount.withdraw(200.0); // Withdrawal
    myAccount.deposit(300.0); // Another deposit
    myAccount.withdraw(100.0); // Another withdrawal

    // Test 1: Generate a statement for the entire transaction history
    std::cout << "Test 1: Generate a statement for the entire transaction history" << std::endl;
    myAccount.generateAccountStatement("2021-01-01 00:00:00", "2023-10-03 23:59:59");

    // Test 2: Generate a statement for a specific range in 2022
    std::cout << "\nTest 2: Generate a statement for a specific range in 2022" << std::endl;
    myAccount.generateAccountStatement("2022-01-01 00:00:00", "2022-12-31 23:59:59");

    // Test 3: Generate a statement for a range that includes 2021 and 2022
    std::cout << "\nTest 3: Generate a statement for a range that includes 2021 and 2022" << std::endl;
    myAccount.generateAccountStatement("2021-11-01 00:00:00", "2022-04-30 23:59:59");

    return 0;
}
