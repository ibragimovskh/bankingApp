#include <string> 
#include <vector> 

struct Transaction { 
    std::string type; 
    int amount; 
    std::string timestamp; 
};

class Account { 
    private: 
        std::string name; 
        int accountNumber; 
        float balance;
        // we need vector of transactions
        std::string getCurrentTimestamp() const;
        std::vector<Transaction> transactionHistory; 
        static int lastAccountNumber; 
    public: 
        Account(std::string name, float initialBalance); 
        void createAccount();
        void deposit(float amount); 
        void withdraw(float amount);
        float getBalance() { return balance; };  
        int getAccountNumber() {return accountNumber;};
        void printTransactionHistory() const; 
        void generateAccountStatement(const std::string &startDate, const std::string &endDate) const; 
};



