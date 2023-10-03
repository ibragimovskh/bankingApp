#include <iostream>
#include "Account.h"

int main () { 
    Account myAcc("Shokhrukh", 12932, 300.25); 
    std::cout << myAcc.getBalance() << std::endl;
    myAcc.withdraw(300.10);
    std::cout << myAcc.getBalance() << std::endl;
    return 0;
}

// #TODO: Managing multiple accounts using <vector>