//
// Created by andre on 18/8/2023.
//

#include "illegal_balance_exception.h"

#include <string>

const char* IllegalBalanceException::what() const noexcept {
    return "Illegal balance exception";
}
