#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    /*
     * cout << std::boolalpha  makes the console display true or false for boolean expressions
     * cout << std::noboolalpha makes the console display 1 or 0 for boolean expressions
     */


    // Casting, can use static_cast<Desired_Type>(value), to tell the compiler to treat a number a certain way
    // can also use Java Casting, (double) int. but is old Style. Modern C++ tries to not use this


//    int total_amount{100};
//    int total_number{8};
//    double average{0.0};
//    average = total_amount /
//              total_number; // this is 100/8 => 12.5, but since the numbers are integers, the result is treated like an integer,
//    cout << average << endl; // 12
//
//    average = static_cast<double>(total_amount) / total_number;
//    std::cout << average << std::endl;// 12.5
//
//    cout << "==============================" << endl;
//
//    const int count{3};
//    int total{}, num1{}, num2{}, num3{};
//    average = 0;
//
//    cout << "Enter 3 integers separated by spaces" << endl;
//    cin >> num1 >> num2 >> num3;
//
//    total = (num1 + num2 + num3);
//
//    average = static_cast<double>(total) / count;
//
//    cout << "Numbers: " << num1 << " , " << num2 << " , " << num3 << endl;
//    cout << "Total: " << total << endl;
//    cout << "average: "<< average << endl;

    // Testing equality
    // == , !=

    bool result{false};
    int num11{}, num22{1};
    result = (100 == 50 + 50);
    result = (num11 != num22);

    cout << (num11 == num22) << endl; // 0 or 1
    cout << std::boolalpha; // makes the console display true or false for boolean expressions
    cout << true << endl;
    cout << (100 == 50) << endl;
    cout << std::noboolalpha; // makes the console display 1 or 0 for boolean expressions
    cout << (1 == 1);

    cout << "\n==============================" << endl << endl;

    // LOGICAL OPERATORS
    /*
     * NOT: you can use the symbol(!)   or the keyword not
     * AND: you can use the symbol(&&)  or the keyword and
     * OR:  you can use the symbol(||)  or the keyword or
     *
     * C++ makes Short-Circuit evaluation, which means that it will stop evaluating as soon as it knows the result
     * for example: A and B and C, if one is false then the entire expression is false.
     * A or B or C, if one is true then the entire expression is true
     */

    /* SECTION CHALLENGE*/

    cout << "SECTION CHALLENGE" << endl << endl;

    /*
     * 1 dollar    = 100 cents
     * 1 quarter   = 25 cents
     * 1 dime      = 10 cents
     * 1 nickel    = 5 cents
     * 1 penny     = 1 cents
     */
    const int dollar{100};
    const int quarter{25};
    const int dime{10};
    const int nickel{5};
    const int penny{1};
    int num_dollar{0};
    int num_quarter{0};
    int num_dime{0};
    int num_nickel{};
    int num_penny{};
    long number_of_cents{0};
    long cents{0};


    cout << "Enter an amount in cents:";
    cin >> number_of_cents;

    cents = number_of_cents;

    num_dollar = number_of_cents / dollar;
    number_of_cents -= dollar * num_dollar;

    num_quarter = number_of_cents / quarter;
    number_of_cents -= quarter * num_quarter;

    num_dime = number_of_cents / dime;
    number_of_cents -= num_dime * dime;

    num_nickel = number_of_cents / nickel;
    number_of_cents -= nickel * num_nickel;

    num_penny = number_of_cents / penny;
    number_of_cents -= penny * num_penny;

    cout << "Without using % modulo" << endl;
    cout << "You can provide change as follows: " << endl;
    cout << "Dollar: " << num_dollar << endl;
    cout << "Quarter: " << num_quarter << endl;
    cout << "Dime: " << num_dime << endl;
    cout << "Nickel: " << num_nickel << endl;
    cout << "Pennies: " << num_penny << endl;

    cout << "TOTAL: "
         << (dollar * num_dollar + quarter * num_quarter + dime * num_dime + nickel * num_nickel + penny * num_penny)
         << " , Left: " << number_of_cents << endl << endl;

    cout << "Using % modulo" << endl;

    num_dollar = num_quarter = num_dime = num_nickel = num_penny = 0;

    num_dollar = cents / dollar;
    cents %= dollar;

    num_quarter = cents / quarter;
    cents %= quarter;

    num_dime = cents / dime;
    cents %= dime;

    num_nickel = cents / nickel;
    cents %= nickel;

    num_penny = cents;

    cout << "You can provide change as follows: " << endl;
    cout << "Dollar: " << num_dollar << endl;
    cout << "Quarter: " << num_quarter << endl;
    cout << "Dime: " << num_dime << endl;
    cout << "Nickel: " << num_nickel << endl;
    cout << "Pennies: " << num_penny << endl;

    cout << "TOTAL: "
         << (dollar * num_dollar + quarter * num_quarter + dime * num_dime + nickel * num_nickel + penny * num_penny)
         << " , Left: " << (cents - num_penny) << endl << endl;


    return 0;
}
