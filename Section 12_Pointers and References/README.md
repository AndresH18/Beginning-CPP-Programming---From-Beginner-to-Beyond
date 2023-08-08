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
`int_ptr += n;` or `int_ptr = int_ptr + n`

(`-`)
  
> [!NOTE]
> Hello














