#include <iostream>
#include <climits>  // <climits> includes local machine information about integers
// <cfloat> includes local machine information about floating point numbers
#include <cfloat>

using namespace std;

int main() {
    /* naming conventions:
     * camelCase:
     * under_score:
     *
     * variable declaration:
     * int age;         // uninitialized
     * int age = 21;    // c-like initialization
     * int age (21);    // constructor initialization
     * int age {21};    // C++11 list initialization syntax, se recomienda usar este tipo de inicialización porque
     * de lo contrario se puede generar un overflow sin que nos demos cuenta, lo que haría que el dato de completamente diferente
     */

    /*
     * variable booleanas se llaman "bool" y verdadero(true) es 1, falso(false) es 0
     * se puede usar tanto el true como 1. Pero cuando se imprime es 1.
     * Eso es porque realmente no existe true o false, sino 1 o 0.
     */


    // calculate the area of a room
//    int room_width {0};
//    int room_length {0};
//    cout << "Enter width of the room: ";
//    cin >> room_width;
//
//    cout << "Enter length of the room: ";
//    cin >> room_length;
//
//    cout << "The area of the room is: " << (room_length * room_length);

//    cout << 1'222'333'2; // can use ' to make large numbers more distinguishable. Unlike Java (_)


    // Operator sizeof(type) returns the number of bytes that represent that type
    // with variable names, you can omit the parentesis
//    int my_variable {0};
//
//    cout << sizeof my_variable;


    cout << "sizeof information" << endl;
    cout << "===========================" << endl;

    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "short: " << sizeof(short) << " bytes" << endl;
    cout << "long: " << sizeof(long) << " bytes" << endl;
    cout << "long long: " << sizeof(long long) << " bytes" << endl;

    cout << "===========================" << endl;

    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "long double: " << sizeof(long double) << " bytes" << endl;

    cout << "===========================" << endl;

    // use values defined in <climits>

    cout << "Minimum values (INTEGER)" << endl;
    cout << "char: " << CHAR_MIN << endl;
    cout << "int: " << INT_MIN << endl;
    cout << "short: " << SHRT_MIN << endl;
    cout << "long: " << LONG_MIN << endl;
    cout << "long long: " << LLONG_MIN << endl;
    cout << "===========================" << endl;
    cout << "Maximum values (INTEGER)" << endl;
    cout << "char: " << CHAR_MAX << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "short: " << SHRT_MAX << endl;
    cout << "long: " << LONG_MAX << endl;
    cout << "long long: " << LLONG_MAX << endl;
    cout << "===========================" << endl;
    cout << "Minimum values (FLOAT)" << endl;
    cout << "float: " << FLT_MIN << endl;
    cout << "double: " << DBL_MIN << endl;
    cout << "long double: " << LDBL_MIN << endl;
    cout << "Maximum values (FLOAT)" << endl;
    cout << "float: " << FLT_MAX << endl;
    cout << "double: " << DBL_MAX << endl;
    cout << "long double: " << LDBL_MAX << endl;

    cout << "===========================" << endl;


    /* CONSTANTS
     *
     * Have names.
     * Occupy storage.
     * Are usually typed.
     * Their value does NOT change once declared.
     *
     * Types of constants:
     * Literal Constants
     * Declared Constants: "const" Keyword
     * Constant Expressions: "constexpr" Keyword
     * Enumerated Constants: "enum" Keyword
     * Defined Constants: "#define"
     */
    // Literal
//    int x = 3;
    // Declared
//    const double pi {3.1315926};
//    pi = 2; // Compile time error
    // Defined
    /* Its a preprocess that tells the compiler to substitute everywhere you see the name with the value */
// #define pi 3.1415926 don't Use defined constants in modern c++

// Exercise

//    cout << "==================================" << endl << endl << endl;
//    const float tax_rate{0.06}; // 6%
//    const int valid_days{30};
//    const double price_room{30.0};
//    cout << "Hello!!, Welcome to Carpet Cleaning Service!!" << endl;
//    cout << "\nHow many rooms would you like cleaned? ";
//
//    int number_of_rooms{0};
//    cin >> number_of_rooms;
//
//    cout << "\nEstimate for carpet cleaning service" << endl;
//    cout << "Number of rooms: " << number_of_rooms << endl;
//    cout << "Price per room: $" << price_room << endl;
//    cout << "Cost: $" << number_of_rooms * price_room << endl;
//    cout << "Tax: $" << price_room * number_of_rooms * tax_rate << endl;
//    cout << "==================================" << endl;
//    cout << "Total estimate $" << (price_room * number_of_rooms) + (price_room * number_of_rooms * tax_rate) << endl;
//    cout << "This estimate is valid for: " << valid_days << " Days." << endl;

    cout << "==================================" << endl << endl << endl;

    // Section Challenge
    const double small_price{25};
    const double large_price{35};
    const double tax_rate{0.06};
    int large_room_number;
    int small_room_number;
    cout << "Welcome to the Room Cleaning Service!!!" << endl;
    cout << "Small Room $ " << small_price << endl;
    cout << "Large Room $ " << large_price << endl;
    cout << "How many small rooms would you like cleaned? ";
    cin >> small_room_number;
    cout << "How many large rooms would you like cleaned? ";
    cin >> large_room_number;
    const double cost{large_room_number * large_price + small_room_number * small_price};
    const double tax{cost * tax_rate};
    const double total {cost + tax};
    cout << "Cost $" << cost << endl;
    cout << "Tax $" << tax << endl;
    cout << "==================================" << endl;
    cout << "Total estimate $" << total << endl;














//    system("pause"); // para que la command prompt no se cierre
    return 0;
}
