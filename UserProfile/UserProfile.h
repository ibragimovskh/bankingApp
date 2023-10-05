#ifndef USER_PROFILE
#define USER_PROFILE 

#include <string>

class UserProfile {
public:
    UserProfile() {};
    void registerUser(const std::string& _username, const std::string& _fullName, const std::string& _email, const std::string& _password);
    bool authenticateUser(const std::string &_username, const std::string _password);

private:
    std::string username;
    std::string fullName;
    std::string email;
    std::string password;
};

#endif
