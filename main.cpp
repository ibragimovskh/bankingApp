#include <iostream>
#include "Account.h" // Include the header file for the Account class

int main() {
    // Create two accounts
    Account account1("John Doe", 1000.0);
    Account account2("Jane Smith", 2000.0);

    // Perform transactions on account1
    account1.deposit(500.0);
    account1.withdraw(200.0);

    // Perform transactions on account2
    account2.deposit(1000.0);
    account2.withdraw(300.0);

    // Print account1's transaction history
    account1.printTransactionHistory();

    // Print account2's transaction history
    account2.printTransactionHistory();

    return 0;
}
