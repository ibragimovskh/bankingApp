#include "Account.h"
#include <stdexcept>
#include <string> 
#include <iostream> 
#include <ctime>

std::string Account::getCurrentTimestamp() const { 
    time_t currentTime;
    struct tm* timeInfo; 
    char buffer[80]; 

    time(&currentTime); 
    timeInfo = localtime(&currentTime); 

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    return std::string(buffer);
}

int Account::lastAccountNumber = 1000; 

Account::Account(std::string name, float initialBalance) : name(name), balance(initialBalance) { 
    if(initialBalance < 0) { 
        throw std::invalid_argument("Initial balance cannot be negative");
    }
    accountNumber = ++lastAccountNumber;
};

void Account::deposit(float amount)  {
    if(amount < 0) { 
        throw std::invalid_argument("Deposit amount cannot be negative");
    }

    Transaction transaction; 
    transaction.type = "Deposit"; 
    transaction.amount = amount;
    transaction.timestamp = getCurrentTimestamp();
    transactionHistory.push_back(transaction);
};

void Account::withdraw(float amount) {
    if( balance >= amount ) { 
        balance -= amount; 
    }else { 
        throw std::invalid_argument("Insufficient funds");
    }     

    Transaction transaction;
    transaction.type = "Withdrawal"; 
    transaction.amount = amount;
    transaction.timestamp = getCurrentTimestamp();
    transactionHistory.push_back(transaction);
};

void Account::printTransactionHistory() const {
    
    std::cout << "Transaction history for " << accountNumber << ": \n"; 
    
    // using const, so that we can't modify transactionHistory
    // & is used to avoid copying and inefficiency
    for(const Transaction& transaction : transactionHistory){ 
        std::cout << "Type: " << transaction.type << ", Account: " << transaction.amount << ", Date: " << transaction.timestamp << std::endl; 
    }

};