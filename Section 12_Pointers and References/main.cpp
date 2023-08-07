#include <iostream>
#include <vector>
#include <string>

using namespace std;

void double_data(int *int_ptr);

void swap(int *a, int *b);

void display(const vector<string> *const v);

void display(int *, int);

void display_array(int *, size_t &);

int *create_int_array(size_t, int = 0);

int main() {

    /** POINTERS
     * The dreaded time has come, we are now going to manage memory.
     *
     * * Is a variable whose value is an address.
     * * The address can contain another variable, a function.
     * * To use the data that the pointer is pointing, we must know it's type. That's why pointers have types.
     *
     * Why use Pointers?
     * * Inside functions, pointers can be used to access data that is defined outside the function.
     *      variables may not be in scope so you can't access them by name.
     * * Pointers can be used to operate on arrays very efficiently.
     * * We can allocate memory dynamically on the heap or free storage.
     * * * This memory doesn't even have a variable name.
     * * * The only way to get to it is via a pointer.
     * * With OOP, pointers are how polymorphism works.
     * * Can access specific addresses in memory.
     * * * useful in embedded and system applications.
     *
     * DECLARING POINTERS
     * Using the symbol '*' between the type and the name.
     * Can be put besides the type, in the space in between or by the name.
     * ALWAYS initialized the pointers, or they will have garbage data.
     * If the pointer is not going to be used yet, initialized it to "nullptr".
     * *
     * variable_type *pointer_name {nullptr}; // nullptr (since C++ 11) represents address zero. The pointer is "pointing nowhere"
     * *
     * int *int_pointer {nullptr};
     * *
     * double * double_pointer {nullptr};
     * *
     * string* string_pointer {nullptr};
     * *
     * ALL pointers, no matter the type or to what they point, always have the same size because the are a memory address.
     * Pointers are, internally, integers. The type is so the compiler knows what type is on that address.
     * The size of ANY pointer is 4 Bytes (sizeof pointer ==== 4)
     * pointer != what it points to
     *
     *
     * ADDRESS OPERATOR
     * To access the address of a variable, you use the '&' symbol before the variable name. Be advised that it is different from method signature.
     * *
     * int num {10}; // variable
     * std::cout << num ; // 10
     * std::cout << &num ; // 0x61ff1c    address
     * *
     *
     * The compiler will make sure that the address stored in a pointer is of the correct type;
     */

    int num{10};

    cout << "Value of num is: " << num << endl;
    cout << "sizeof of num is: " << sizeof num << endl;
    cout << "Address of num is: " << &num << endl;

    cout << "------------------------------------" << endl;

    int score{10};
    double high_temp{100.7};

    int *score_ptr{nullptr};
    score_ptr = &score; // OK
//    score_ptr = score; // COMPILER ERROR. pointer != int
//    score_ptr = &high_temp; // COMPILER ERROR
    cout << score_ptr << endl;

    int *p;

//    cout << "Value of p is: " << p << " garbage" << endl ; // 0x61ff63 - garbage
    cout << "address of p is: " << &p << endl; // 0x61ff63
    cout << "sizeof p is: " << sizeof p << endl; // 4 bytes (because is an int)

    p = nullptr; // set p to point nowhere
    cout << "Value of p is: " << p << endl; // 0

    cout << "------------------------------------" << endl;

    int *p1{nullptr};
    double *p2{nullptr};
    unsigned long long *p3{nullptr};
    vector<string> *p4{nullptr};
    string *p5{nullptr};

    cout << "The size of p1 is: " << sizeof p1 << endl;
    cout << "The size of p2 is: " << sizeof p2 << endl;
    cout << "The size of p3 is: " << sizeof p3 << endl;
    cout << "The size of p4 is: " << sizeof p4 << endl;
    cout << "The size of p5 is: " << sizeof p5 << endl;

    cout << "------------------------------------" << endl;

    score = 10;
    score_ptr = &score;
    cout << "Value of score is: " << score << endl;
    cout << "Address of score is:\t" << &score << endl;
    cout << "Value of score_ptr is:\t" << score_ptr << endl;

    /** ACCESS DATA FROM WHERE THE POINTER IS POINTING (DEREFERENCING A POINTER)
     *
     * If the pointer has a valid address, then we can access the data at the address
     * using the dereferencing operator '*'.
     *
     * By calling '*' followed by the name of the pointer, we can access the data on the address.
     * Using the name of the pointer means the address.
     * Using '*' followed by the name of the pointer means what is at that address.
     */
    cout << "------------------------------------" << endl;

    int test_score{100};
    int *test_score_ptr{&test_score};

    cout << *test_score_ptr << endl; // 100

    *score_ptr = 200;
    cout << *score_ptr << endl; // 200, getting data using the pointer
    cout << score << endl; // 200, getting data using the variable
    /// Since the pointer points to the same place as the variable, changing what is
    /// in the address through the pointer is reflected on the variable

    cout << "------------------------------------" << endl;

    double temperature{100.9};
    double *temperature_ptr{&temperature};

    double new_temperature{*temperature_ptr};

    cout << "Temperature:\t" << temperature << endl;
    cout << "Temperature_ptr:\t" << temperature_ptr << endl;
    cout << "New Temperature:\t" << new_temperature << endl;

    cout << "------------------------------------" << endl;

    /** DYNAMIC MEMORY
     *
     * ALLOCATING
     *
     * We allocate a space in memory so that we can use it later.
     * We use the keyword "new"
     * *
     * pointer_type pointer_name {nullptr};
     * pinter_name = new pointer_type;
     * *
     *
     * DEALLOCATING
     *
     * We use the keyword "delete" to tell the compiler that we don't
     * need the memory space anymore
     * *
     * int *int_ptr {nullptr};
     * int_ptr = new int;   // allocate an integer in the heap
     * ...
     * delete int_ptr;      // frees the allocated storage
     *
     * WARNING
     * If we loose the pointer (by reassigning it to somewhere else) then we cannot access the memory location again.
     * This is called a memory leak.
     */
    int *int_ptr{nullptr};
    int_ptr = new int; // allocate an integer on the heap
    cout << int_ptr << endl; // some Address
    cout << *int_ptr << endl; // Garbage value

    *int_ptr = 2506; // assign a value to the memory address
    cout << *int_ptr << endl;

    delete int_ptr; // Deallocating the integer from the heap

    cout << int_ptr << endl;

    cout << "------------------------------------" << endl;

    int *array_ptr{nullptr};
    int size{};

    cout << "How big do you want the array? ";
//    cin >> size;

    array_ptr = new int[size]; // Allocating an int array


    delete[] array_ptr; // deallocate the array array_ptr. You need to put the '[]' to refer to the array,
    // otherwise you will refer to the first position, and loose the location of the entire array

    cout << "------------------------------------" << endl;


    /** Arrays and Pointers
     *
     * * The value of an array name is the address of the first element in the array.
     * * The value of a pointer variable is an address.
     * * If the pointer points to the same data type as the array element then
     *      the pointer and the array name can be used interchangeably (almost).
     *
     * SUBSCRIPT AND OFFSET
     * *
     * int array_name[] {1, 2, 3, 4, 5};
     * int *pointer_name {array_name};
     *
     *     Subscript Notation       |      Offset Notation
     *
     *      array_name[index]       |       *(array_name + index)
     *      pointer_name[index]     |       *(pointer_name + index)
     *
     *
     * ++ AND --
     * (++) increments a pointer to point to the next array element
     *  * array_pointer++;
     * (--) decrements a pointer to point to the previous array element
     *  * array_pointer--;
     *
     * + AND -
     * (+) increment pointer by:  n * sizeof(type)
     *  * int_ptr += n; or int_ptr = int_ptr + n;
     * (-) decrement pointer by:  n * sizeof(type)
     *  * int_ptr -= n; or int_ptr = int_ptr - n;
     *
     * Subtracting pointer
     * Determine the number of elements between pointers if the are of the same type.
     *
     * Comparing pointers
     * p1 == p2
     * p1 != p2
     * It compares the address, NOT the value on the address.
     */

    int scores[]{192, 95, 8976};

    cout << scores << endl; // 0x61fec8     Address
    int *scores_ptr{scores};

    cout << "------------------------------------" << endl;

    cout << scores_ptr << endl;     // 0x61ff10     Address
    cout << *score_ptr << endl;     // 192
    cout << scores_ptr[2] << endl;  // 8976

    cout << "------------------------------------" << endl;

    cout << scores_ptr << endl;     // 0x61ff10     Address
    cout << scores_ptr + 1 << endl; // 0x61ff14     Address
    cout << scores_ptr + 2 << endl; // 0x61ff18     Address
    /// The address is changing by four because the size of an 1 int is 4 bytes

    cout << "------------------------------------" << endl;

    cout << *scores_ptr << endl;        // 192
    cout << *(scores_ptr + 1) << endl;  // 95
    cout << *(scores_ptr + 2) << endl;  // 8976


    cout << "------------------------------------" << endl;

    cout << "\n=================Pointer Arithmetic=================" << endl << endl;

    string s1{"Frank"};
    string s2{"Frank"};

    string *string_p1{&s1};
    string *string_p2{&s2};
    string *string_p3{&s1};

    // Determine if two pointers point to the same data
    // You must compare the referenced pointers
    // Remember that you can compare strings with "=="

    cout << (*string_p1 == *string_p2) << endl; /// true
    cout << (*string_p1 == *string_p3) << endl; /// true


    cout << "---------------------------------------" << endl;
    int scores2[]{100, 95, 89, 68, -1};
    scores_ptr = scores2;

    while (*scores_ptr != -1) {
        cout << *scores_ptr << endl;
        scores_ptr++;
    }
    cout << "---------------------------------------" << endl;
    scores_ptr = scores2;

    /// This is the same as the loop from before
    while (*scores_ptr != -1) {
        cout << *scores_ptr++ << endl; /// we get the value and then increment the pointer
    }

    cout << "================================" << endl;

    s1 = "Frank";
    s2 = "Frank";
    string s3{"James"};

    string_p1 = &s1;
    string_p2 = &s2;
    string_p3 = &s1;

    cout << boolalpha; // Show true | false
    cout << string_p1 << " == " << string_p2 << " : " << (string_p1 == string_p2) << endl; // false
    cout << string_p1 << " == " << string_p3 << " : " << (string_p1 == string_p3) << endl; // true

    cout << *string_p1 << " == " << *string_p2 << " : " << (*string_p1 == *string_p2) << endl; // true
    cout << *string_p1 << " == " << *string_p3 << " : " << (*string_p1 == *string_p3) << endl; // true

    string_p3 = &s3; // point to james
    cout << *string_p1 << " == " << *string_p3 << " : " << (*string_p1 == *string_p3) << endl; // false


    cout << "-----------------------------------------" << endl;

    char name[]{"Frank"}; // c-style string
    char *char_ptr1{nullptr};
    char *char_ptr2{nullptr};

    char_ptr1 = &name[0]; // 'F'
    char_ptr2 = &name[3]; // 'n'

    cout << "In the string " << name << ", " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1)
         << " characters away from " << *char_ptr1 << endl;

    cout << "\n\n===========================================" << endl << endl;
    /**
     * PASSING POINTERS TO A FUNCTION
     * "const" keyword and Pointers
     * There are several ways to qualify pointers using "const":
     *
     * * Pointers to constants
     * * Constant pointers
     * * Constant Pointers to constants
     *
     * POINTERS TO CONSTANTS
     * The data pointer to by the pointers is constant and CANNOT be changed.
     * The pointer itself can change and point somewhere else.
     * *
     *      int high_score {100};
     *      int low_score{65};
     *
     *      const int *score_ptr {&high_score};
     *
     *      *score_ptr = 86;        // ERROR
     *      score_ptr = &low_score; // OK
     *
     *
     * CONSTANT POINTERS
     * The data pointed to by the pointers can be changed.
     * The pointer itself CANNOT change(point somewhere else).
     * *
     *      int high_score {100};
     *      int low_score{65};
     *
     *      int *const score_ptr {&high_score};
     *
     *      *score_ptr = 86;        // OK
     *      score_ptr = &low_score; // ERROR
     *
     *
     * CONSTANT POINTERS TO CONSTANTS
     * The data pointed by the pointer is constant and CANNOT be changed.
     * The pointer itself CANNOT change(point somewhere else).
     * *
     *      int high_score {100};
     *      int low_score{65};
     *
     *      const int *const score_ptr {&high_score};
     *
     *      *score_ptr = 86;        // ERROR
     *      score_ptr = &low_score; // ERROR
     *
     */

    int value{10};
    int_ptr = nullptr;

    cout << "Value: " << value << endl;
    double_data(
            &value); // Pointers are an Address, So we can pass the address as a pointer to a function that receives a pointer
    cout << "Value: " << value << endl;

    cout << "------------------------------------------" << endl;

    int_ptr = &value;
    double_data(int_ptr);
    cout << "Value: " << value << endl;

    cout << "------------------------------------------" << endl;

    int x{100}, y{200};
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    swap(&x, &y);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;


    cout << "------------------------------------------" << endl;

    vector<string> stooges{"Larry", "Moe", "Curly"};
    display(&stooges);

    cout << "------------------------------------------" << endl;
    int scores3[]{100, 98, 67, 86, -1};
    display(scores3, -1);

    /** RETURNING POINTERS FROM A FUNCTION
     * *
     *      type *function();
     *
     *      int *largest_int(int *p1, int *p2) {
     *          if (*p1 > *p2) {
     *              return p1;
     *          else
     *              return p2;
     *      }
     *      main() {
     *          int a{100}, b{200};
     *          int *largest_ptr{nullptr};
     *          largest_ptr = largest_int(&, &b);
     *      }
     *
     * Should return pointers to:
     * * Memory dynamically allocated in the function.
     * * To data that was passed in.
     *
     * Never return a pointer to a local function variable.
     *
     * RETURNING DYNAMICALLY ALLOCATED MEMORY
     * *
     *      int *create_array(size_t size, int init_value = 0) {
     *
     *          int *new_storage{nullptr};
     *
     *          new_storage = new int[size];
     *          for (size_t i{0}; i < size; i++) {
     *              *(new_storage + i) = init_value;
     *          return new_storage;
     *      }
     *
     *      main() {
     *          int *my_array;  // will be allocated by the function
     *
     *          my_array = create_array(100, 20); // create the array
     *          . . .
     *          delete [] my_array; // be sure to free the storage
     *      }
     *
     *      DON'T DO THIS!!!!!!!!
     *
     *      int *dont_do_this() {
     *          int size{};
     *          . . .
     *          return &size;
     *      }
     *      // since 'size' was created inside the function, when the function terminates the memory that was allocated for it will be freed
     *      // so you will have no control over the address of size;
     *
     *      int *or_this() {
     *          int size{};
     *          int *int_ptr{&size};
     *          . . .
     *          return int_ptr;
     *      }
     *      // The pointer's memory is allocated inside the method, so when the method terminates, the memory of the pointer will
     *      // be freed and you will have no control.
     *
     *      /// Since the variables and pointers will be outside their lifetime, they could point to all sorts of others things
     *      /// This would (hopefully) crash the program, or would create bugs that are VERY HARD TO FIX
     *
     */

    /** POTENTIAL PITFALLS WITH POINTERS
     * * Uninitialized Pointers
     *
     *      int *ptr; // Pointing anywhere
     *      . . .
     *      ptr = 100; // Hopefully a crash
     *
     * * Dangling Pointers (Stray Pointers)
     *      Pointer that is pointing to released memory.
     *          For example, 2 pointers point to the same data.
     *          1 pointer released the data with delete.
     *          The other pointer accesses the released data
     *      Pointer that points to memory that is invalid
     *          Like when you return a pointer to a function local variable
     *
     * * Not checking if new failed to allocate memory
     *  If new fails an exception is thrown.
     *  We can use exception handling to catch the exceptions.
     *  Dereferencing a null pointer will cause the program to crash.
     *
     * * Leaking Memory
     *  Forgetting to release allocated memory with delete.
     *  If you lose your pointer to the storage allocated on the heap you have no way to get to the storage again.
     *  The memory is orphaned or leaked.
     *  One of most common pointer problems.
     *
     */

    int *my_array{nullptr};
    size_t my_size{};
    int initial_value{};

    cout << "\nHow many integers would you like to allocate? ";
