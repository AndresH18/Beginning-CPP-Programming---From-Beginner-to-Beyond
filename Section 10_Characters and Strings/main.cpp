#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

int main() {

    /** C-style strings
     * #include <cctype>
     * function_name(char)
     * *functions for testing characters
     * *functions for converting character case
     * Implemented as an array of characters
     * Terminated by a null character (null - character with a value of zero)
     * "C++ is fun" => | C | + | + |   | i | s |   | f | u | n | \0 |
     *
     * strcpy (c_string_var, "new_String"); // assign a new value to a c-style string
     *
     *
     * #include <cstring>
     * Functions that work with c-style Strings
     * * Copying
     * * Concatenation
     * * Comparison
     * * Searching
     * * and others
     *
     * strcpy (charString[], "Hello"); // Copy
     * strcat (charString[], "there"); // concatenate
     * strlen (charString[]); // length
     * strcmp (charString[], "Another"); // compare strings
     *
     * #include <cstdlib>
     * Functions to convert c-style strings to:
     * integer, float, long, etc...
     */
    /**
    * Testing characters
    * isalpha (c)      |   true if c is a letter
    * isalnum (c)      |   true if c is a letter or digit
    * isdigit (c)      |   true if c is a digit
    * islower (c)      |   true if c is lowercase letter
    * isprint (c)      |   true if c is a printable character
    * ispunct (c)      |   true if c is a punctuation character
    * isupper (c)      |   true if c is an uppercase letter
    * isspace (c)      |   true if c is whitespace
    *
    * Converting characters
    * tolower (c)      |   returns lowercase of c
    * toupper (c)      |   returns uppercase of c
    */

    cout << "================== C - STYLE STRINGS ================== " << endl << endl;

    char first_name[20]{};
    char last_name[20]{};
    char full_name[50]{};
    char temp[50]{};

    cout << "first_name//if not initialized, then garbage value " << first_name << endl;

    cout << "Enter first name ";
    cin >> first_name;

    cout << "Enter last name ";
    cin >> last_name;

    cout << "Hello, " << first_name << endl;
    cout << "Your first name has " << strlen(first_name) << " Characters" << endl;

    strcpy_s(full_name, first_name);// strcpy was deprecated, this is the new version
    strcat_s(full_name, " ");
    strcat_s(full_name, last_name);

    cout << "This is your full Name? " << full_name << ". Y/N";
    char is_name{};
//    cin >> is_name;
    if (toupper(is_name) == 'Y') {
        cout << "Yes, I did it!!!!" << endl;
    } else {
        cout << "Damn, I don't know what happened." << endl;
    }

    cout << "\n\n-------------------------------------------------" << endl << endl;

    cout << "Enter your full name ";
//    cin.getline(full_name, 50);   // variable in which we want to store the console input,
    // and a limit of character to read.
    // This allows to take into account the spaces between words
    // std::getline(cin, variable);

    cout << "This is your full name: " << full_name << endl;

    cout << "\n\n================= C++ - STYLE STRINGS ================= " << endl << endl;
    /** std::string is a Class in the Standard Template Library
     * #include <string>
     * std namespace
     * contiguous in memory
     * dynamic size
     * work with input and output streams
     * lots of useful member functions
     * our familiar operator can be used (+, =, <, <=, >, >=, +=, ==, =!, [], ...)
     * can be easily converted to C-style string if needed
     * safer
     */

    string s1;                           // Empty
    string s2 {"Frank"};            // Frank
    string s3 {s2};                     // Frank , different locations in memory
    string s4 {"Frank", 3};  // Fra
    string s5 {s3, 0, 2};   // Fr
    string s6 (3, 'X');     // XXX

    s1 = "c++ Rocks!";
    s2 = s1;

    string part1 {"C++"};
    string part2 {"is a powerful"};

    string sentence;

    sentence = part1 + " " + part2 + " language"; // C++ is a powerful language

//    sentence = "C++" + " is powerful"; // ilegal, because this are c-style literals.
    // Combination of c-style and c++-style is OK


    // strings can be considered like vectors
    s1 = "";
    s2 = "Frank";

    cout << s2[0] << endl;
    cout << s2.at(0) << endl;

    s2[0] = 'f';        // frank
    s2.at(0) = 'p'; // prank

    // Comparing
    /**
     * ==   !=  >   >=  <   <=
     * The objects are compared character by character lexically
     * Can compare:
     * * two std::string objects
     * * std::string object and C-style string literal
     * * std::string object and C-style string variable
     *
     * string_object.substr(start_index, length); // returns the substring
     * string_object.find(search_string); // returns the index from which search_string starts
     * string_object.find(search_string, from_index);; // returns the index from which search_string start, but after(inclusive) from_index
     * If string_object.fin(search_string) doesn't find the string, then it returns std::npos
     *
     * string_object.erase(start_index, length); // removes what is inside this range
     * string_object.clear(); // empties the string
     * string_object.length(); // removes the number of characters inside the string
     *
     * string_object.swap(another_string); // swaps the values of the variables
     *
     *
     * cin >> string_object; // only accepts up to the first space
     *
     * getline(cin, string_object); // read entire line until \0, that is until pressed "enter"
     * getline(cin, string_object, 'X'); // 'X' is a delimiter. The character with which you want to stop accepting input, it is not included. A customized line breaker
     *
     *
     *
     */

    return 0;
}
