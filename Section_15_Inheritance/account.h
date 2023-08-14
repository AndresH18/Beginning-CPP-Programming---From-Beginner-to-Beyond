//
// Created by andre on 13/8/2023.
//

#ifndef SECTION_15_INHERITANCE_ACCOUNT_H
#define SECTION_15_INHERITANCE_ACCOUNT_H


class Account {
protected:
    double* p_balance;
    std::string s_name;
public:
    Account();

    Account(double amount);

    /**
     * Copy constructor for Account
     */
    Account(const Account& account);
    /**
     * Move constructor for Account
     */
    Account(Account&& account);

    ~Account();

    virtual void withdraw(double amount);

    virtual void deposit(double amount);

    double get_balance() const;

    void set_balance(double amount);


    /**
     * Copy assignment operator
     */
    Account &operator=(const Account& other);

    /**
     * Move assignment operator
     */
     Account &operator=(Account&& other);
};


#endif //SECTION_15_INHERITANCE_ACCOUNT_H
