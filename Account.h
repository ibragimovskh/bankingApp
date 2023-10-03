#include <string> 
#include <stdexcept>


class Account { 
    private: 
        std::string name; 
        int accountNumber; 
        float balance;

        static int lastAccountNumber; 
    public: 
        Account(std::string name, int accountNumber, float initialBalance); 
        void createAccount();
        void deposit(float amount); 
        void withdraw(float amount);
        float getBalance() { return balance; };  
        int getAccountNumber() {return accountNumber;};
};

int Account::lastAccountNumber = 1000; 

Account::Account(std::string name, int accountNumber, float initialBalance) : name(name), balance(initialBalance) { 
    if(initialBalance < 0) { 
        throw std::invalid_argument("Initial balance cannot be negative");
    }
    accountNumber = ++lastAccountNumber;
};

void Account::deposit(float amount)  {
    if(amount < 0) { 
        throw std::invalid_argument("Deposit amount cannot be negative");
    }
};

void Account::withdraw(float amount) {
    if( balance >= amount ) { 
        balance -= amount; 
    }else { 
        throw std::invalid_argument("Insufficient funds");
    }     
};

