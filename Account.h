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
    float initialBalance;
    std::string getCurrentTimestamp() const;
    std::vector<Transaction> transactionHistory;
    static int lastAccountNumber;

protected: 
    float currentBalance;


public:
    Account(std::string name, float initialBalance);
    void deposit(float amount);
    void withdraw(float amount);
    float getBalance() { return currentBalance; };
    int getAccountNumber() { return accountNumber; };
    void printTransactionHistory() const;
    void generateAccountStatement(const std::string &startDate, const std::string &endDate) const;
};

class SavingsAccount : public Account {
private:
    // chrono will help to determine whether enough time has passed since last calculation
    std::chrono::system_clock::time_point lastInterestCalculation;
    float interestRate;

public:
    SavingsAccount(std::string name, float initialBalance, float interestRate);
    bool calculateInterest();
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(std::string name, float initialBalance, float overdraftLimit);
    void applyOverdraft(float amount);
};
