#include <iostream>
#include <memory>

#include "account.h"
#include "illegal_balance_exception.h"

int main() {

    try {
        std::unique_ptr<Account> andres_account = std::make_unique<Account>("Andres", -1000);
        std::cout << "Use andres_account" << std::endl;
    } catch (const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
