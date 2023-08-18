//
// Created by andre on 18/8/2023.
//

#ifndef SECTION_18_EXCEPTION_HANDLING_ACCOUNT_H
#define SECTION_18_EXCEPTION_HANDLING_ACCOUNT_H


#include <string>

class Account {
private:
    std::string name;
    double balance;

public:
    Account(std::string name, double balance);
};


#endif //SECTION_18_EXCEPTION_HANDLING_ACCOUNT_H
