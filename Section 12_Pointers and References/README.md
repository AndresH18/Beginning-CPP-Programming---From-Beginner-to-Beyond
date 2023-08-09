# Pointers and References

## What is a Pointer

- A variable
    - Whose value is an address
- What can be store at the address
    - Another variable
    - A function
- Pointers point to variables or functions
- If x is an integer variable and its value is 10 then I can declare a pointer that points to it
- To use the data that the pointer is pointing to you must know its type.

### Why use pointers

Can't I just use the variable or function itself? **Yes, but not always**

- Inside functions, pointers can be used to access data that are defined outside of the function. Those variables may
  not be in scope so you cant access them by their name
- Pointers can be used to operate arrays efficiently
- we can allocate memory dynamically on the heap or free store
    - This memory doesn't even have a variable name
    - the only way to get it is via a pointer
- With Object-Oriented, pointers are how polymorphism works!
- Can access specific addresses in memory
    - useful in embedded and systems applications

## Declaring Pointers

`variable_type *pointer_name;` There is no difference between having the asterisk next to the name or type:

```c++
int *int_ptr;
double* double_ptr;
char *char_ptr;
string *string_ptr;
```

Like variables, if pointers are not initialized they will contain garbage data (that represents an
address). `variable_type *pointer_name {nullptr};`

```c++
int *int_ptr{};
double* double_ptr{nullptr};
char *char_ptr {nullptr};
string *string_ptr {nullptr};
```

Initializing pointer variables to 'point nowhere'

- Always initialize pointers
- Uninitialized pointers contain garbage data and can 'point anywhere'
- initializing to zero or `nullptr` (c++ 11) represents address zero
    - implies that the pointer is 'pointing nowhere'
- If you don't initialize a pointer to point to a variable or function then you should initialize it to `nullptr` to '
  make it null'

## Accessing Pointer Address

The address operator `&`

- Variables are stored in unique addresses
- Unary operator
- Evaluates to the address of its operand
    - Operand cannot be a constant or expression that evaluates to temp values

```c++
int num{10};
cout << "Value of num is: " << num << endl; // 10
cout << "sizeof of num is: " << sizeof num << endl; // 4
cout << "Address of num is: " << %num << endl; // 0x61ff4c
```

### Pointer addresses

```c++
int *p;
cout << "Value of p is: " << p << endl; // 0x61ff70 - garbage
cout << "Address of p is" << &p << endl; // 0x12ab32
cout << "size of p is: " << sizeof p << endl; // 4
p = nullptr; // set p to point nowhere
cout << "Value of p is: " << p << endl; // 0
```

`sizeof` a pointer variable

- Don't confuse the size of a pointer and the size of what it points to
- All pointers in a program have the same size
- They may be pointing to very large or small types

```c++
int *p1 {nullptr};
double *p2{nullptr};
unsigned long long *p3 {nullptr};
vectos<string> *p4 {nullptr};
string *p5{nullptr};
```

### Storing an Address in Pointer Variable

**Typed pointers** The compiler will make sure that the address stored in a pointer variables is of the correct type

```c++
int score {10};
double high_temp {100.7};

int *score_ptr {nullptr};
score_ptr = &score; // OK
score_ptr = &high_temp; // Compiler Error
```

- Pointers are variables so they can change
- Pointers can be null
- pointers can be uninitialized

```c++
double high_temp {100.7};
double low_temp {37.2};
double *temp_ptr;

temp_ptr = &high_temp; // points to high_temp
temp_ptr = &low_temp; // now points to low_temp

temp_ptr = nullptr; 
```

## Dereferencing a Pointer

Access the data we're pointing to - dereferencing a pointer.  
If score_ptr is a pointer and has a valid address then you can access the data at the address contained in the score_ptr
using the dereferencing operator `*`

```c++
int score {100};
int *score_ptr {&score};

cout << *score_ptr << endl; // 100

*score_ptr = 200;
cout << *score_ptr << endl; // 200
cout << score << endl; // 200
```

```c++
double high_temp {100.7};
double low_temp {37.4};
double *temp_ptr {&high_temp};

count << *temp_ptr << endl; // 100.7

temp_ptr = &low_temp;

cout << *temp_ptr << endl; // 37.4
```

