#include <iostream>
#include <iomanip>
#include <vector>


using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout << "================== IF ==================" << endl << endl;
    int num{};
    int diff{};
    const int min{10};
    const int max{100};

    cout << "Enter a number between " << min << " and " << max << endl;
    cin >> num;

    if (num >= min) {
        cout << "========== IF STATEMENT 1 =========" << endl;
        cout << num << " is greater or equal than " << min << endl;

        diff = num - min;
        cout << num << " is " << diff << " greater than " << min << endl;
    }

    if (num <= max) {
        cout << "\n========== IF STATEMENT 2 =========" << endl;
        cout << num << " is less than or equal to " << max << endl;

        diff = max - num;
        cout << num << " is " << diff << " less than " << max << endl;
    }

    if (num >= min && num <= max) {
        cout << "\n========== IF STATEMENT 3 =========" << endl;
        cout << num << " is in the correct range" << endl;
        cout << "This means that IF 1 and IF 2 are also true" << endl;
    }

    if (num == min || num == max) {
        cout << "\n========== IF STATEMENT 4 =========" << endl;
        cout << num << " is right of a boundary" << endl;
    }

    cout << "\n\n================== IF-ELSE-IF ==================" << endl << endl;

    num = 0;
    const int target{10};

    cout << "Enter a number and I'll compare it to " << target << endl;
    cin >> num;

    if (num >= target) {
        cout << "\n=======================================================" << endl;
        cout << num << " is greater that or equal to " << target << endl;
        diff = num - target;
        cout << num << " is " << diff << " greater than " << target << endl;
    } else {
        cout << "\n=======================================================" << endl;
        cout << num << " is less than " << target << endl;
        diff = target - num;
        cout << num << " is " << diff << " less than " << target << endl;
    }

    cout << "\n\n================== NESTED IF ==================" << endl << endl;

    int score{};
    cout << "Enter your score on the exam (0-100) " << endl;
    cin >> score;
    char letter_grade{};

    if (score >= 0 && score <= 100) {
        if (score > 90)
            letter_grade = 'A';
        else if (score > 80)
            letter_grade = 'B';
        else if (score > 70)
            letter_grade = 'C';
        else if (score > 60)
            letter_grade = 'D';
        else
            letter_grade = 'F';

        cout << "Your grade will be: " << letter_grade << endl;

        if (letter_grade == 'F')
            cout << "Sorry, you failed" << endl;
        else
            cout << "You passed" << endl;
    } else {
        cout << "Sorry, the score you entered is not valid" << endl;
    }


    cout << "\n\n=======================================================" << endl << endl << endl;

    double width{}, height{}, length{};
    const int max_size{10};
    const int medium_size{100};
    const int large_size{500};
    const double base_cost{2.50};

    cout << "Welcome to the Shipping cost calculator" << endl;
    cout << "Please enter the dimensions of your package [length width height]" << endl;
    cin >> length >> width >> height;

    if (length >= max_size || width >= max_size || height >= max_size) {
        if (length < max_size) {
            cout << "The length is not valid, it must be greater or equal to " << max_size << endl;
        }
        if (width < max_size) {
            cout << "The width is not valid, it must be greater or equal to " << max_size << endl;
        }
        if (height < max_size) {
            cout << "The height is not valid, it must be greater or equal to " << max_size << endl;
        }
    } else {
        double volume{length * width * height};
        double sub_charge{};
        if (volume > large_size) {
            sub_charge = static_cast<double>(25) / 100;
        } else if (volume > medium_size) {
            sub_charge = 10.0 / 100;
        }
        cout << "The volume of the package is: " << volume << endl;
        cout << fixed << setprecision(2); // Prints dollar price nicely
        cout << "The sub charge due to the volume (" << volume << ") of the package is: " << sub_charge << endl;
        cout << "The cost of the package is: " << (base_cost * (1 + sub_charge)) << endl;
    }


    cout << "\n\n================== SWITCH-CASE ==================" << endl << endl;

    letter_grade = 'N';
    cout << "Enter the letter grade you expect on the exam: ";
    cin >> letter_grade;

    switch (letter_grade) {
        case 'a':
        case 'A':
            cout << "You need 90 or above" << endl;
            break;
        case 'b':
        case 'B':
            cout << "You need 80 - 89" << endl;
            break;
        case 'c':
        case 'C':
            cout << "You need 70 - 79" << endl;
            break;
        case 'd':
        case 'D':
            cout << "60 - 69" << endl;
            break;
        case 'f':
        case 'F': {
            char confirm{};
            cout << "Are you sure? (Y/N)";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                cout << "It seems you don want to study..." << endl;
            } else if (confirm == 'n' || confirm == 'N') {
                cout << "Good, go study" << endl;
            } else {
                cout << "Invalid Option" << endl;
            }

        }
            break;
        default :
            cout << "Default. Not valid Option" << endl;
            break;
    }

    enum Direction {
        left, right, up, down
    };

    Direction heading{right};


    switch (heading) {
        case left:
            cout << "Left" << endl;
            break;
        case right:
            cout << "Right" << endl;
            break;
        default:
            cout << "Catches everything that I didn't handle before"
                 << endl;
            break;
    }


    cout << "\n\n================== LOOPS ==================" << endl << endl;


    /** FOR - loop
    * for (initialization ; condition ; increment)
    *      statement;
    *
    * for (initialization ; condition ; increment) {
    *      statements;
    * }
    *
    * for (int i, j ; condition ; i++, j++) {statements};
    * for (;;) {endles loop}
    */

    /** RANGED-BASE FOR - loop
     * (enhance for loop, for-each loop)
     *
     * for (var_type var_name : sequence) {
     *     statements; // can use var_name
     * }
     *
     * Can also use the keyword "auto" instead of var_type.
     * This makes the compiler to figure it out by itself.
     * "auto" is the equivalent of Java's "var" keyword
     *
     *
     */

    std::vector<double> temperatures{87.2, 90.4, 77.4, 80.0, 72.5};

    double average_temp{};
    double running_sum{};

    for (auto temp : temperatures) {
        running_sum += temp;
    }
    average_temp = running_sum / temperatures.size();

    for (auto temp : {60.2, 50.0, 45.0, 89.9, 100.5}) {
        cout << temp << endl;
    }

    /** WHILE - loop
     * "pre-condition loop"
     *
     * while (expression)
     *      statement;
     *
     * while (expression) {
     *      statements;
     * }
     *
     */

    /** DO-While - loop
     * "post-condition loop"
     *
     * do {
     *      statements;
     * } while (expression/condition);
     *
     */


    int num_items{};

    cout << "How many data items do you have? ";
    cin >> num_items;

    std::vector<int> data{};

    for (int i{1}; i <= num_items; i++) {
        int data_item{};
        cout << "Enter data item " << i << ": ";
        cin >> data_item;
        data.push_back(data_item);
    }

    cout << "Displaying Histogram " << endl;
    for (auto val : data) {
        for (int i{0}; i < val; i++) {
            if (i % 5 != 0)
                cout << "-";
            else
                cout << "*";
        }
        cout << endl;
    }


    system("pause");


    return 0;
}
