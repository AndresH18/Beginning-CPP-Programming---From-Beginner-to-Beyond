#include <iostream>
#include "savings_account.h"
#include "account.h"

using namespace std;

int main() {
    cout << "\n======Account===================================" << endl;
    Account ac;
    ac.deposit(2000.0);
    ac.withdraw(1000);

    Account *p_acc;
    p_acc = new Account{};
    p_acc->deposit(1000);
    p_acc->withdraw(500);

    Account ac2 {*p_acc};

    ac2.deposit(90);

    delete p_acc;

    Account ac3;
    ac3 = ac2;

    ac3.withdraw(1);

    SavingsAccount sa1{1, 100};

    SavingsAccount sa2 {SavingsAccount(1.2)};

    sa2.deposit(912);

    return 0;
}