```c++
string name {"Andres"};
string *string_ptr {&name};

cout << *string_ptr << endl; // Andres

name = "David"; 

cout << *string_ptr << endl; // David
```

## Dynamic Memory Allocation

Allocating storage from the heap at runtime

- We often don't know how much storage we need until we need it
- We can allocate storage to a variable at runtime
- Recall C++ arrays
    - We had to explicitly provide the size and it was fixed
    - But vectors grow and shrink dynamically
- We can use pointers to access newly allocated heap storage.

**Using `new` to allocate storage. `delete` to deallocate storage**

```c++
int *int_ptr {nullptr};
int_ptr = new int;          // allocate an integer on the heap
cout << int_ptr << endl;    // 0x2763f54
cout << *int_ptr << endl;   // 41199834 - garbage
*int_ptr = 100;
cout << *int_ptr << endl;   // 100

delete int_ptr;             // free the allocated memory
```

*** Using `new[]` to allocate storage for an array. `delete[]` to deallocate the storage of the array

```c++
int *array_ptr {nullptr};
int size{};
cout << "How big do you want the array?";
cin >> size;

array_ptr = new int[size]; // allocate array on the heap

delete[] array_ptr; // free allocated storage
```

## Arrays and Pointers

- The value of an array name is the address of the first element in the array
- The value of a pointer variable is an address
- If the pointer points to the same data type as the array element then the pointer and array name can be used
  interchangeably (almost).

```c++
int scores[] {100, 95, 89};
cout << scores << endl; // 0x35baf0
cout << *scores << endl; // 100

int *score_ptr {scores};

cout << score_ptr << endl; // 0x35baf0
cout << *score_ptr << endl; // 100
```

```cpp
int scores[] {100, 95, 89};

int *score_ptr {scores};

cout << score_ptr[0] << endl; // 100
cout << score_ptr[1] << endl; // 95
cout << score_ptr[2] << endl; // 89
```

**Using Pointers in expressions**

```cpp
int scores[] {100, 95, 89};

int *score_ptr {scores};

cout << score_ptr << endl; // 0x35baf0
cout << (score_ptr + 1) << endl; // 0x35baf4
cout << (score_ptr + 2) << endl; // 0x35baf8
```

By using `(score_ptr + 1)` we are adding 1 size of the pointer type. An int occupies 4 bytes, so by `(score_ptr + 1)` we
are moving 4 bytes forward. In the case of hte array, we are moving to the next item. This is called **Pointer
Arithmetic**.

### Equivalence Between Arrays and pointers

Pointers of arrays can be used as if they were arrays themselves. This allows using the `[]` operator on pointers to
access data of the array.

```c++
int array_name[] {1, 2, 3, 4, 5};
int *pinter_name {array_name};
```

|  Subscript Notation   |      Offset Notation      | 
|:---------------------:|:-------------------------:|
|  `array_name[index]`  |  `*(array_name + index)`  |
| `pointer_name[index]` | `*(pointer_name + index)` |

## Pointer Arithmetic

- Pointers can be used in
    - Assignment expressions
    - Arithmetic expressions
    - Comparison expressions
- c++ allows pointer arithmetic
- Pointer arithmetic only makes sense with raw arrays

### ++ and --

(`++`) increments a pointer to point to the next array element  
`ìnt_ptr++;`

(`--`) decrements a pointer to point to the previous array element  
`int_ptr--;`

### + and -

(`+`) increment pointer by `n * sizeof(type)`  
`int_ptr += n;` or `int_ptr = int_ptr + n;`

(`-`) decrement pointer by `n * sizeof(type)`  
`int_ptr -= n` or `int_ptr = int_ptr - n;`

### Subtracting two pointers

Determine the number of elements between pointers.  
**Both pointers must point to the same data type**

```c++
int n = int_ptr2 - int_ptr1;
```

### Comparing two pointers

Determine if two pointers point to the same location.  
Does NOT compare the data where they point.

```c++
string s1 {"Andres"};
string s2 {"Andres"};

string *p1 {&s1};
string *p2 {&s2};
string *p3 {&s1};

cout << (p1 == p2) << endl; // false
cout << (p1 == p3) << endl; // true

cout << (*p1 == *p2) << endl; // true
cout << (*p1 == *p3) << endl; // true
```

