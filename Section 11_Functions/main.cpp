#include <iostream>
#include <cmath>
#include <cstdlib> // required for rand()
#include <ctime>    // required for time()
#include <vector>

using namespace std;

double volume_cylinder(double height, double radius); // prototype with parameters names and types
double area_circle(double); // prototype with parameters type

double calc_cost(double base_cost, double tax_rate = 0.06, double shipping = 3.50);

void print_vector(const vector<int> &v);

void zero_vector_reference(std::vector<int> &v);

void one_vector_value(std::vector<int> v);


const double pi{3.14159};


void area_circle() {
    double radius{};
    cout << "Enter radius of circle: ";
//    cin >> radius;

    cout << "The area of the circle with radius " << radius << " is: " << area_circle(radius) << endl;
}

double area_circle(double radius) {
    return pi * pow(radius, 2);
}

void volume_cylinder() {
    double height{}, radius{};

    cout << "Enter the radius of the cylinder: ";
//    cin >> radius;
    cout << "Enter the height of the cylinder: ";
//    cin >> height;

    cout << "The volume of the cylinder of radius " << radius << " and height " << height << " is: "
         << (volume_cylinder(height, radius)) << endl;
}

double volume_cylinder(double height, double radius) { return height * area_circle(radius); }


int main() {

    double num{};

    cout << "Enter a double number: ";
//    cin >> num;

    cout << "The sqrt of " << num << " is: " << sqrt(num) << endl;
    cout << "The Cube root of " << num << " is: " << cbrt(num) << endl;

    cout << "----------------------------------------------------" << endl;

    cout << "The sine of " << num << " radians is: " << sin(num) << endl;
    cout << "The cosine of " << num << " radians is: " << cos(num) << endl;
    cout << "The tangent of " << num << " radians is: " << tan(num) << endl;

    cout << "----------------------------------------------------" << endl;

    cout << "The ceiling of " << num << " is: " << ceil(num) << endl;
    cout << "The floor of " << num << " is: " << floor(num) << endl;
    cout << "Rounding of " << num << " is: " << round(num) << endl;

    cout << "\n=====================================================" << endl << endl;

    int random_numbers{};
    size_t count{10};   // number of random numbers to generate
    int min{1};         // lower bound (inclusive)
    int max{6};         // upper bound (inclusive)

    // seed the random number generator
    // if you don't seed the generator, you will get the same sequence of random number every run
    cout << "RAND_MAX on my system is: " << RAND_MAX << endl;
    srand(time(nullptr));

    for (size_t i{0}; i < count; i++) {
        random_numbers = rand() % max + min; // generate random number [min, max]
        cout << random_numbers << "\t";
    }

    cout << "\n\n======================== FUNCTIONS =============================" << endl << endl;
    /** FUNCTIONS
     * functions need to be declare before (up) they are used.
     * The Compiler needs to know the functions before it is used.
     * To achieve this, we can use functions Prototypes, which let the compiler know
     * that there is a function named --- with arguments ---.
     * Function prototypes are generally placed after the #include 's
     *
     * function_type function_name (functions_parameters_with_names); // prototype with parameters names and types.
     * function_type functions_name (functions_parameters_only_type); // prototype with parameters types.
     *
     * function_type function_name (function_parameters) {
     *      statements;
     *      return <<functions_type>>;
     * }
     *
     * DEFAULT ARGUMENT VALUE
     * We can make functions in wich we can omit one value, therefore will use a default value that we decided
     *
     * function_type function_name (parameter_1, parameter_2 = default_value); // prototype
     * Here, if we dont pass a value to "parameter_2", then "parameter_2" uses "default_value".
     * The default value can be placed on the prototype or on the declaration, but not on both.
     * The Default values Must be the LAST ones of the parameters
     * WARNING: It is very similar to Method Overloading.
     */
    area_circle();
    volume_cylinder();


    cout << "No default Values" << calc_cost(100.0, 0.08, 4.25) << endl;
    cout << "Default Shipping" << calc_cost(100, 0.08) << endl;
    cout << "Default Tax and Shipping" << calc_cost(100) << endl;
    cout << "Can not use only Default Tax" << endl;

    /**
     * When we pass primitive data types or strings(both C and C++) on the parameters of a method, we are creating a copy of them.
     * Therefore if we alter them inside the method structure, they are not changed on outside the caller.
     * However, with arrays, we are actually passing the memory address of the array, and if we alter it inside the method, the change is visible outside the caller.
     * We can use the keyword "const" on the parameter so that you cannot modify the array inside the method.
     *
     * When we want to pass the reference on the parameter, we name the parameter using '&' symbol
     *
     * function_type function_name (parameter_type &parameter_name); // with this, when we pass data, we are passing the reference.
     * Therefore, if we alter it inside the method, we see the change outside the caller.
     * The '&' is not part of the name, so inside the method when we want to do something with the variable, we omit the '&'.
     * It can also be: function_type function_name (parameter_type & parameter_name);
     */

    vector <int> v {1, 2, 5, 3, 4, 6, 7, 8, 9};
    print_vector(v); // print by reference
    zero_vector_reference(v); // set to zeros by reference
    one_vector_value(v); // set to ones by value

    print_vector(v); // print by reference

    /** SCOPE
     * variables and data inside a method are only available while executing the block of code. When the block has finished executing,
     * the compiler can write over the memory that was allocated for the block of code.
     * Inner blocks can see variables outside of the block, but variables outside of the block cannot see variables inside the block.
     * We first se if the variable which we are referring is local to the innermost block that we are.
     *  If it's not from this block, we look to the next outer block until we find it.
     * {
     *      int num; // lets call it num1
     *      {
     *          int num; // lets call it num2
     *          cout << num; // here we are referring to num2
     *      }
     *      cout << num; // here we are referring to num1
     * }
     *
     * There is a type of variables whose lifetime is the entire program, therefore if the block has finished executing, they are not lost.
     * They are called static variables. They need to be initialized or they will be initialized to 0.
     * Their value doesn't change. They use the "static" keyword.
     *
     * static data_type var_name {var_value};
     *
     */

    /** INLINE FUNCTIONS
     * Sometimes, functions are so small or simple that simply allocating space in memory so that they execute seems overkill.
     * So we can ask the compiler to work with a function in the same memory space, or something like that.
     * Using the "inline" keyword on the method signature.
     *
     * inline int add_numbers(int a, int b) {
     *      return a + b;
     * }
     */

    return 0;
}

double calc_cost(double base_cost, double tax_rate, double shipping) {
    return base_cost += (base_cost * tax_rate) + shipping;
}

void print_vector(const vector<int> &v) {
    cout << "=================== PRINT VECTOR ===================" << endl;
    for (auto value : v) {
        cout << value << "\t";
    }
    cout << endl;
}

void zero_vector_reference(std::vector<int> &v) {
    cout << "=================== ZERO VECTOR REFERENCE ===================" << endl;
    cout << "ELEMENTS OF THE ORIGINAL WILL BE ALTERED." << endl;
    for (int i{0} ; i < v.size(); i++) {
        v.at(i) = 0;
    }
}

void one_vector_value(std::vector<int> v) {

    cout << "=================== ONE VECTOR VALUE ===================" << endl;
    cout << "ELEMENTS WILL BE COPIED AND THE ORIGINAL WILL NOT BE ALTERED." << endl;

    for (int i{0} ; i < v.size(); i++) {
        v.at(i) = 1;
    }

    /// Like with Java, this doesn't work. "Enhanced-for" - "Ranged-loop" is used to traversal of elements, NOT assignment.
//    for (auto value : v) {
//        value = 1;
//    }

    print_vector(v);
}