//    cin >> my_size;
    cout << "What value would you like them initialized to? ";
//    cin >> initial_value;

    my_array = create_int_array(my_size, initial_value);

    cout << &my_size;
    display_array(my_array, my_size);

    delete[] my_array;

    cout << "\n\n========================================REFERENCES ========================================" << endl
         << endl;


    /** REFERENCES
     * 
     * A reference is an alias for a variable, so when using the reference we are using the variable it refers to.
     * They must ALWAYS be initialized to a variable when created, and they can't be null
     * Once initialized it cant change to a different variable.
     * They are often used in range-based (enhanced) for loops, to access collection elements
     *
     * NOT USING REFERENCES
     * *
     * for (auto str : some_string_vector) // Stores a copy on the variable str
     *      str = "Funny"; // alters the copy
     *
     * USING REFERENCES
     * *
     * for (auto &str : some_string_vector) // now str is an alias for those objects
     *      str = "Funny"; // we are modifying the original
     *
     * for (auto const &str : some_string_vector) // We are making so that we can not alter via the reference
     *      str = "Fun"; // compiler error
     *
     *
     */

    int number{100};
    int &ref{number};
    cout << number << endl;
    cout << ref << endl;
    cout << "--------" << endl;
    number = 200;
    cout << number << endl;
    cout << ref << endl;
    cout << "--------" << endl;
    ref = 300;
    cout << number << endl;
    cout << ref << endl;


    cout << "_________________________________" << endl;
    /// Using a reference to a pointer
    string password{"Hello"};
    string *password_ptr{&password};
    string *&m_pass{password_ptr};

    cout << "\n================================================" << endl << endl;

    /** L - R Values
     * L values:
     * Values that have names and are addressable.
     * Modifiable if they are not constants.
     * *
     * 100 = x;         // 100 is NOT an L value
     * (100 + 20) = x   // (100 + 20) is NOT an L value
     * string name;
     * name = "Frank";
     * "Frank" = name;  // "Frank" is NOT an L value
     *
     *
     * R Values:
     * A value that is not an L value.
     * On the right side of an assignment expression.
     * A literal.
     * A temporary which is intended to be non-modifiable
     * *
     * int x {100};                 // 100 is an R-value
     * int y = x + 200;             // (x + 200) is an R -value
     *
     * string name;
     * name = "Frank";              // "Frank" is an R value
     *
     * int max_num = max(20, 30);   // max(20, 30) is an R value
     *
     *
     * R Values can be assigned to L values explicitly
     * *
     * y = 100;     // R value 100 is assigned to L value y
     * x = x + y    // R value x + y is assigned to L value x
     *
     *
     * L Value References
     * The references we've used are L Value References
     * *
     * int x {100};
     * int &ref1 = x;   // ref1 is referenced to L Value
     * ref1 = 1000;
     *
     * int &ref2 = 100; // ERROR 100 is an R Value
     *
     * int square(int &n) {
     *  return n*n;
     * }
     * int num {10};
     * square(num);     // OK
     * square(5);       // ERROR - can't reference R Values
     */

    cout << noboolalpha; // show 0 | 1
//    system("pause");
    return 0;
}

/** (pass-by-reference)
 * Double the value stored at the location of the pointer.
 * @param int_ptr
 */
void double_data(int *int_ptr) {
    *int_ptr *= 2; // *int_ptr = *int_ptr * 2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(const vector<string> *const v) {
    for (auto s : *v) {
        cout << s << " ";
    }
    cout << endl;
//    (*v).at(0) = "Funny"; // ERROR
//    v = nullptr;          // ERROR
}

void display(int *array, int sentinel) {

    while (*array != sentinel) {
        cout << *array++ << " ";
    }
    cout << endl;
}

int *create_int_array(size_t size, int initial_value) {
    int *array{nullptr};
    array = new int[size];

    for (size_t i{0}; i < size; ++i) {
        array[i] = initial_value;
    }
    return array;
}

void display_array(int *array, size_t &size) {
    cout << " :: " << &size << endl;

    for (size_t i{0}; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