## Const and Pointers

`const` and pointers

There are several ways to qualify pointers using `const`

- [Pointers to constants](#pointers-to-constants)
- [Constant pointers](#constant-pointers)
- [Constan pointers to constants](#constant-pointers-to-constants)

### Pointers to Constants

The data pointed to by the pointers is constant and **cannot** be changed.  
The pointer itself can change and point somewhere else.

Its declare like `const variable_type *pointer_name`

```c++
int high_score {100};
int low_score {65};

const int *score_ptr {&high_score};

*score_ptr = 68; // ERROR
score_ptr = &low_score; // OK
```

The data cannot be change using the pointer.

### Constant Pointers

The data pointed to by the pointers can be changed.  
The pointer itself **cannot** change and point somewhere else.

Its declared like `variable_type *const pointer_name`

```c++
int high_score {100};
int low_score {65};

int *const score_ptr {&high_score};

*score_ptr = 86; // OK
score_ptr = &low_scorfe; // ERROR
```

The value at the memory address can change, but the pointer cannot point somewhere else.

### Constant Pointers to Constants

The data pointed to by the pointer is **constant** and cannot be changed.  
The pointer itself **cannot change** and point somewhere else

```c++
int high_score {100};
int low_score {65};

const int *const score_ptr {&high_score};

*score_ptr = 86; // ERROR
score_ptr = &low_scorfe; // ERROR
```

## Passing pointers to a function

Pass by reference with pointer parameters.  
We can use pointers and the dereference operator to achieve pass by reference.  
The function parameter is a pointer.  
The actual parameter can be a pointer or address of a variable.

```c++
void double_data(int *int_ptr);

void double_data(int *int_ptr) {
    *int_ptr *= 2;
}

int main() {
    int value {10};
    
    cout << value << endl; // 10
    
    double_data( &value ); 
    
    cout << value << endl; // 20
    
    int *int_ptr {&value};
    
    double_data(int_ptr);
    
    cout << value << endl; // 40
}
```

## Returning a pointer from a Function

Functions can also return pointers  
`type *function();`.

Should return pointers to:

- Memory dynamically allocated in the function
- To data that was passed in

**Never return a pointer to a local variable!**

```c++
int *largest_int(int *int_ptr1, int *int_ptr2) {
    if (*int_ptr1 > *int_ptr2)
        return int_ptr1;
    else 
        return int_ptr2;
}
```

Here, we returned pointers that were passed to the function so we know that the data exists and they are valid pointers.

```c++
int main() {
    int a{100};
    int b{200};
    
    int *largest_ptr = {nullptr};
    largest_ptr = largest_int(&a, &b);
    cout << *largest_ptr << endl; // 200
}
```

### Returning dynamically allocated memory

```c++
int *create_array(size_t size, int init_value = 0) {
    int *new_storage {nullptr};
    new_storage = new int[size];
    for (size_t i{0}; i < size; ++i) 
        *(new_storage + i) = init_value;
    return new_storage;
}

int main() {
    int *my_array;
    my_array = create_array(100, 20);
    // use my_array
    delete[] my_array; // be sure free the storage
}
```

### Never return a pointer to a local variable!!!

```c++
int *dont_do_this() {
    int size{};
    // . . . 
    return &size;
}
int *or_this() {
    int size{};
    int *int_ptr {&size};
    // . . . 
    return int_ptr;
}
```

## Potential Pitfalls with Pointers

### Uninitialized Pointers

```c++
int *ptr; // Pointing anywhere
// . . .
ptr = 100; // Hopefully a crash
```

### Dangling Pointers (Stray Pointers)

- Pointer that is pointing to released memory.  
  For example, 2 pointers point to the same data. One pointer released the data with delete. The other pointer
  accesses the released data.

- Pointer that points to memory that is invalid  
  Like when you return a pointer to a function's local variable.

### Not checking if new failed to allocate memory

If new fails an exception is thrown.  
We can use exception handling to catch the exceptions.  
Dereferencing a null pointer will cause the program to crash.

### Leaking Memory

Forgetting to release allocated memory with delete.  
If you lose your pointer to the storage allocated on the heap you
have no way to get to the storage again.  
The memory is orphaned or leaked.  
One of most common pointer problems.

## What is a Reference

- An alias for a variable
- Must be initialized to a variable when declared
- Cannot be null
- Once initialized cannot be made to refer to a different variable
- Very useful as function parameters
- Might be helpful to think of a reference as a constant pointer that is automatically dereference

**Using references in range-based for loop**

We can use references by using `&`. In range-based loops, we avoid the overhead of copying the collection-values to the
variable

```c++
vector<string> stooges {"Larry", "Moe", "Curly"};

for (auto str: stooges) // str is a COPY of each vector element
    str = "Funny";      // changes the copy

for (auto str: stooges)
    cout << str << endl;    // Larry, Moe, Curly

for (auto & str : stooges)  // str is a reference to each vector element
    str = "Funny";          // changes the actual

for (auto str: stooges)
    cout << str << endl;    // Funny, Funny, Funny
    
for (auto const & str : stooges) // cannot alter via the reference
    str = "Funny";          // compiler error
```

**Using references in code**

```c++
int number{100};
int &ref{number};
cout << number << endl; // 100
cout << ref << endl;    // 100

number = 200;
cout << number << endl; // 200
cout << ref << endl;    // 200

ref = 300;
cout << number << endl; // 300
cout << ref << endl;    // 300
```

## L-values and R-values

### L-values

Values that have names and are addressable.  
Modifiable if they are not constants.

```c++
int x {100};    // x is an l-value
x = 1000;
x = 1000 + 20;

string name;    // name is an l-value
name = "Andres";

100 = x;        // 100 is NOT an l-value
(100 + 20) = x; // (100 + 20) is not an l-value

"Andres" = name;// "Andres" is NOT an l-value
```

### R-values

Non-addressable and non-assignable.

A value that's not an l-value.  
On the right-hand side of an assignment expression  
A literal  
A temporary which is intended to be non-modifiable

```c++
int x{100};         // 100 is an r-value
int y = x + 200;    // (x+200) is an r-value

string name;
name = "Andres";    // "Andres" is an r-value
int max_num = max(20, 30); // max(20, 30) is an r-value 
```

R-Values can be assigned to L-Values explicitly

```c++
int x {100};
int y{0};

y = 100;    // r-value 100 is assigned to l-value y
x = x + y;  // r-value (x + y) is assigned to l-value x
```

### L-Values References

The references we've used are l-valued references, because we are referencing l-values.

```c++
int x {100};
int &ref1 = x;      // ref1 is reference to l-value
ref1 = 1000;

int &ref2 = 100;    // Error, 100 is an r-value
```

The same when we pass-by-reference

```c++
int square(int &n) { // pass-by-reference
    return n*n;
}
int num {10};
square(num);     // OK
square(5);       // Error, can't reference r-value 5
```

## Pointers vs References

### Pass by value

When the function does **not modify** the actual parameter and the parameter is *small and efficient to copy*, like
simple types (int, char, double, etc.). Strings, vectors, arrays, objects have some overhead involved when they are
copied.

### Pass by reference using a pointer

When the function does *modify the actual parameter*, and the parameter is *expensive to copy*, and it's *OK for the
pointer to contain a `nullptr` value*

#### Pass by reference using a [pointer to const](#pointers-to-constants)

When the function does *not modify the actual parameter*, and the parameter is *expensive to copy*, and it's *OK for the
pointer to contain a `nullptr` value*

#### Pass by reference using a [const pointer to const](#constant-pointers-to-constants)

When the function does *not modify the actual parameter*, and the parameter is *expensive to copy*, and it's *OK for
the pointer to contain a `nullptr` value*, and *you don't want to modify the pointer itself*.

### Pass by reference using a [reference](#what-is-a-reference)

When the function *does modify* the actual parameter, and the parameter is *expensive to copy*, and the parameter will
*NEVER be `nullptr`*.

#### Pass by reference using a `const` reference
When the function does *NOT modify* the actual parameter, and the parameter is *expensive to copy*, and the parameter will
*NEVER be `nullptr`*.