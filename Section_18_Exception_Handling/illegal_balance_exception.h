//
// Created by andre on 18/8/2023.
//

#ifndef SECTION_18_EXCEPTION_HANDLING_ILLEGAL_BALANCE_EXCEPTION_H
#define SECTION_18_EXCEPTION_HANDLING_ILLEGAL_BALANCE_EXCEPTION_H


#include <exception>

class IllegalBalanceException : public std::exception {

public:
    IllegalBalanceException() noexcept = default;

    ~IllegalBalanceException() override = default;

    const char* what() const noexcept override;


};


#endif //SECTION_18_EXCEPTION_HANDLING_ILLEGAL_BALANCE_EXCEPTION_H
