#include <iostream>
#include "Account.h" // Include the header file for the Account class
int main() {
    // Create an Account object and add sample transactions to its transactionHistory
    Account myAccount("nm Doe", 1000.0); // Set an initial balance

    // Add transactions to the transactionHistory using the deposit and withdraw methods
    myAccount.deposit(300.0); // Another deposit
    myAccount.deposit(300.0); // Another deposit
    myAccount.withdraw(200.0); // Withdrawal
    myAccount.deposit(300.0); // Another deposit
    myAccount.withdraw(100.0); // Another withdrawal

    // Test: Generate a statement for the entire period from 2021 until 2023
    std::cout << "Generate a statement for the period from 2021 until 2023" << std::endl;
    myAccount.generateAccountStatement("2021-01-01 00:00:00", "2023-12-31 23:59:59");

    return 0;
}
