#include <iostream>
#include "Account.h"

using namespace std;

int main() {
    cout << "\n===Account===================================" << endl;
    Account ac;
    ac.deposit(2000.0);
    ac.withdraw(1000);

    Account *p_acc;
    p_acc = new Account{};
    p_acc->deposit(1000);
    p_acc->withdraw(500);
    delete p_acc;



    return 0;
}
