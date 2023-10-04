#include "Account.h"
#include <stdexcept>
#include <string> 
#include <iostream> 
#include <ctime>
#include <chrono>

int Account::lastAccountNumber = 1000; 

Account::Account(std::string name, float initialBalance) : name(name), initialBalance(initialBalance) ,currentBalance(initialBalance) { 
    if(initialBalance < 0) { 
        throw std::invalid_argument("Initial balance cannot be negative");
    }
    accountNumber = ++lastAccountNumber;
};

std::string Account::getCurrentTimestamp() const { 
    time_t currentTime;
    struct tm* timeInfo; 
    char buffer[80]; 

    time(&currentTime); 
    timeInfo = localtime(&currentTime); 

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    return std::string(buffer);
}


void Account::deposit(float amount)  {
    if(amount <= 0) { 
        throw std::invalid_argument("Deposit amount cannot be negative");
    }else { 
        currentBalance += amount;
    }
    Transaction transaction; 
    transaction.type = "Deposit"; 
    transaction.amount = amount;
    transaction.timestamp = getCurrentTimestamp();
    transactionHistory.push_back(transaction);
};

void Account::withdraw(float amount) {
    if( currentBalance >= amount ) { 
        currentBalance -= amount; 
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

void Account::generateAccountStatement(const std::string& startDate, const std::string& endDate) const {
    struct tm startTm, endTm;
    std::string format = "%Y-%m-%d %H:%M:%S";

    // startDate & endDate are parsed into the format above
    // If they're in the wrong format, an error is thrown
    if (strptime(startDate.c_str(), format.c_str(), &startTm) == nullptr ||
        strptime(endDate.c_str(), format.c_str(), &endTm) == nullptr) {
        std::cerr << "Invalid date format." << std::endl;
        return;
    }
    // mktime converts date into seconds since Unix epoch (1970)
    time_t startTime = mktime(&startTm);
    time_t endTime = mktime(&endTm);

    if (startTime == -1 || endTime == -1) {
        std::cerr << "Invalid date values." << std::endl;
        return;
    }
    // Initialize the balance at the start of the statement period
    float balanceAtStart = initialBalance;
    // Iterate through all transactions within the statement period
    for (const Transaction& transaction : transactionHistory) {
        struct tm transactionTm;
        // Checking if transaction->time is in the right format
        // If it is, save it to transactionTm
        if (strptime(transaction.timestamp.c_str(), format.c_str(), &transactionTm) == nullptr) {
            std::cerr << "Invalid transaction date format." << std::endl;
            continue;
        }
        // Converting to seconds
        time_t transactionTime = mktime(&transactionTm);
        // Check if the transaction date is within the specified range
        if (transactionTime >= startTime && transactionTime <= endTime) {
            std::cout << "Type: " << transaction.type << ", Amount: " << transaction.amount
                      << ", Timestamp: " << transaction.timestamp << std::endl;
        }

        // Update the balance for each transaction within the statement period
        if (transactionTime >= startTime && transactionTime <= endTime) {
            if (transaction.type == "Deposit") {
                balanceAtStart += transaction.amount;
            } else if (transaction.type == "Withdrawal") {
                balanceAtStart -= transaction.amount;
            }
        }
    }

    // Print the initial balance and balance at the end of the statement period
    std::cout << "Initial Balance: " << initialBalance << std::endl;
    std::cout << "Balance at the end of the statement period: " << balanceAtStart << std::endl;
}

// SAVINGS & CHECKINGS

SavingsAccount::SavingsAccount(std::string name, float initialBalance, float interestRate)
    : Account(name, initialBalance), interestRate(interestRate) {
    lastInterestCalculation = std::chrono::system_clock::now(); // Initialize the last calculation time
}

CheckingAccount::CheckingAccount(std::string name, float initialBalance, float overdraftLimit)
    : Account(name, initialBalance), overdraftLimit(overdraftLimit) {
}

bool SavingsAccount::calculateInterest() {
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
    std::chrono::duration<double> timeSinceLastCalculation = currentTime - lastInterestCalculation;

    // Debugging output
    std::cout << "Time since last calculation (seconds): " << timeSinceLastCalculation.count() << std::endl;
    // it is set to 86400 now, but for testing purposes you can change it to 2
    if (timeSinceLastCalculation.count() >= 24 * 60 * 60) {
        // Calculate the daily interest rate
        float dailyInterestRate = interestRate / 365.0;

        // Calculate the daily interest
        float dailyInterest = currentBalance * dailyInterestRate;

        // Add the daily interest to the current balance
        currentBalance += dailyInterest;

        // Update the last calculation time
        lastInterestCalculation = currentTime;

        // Interest calculation successful
        return true;
    } else {
        std::cerr << "Interest calculation failed. Too soon since the last calculation" << std::endl;
        return false;
    }
}
