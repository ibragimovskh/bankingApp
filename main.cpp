#include "Account.h"
#include <stdexcept>
#include "UserProfile/UserProfile.h"
#include <iostream>
#include <string>

int main() {
    // Create a UserProfile object
    UserProfile user;

    // Test 1: Register a user
user.registerUser(std::string("john_doe"), std::string("John Doe"), std::string("john@example.com"), std::string("password123"));
    std::cout << "Test 1: User registration successful." << std::endl;

    // Test 2: Authenticate the user (correct password)
    if (user.authenticateUser("john_doe", "password123")) {
        std::cout << "Test 2: User authentication successful." << std::endl;
    } else {
        std::cout << "Test 2: User authentication failed." << std::endl;
    }

    // Test 3: Authenticate the user (incorrect password)
    if (user.authenticateUser("john_doe", "wrong_password")) {
        std::cout << "Test 3: User authentication successful (incorrect password)." << std::endl;
    } else {
        std::cout << "Test 3: User authentication failed (incorrect password)." << std::endl;
    }

    // Test 4: Authenticate a non-existent user
    if (user.authenticateUser("nonexistent_user", "password123")) {
        std::cout << "Test 4: User authentication successful (non-existent user)." << std::endl;
    } else {
        std::cout << "Test 4: User authentication failed (non-existent user)." << std::endl;
    }

    return 0;
}
