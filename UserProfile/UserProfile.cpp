#include "UserProfile.h"
#include <string>


void UserProfile::registerUser(const std::string& _username, const std::string& _fullName, const std::string& _email, const std::string& _password) {
    this->username = _username;
    this->fullName = _fullName;
    this->email = _email;
    this->password = _password;
    // Rest of your registration logic goes here, if any.
}

bool UserProfile::authenticateUser(const std::string &_username, const std::string _password) {
    // Check if the provided username and password match the stored values
    if (username == _username && password == _password) {
        // Authentication successful
        return true;
    } else {
        // Authentication failed
        return false;
    }
}

