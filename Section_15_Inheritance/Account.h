//
// Created by andre on 13/8/2023.
//

#ifndef SECTION_15_INHERITANCE_ACCOUNT_H
#define SECTION_15_INHERITANCE_ACCOUNT_H


class Account {
protected:
    double amount{};
public:
    Account();

    ~Account();

    void withdraw(double amount);

    void deposit(double amount);

    double get_amount() const;

    void set_amount(double amount);
};


#endif //SECTION_15_INHERITANCE_ACCOUNT_H
