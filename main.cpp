#include "Account.h"
#include <stdexcept>
#include <string> 
#include <iostream> 
#include <ctime>
#include <chrono>
#include <thread>  // Include the <thread> header for sleep_for

int main() {
    // Create a SavingsAccount with an initial balance of $1000 and an interest rate of 5%.
    SavingsAccount savings("John Doe", 1000.0, 0.05);

    // Test 1: Wait for a short duration (e.g., 5 seconds) and then calculate interest.
    std::cout << "Test 1: Wait for a short duration and then calculate interest." << std::endl;

    // Wait for 5 seconds (adjust this duration for testing)
    std::this_thread::sleep_for(std::chrono::seconds(5));

    bool success1 = savings.calculateInterest();
    if (success1) {
        std::cout << "Interest calculated successfully." << std::endl;
        std::cout << "Current balance: $" << savings.getBalance() << std::endl;
    } else {
        std::cerr << "Interest calculation failed." << std::endl;
    }

    // Test 2: Calculate interest immediately after the first calculation (should fail).
    std::cout << "\nTest 2: Calculate interest immediately after the first calculation (should fail)." << std::endl;
    bool success2 = savings.calculateInterest();
    if (success2) {
        std::cout << "Interest calculated successfully." << std::endl;
        std::cout << "Current balance: $" << savings.getBalance() << std::endl;
    } else {
        std::cerr << "Interest calculation failed." << std::endl;
    }

    // Test 3: Wait for a short duration again and then calculate interest.
    std::cout << "\nTest 3: Wait for a short duration and then calculate interest again." << std::endl;

    // Wait for 5 seconds (adjust this duration for testing)
    std::this_thread::sleep_for(std::chrono::seconds(5));

    bool success3 = savings.calculateInterest();
    if (success3) {
        std::cout << "Interest calculated successfully." << std::endl;
        std::cout << "Current balance: $" << savings.getBalance() << std::endl;
    } else {
        std::cerr << "Interest calculation failed." << std::endl;
    }

    return 0;
}
