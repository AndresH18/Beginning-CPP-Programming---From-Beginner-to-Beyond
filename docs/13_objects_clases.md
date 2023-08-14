# Classes and Objects

<!-- TOC -->
* [Classes and Objects](#classes-and-objects)
  * [Procedural Programming](#procedural-programming)
    * [Procedural Programming - Limitations](#procedural-programming---limitations)
  * [What is Object-Oriented Programming](#what-is-object-oriented-programming)
  * [Limitations](#limitations)
  * [Classes and objects](#classes-and-objects-1)
  * [Declaring Classes and Creating Objects](#declaring-classes-and-creating-objects)
    * [Declaring a class](#declaring-a-class)
    * [Creating Objects](#creating-objects)
  * [Accessing Class Members](#accessing-class-members)
  * [Access Modifiers](#access-modifiers)
  * [Implementing Member Methods](#implementing-member-methods)
    * [Inside class Declaration](#inside-class-declaration)
    * [Outside the class declaration](#outside-the-class-declaration)
    * [Separating Specification from Implementation](#separating-specification-from-implementation)
      * [Specification](#specification)
        * [Include-Guards](#include-guards)
      * [Implementation](#implementation)
    * [Using Classes with separated declaration and implementation](#using-classes-with-separated-declaration-and-implementation)
  * [Constructors and Destructors](#constructors-and-destructors)
    * [Constructors](#constructors)
    * [Destructors](#destructors)
    * [Creating Objects](#creating-objects-1)
  * [Default Constructor](#default-constructor)
    * [No Default constructor](#no-default-constructor)
  * [Overloading Constructors](#overloading-constructors)
  * [Constructor Initialization Lists](#constructor-initialization-lists)
  * [Delegating Constructors](#delegating-constructors)
  * [Constructor Parameters and Default Values](#constructor-parameters-and-default-values)
    * [Default constructor parameters](#default-constructor-parameters)
  * [Copy Constructor](#copy-constructor)
    * [Best practices](#best-practices)
    * [Declaring the Copy constructor](#declaring-the-copy-constructor)
    * [Implementing the Copy Constructor](#implementing-the-copy-constructor)
  * [Shallow vs Deep Copying](#shallow-vs-deep-copying)
    * [Shallow Copying](#shallow-copying)
    * [Deep Copying](#deep-copying)
  * [Move Constructor](#move-constructor)
    * [R-Value References](#r-value-references)
    * [L-Value Reference Parameters](#l-value-reference-parameters)
    * [R-Value Reference Parameters](#r-value-reference-parameters)
    * [L-Value and R-Value Reference Parameters](#l-value-and-r-value-reference-parameters)
    * [Declaring the Move Constructor](#declaring-the-move-constructor)
  * [This pointer](#this-pointer)
    * [Determine Object Identity](#determine-object-identity)
  * [Using `const` with Classes](#using-const-with-classes)
  * [Static Class Members](#static-class-members)
  * [Struct vs Classes](#struct-vs-classes)
    * [Some General Guidelines](#some-general-guidelines)
  * [Friends of a Class](#friends-of-a-class)
    * [Non-Member function](#non-member-function)
    * [Member function of Another Class](#member-function-of-another-class)
    * [Another Class as a Friend](#another-class-as-a-friend)
<!-- TOC -->

**Object-Oriented Programming - Classes and Objects**

- What is Object-Oriented Programming
- What are classes and Objects
- Declaring classes and creating objects
- Dot and pointer operators
- `public` and `private` access modifiers
- Methods, Constructors and Destructors
    - `class` methods
    - Default and overloaded constructors
    - Copy and move constructors
    - [Shallow](#shallow-copying) vs [deep](#deep-copying) copying
    - `this` pointer
- `static` class members
- `struct` vs `class`
- `friend` of a class

## Procedural Programming

- Focus is on processes or actions that a program takes
- Programs are typically a collection of functions
- Data is declares separately
- Data is passed as arguments into functions
- Fairly easy to learn

### Procedural Programming - Limitations

Functions need to know the structure of the data. If the structure of the data changes, many functions must be changed.

As programs get larger they become more:

- Difficult to understand
- Difficult to maintain
- Difficult to extend
- Difficult to debug
- Difficult to reuse code
- Fragile and easier to break

## What is Object-Oriented Programming

Classes and Objects:

- Focus is on classes that model real-world domain entities
- Allows developers to think at a higher level of abstraction
- Used successfully in very large programs

Encapsulation:

- Object contains data **AND** operations that work on that data
- Abstract Data Type (ADT)

Information-hiding:

- Implementation-specific logic can be hidden
- Users of the class code to the interface since they don't need to know the implementation
- More abstraction
- Easier to test, debug, maintain and extend

Re-Usability:

- Easier to reuse classes in other applications
- Faster development
- Higher quality

Inheritance:

- Can create new classes in terms of existing classes
- Reusability
- Polymorphic classes

## Limitations

Not a panacea:

- OOP won't make bad code better
- Not suitable for all types of problems
- Not everything decomposes to a class

Learning Curve:

- Usually a steeper learning curve, especially for c++
- Many OO languages, many variations of OO concepts

Design:

- Usually more up-front design is necessary to create good models and hierarchies

Programs can be:

- Larger in size
- Slower
- More complex

## Classes and objects

Classes:

- Blueprint from which objects are created
- A user defined data type
- Has attributes (data)
- Has methods (functions)
- Can hide data and methods
- provides a public interface

Example classes:

- Account
- Employee
- Image
- std::vector
- std::string

Objects:

- Created from a class
- Represents a specific instance of a class
- Can create many, many objects
- Each has its own identity
- Each can use the defined class methods

## Declaring Classes and Creating Objects

### Declaring a class

```c++
class ClassName {
    // declarations(s);
};
```

**Player**

```c++
class Player {
    // attributes
    std::string name;
    int health;
    int xp;
    // methods
    void talk(std::string text_to_say);
    bool is_dead();
};
```

**Account**

```c++
class Account {
    // attributes
    std::string name;
    double balance;
    // methods
    bool withdraw(double amount);
    bool deposit(double amount);
};
```

### Creating Objects

```c++
Player andres; // default constructor
Player hero; // default constructor

Player* enemy = new Player();
delete enemy;
```

```c++
Account andres_account;

Account* david_account = new Account();
delete david_account;

Account accounts[] {andres_account, *david_account};
std::vector<Account> vector_accounts {andres_account};
vector_accounts.push_back(*david_account);
```

## Accessing Class Members

We can access:

- class attributes
- class methods

If we have an **object**, using the *dot* operator

```c++
Account andres_account;
andres_account.balance;
andres_account.deposit(1000.0);
```

If we have a **pointer** to an object

- Dereference the pointer, then use dot operator
  ```cpp
  (*david_account).balance;
  (*david_account).deposit(50.0);
  ```
- Or use the member of pointer operator
  ```c++
  david_account->balance;
  david_account->deposit(150.0);
  ```

## Access Modifiers

Specify who can access the data and methods.

By default, all fields and methods inside a class are private.

- `public`: accessible everywhere
- `private`: accessible only by members or *friends* of the class
- `protected`: used with inheritance

```c++
class ClassName {
    public:
    // declarations(s);
};
```

Everything declared after the access modifier will have that access modifier applied to it.

> [!WARNING]
> Trying to access a field or a method outside of it's modifier scope will result in a Compiler Error

## Implementing Member Methods

- Very similar to how functions are implemented
- Member methods have access to member attributes, so there's no need to pass them as arguments
- Cam be implemented inside the class declaration.
- Can be implemented outside the class declaration. Need to use `Class_name::method_name`
- Can separate specification from implementation:
    - `.h` file for the class declaration
    - `.cpp` file for the class implementation

### Inside class Declaration

```c++
class Account {
    private:
        double balance;
    public:
        void set_balance(double newBalance) {
            balance = newBalance;
        }
        double get_balance() {
            return balance;
        }
};
```

### Outside the class declaration

```c++
class Account {
    private:
        double balance;
    public:
        void set_balance(double newBalance);
        double get_balance();
};

void Account::set_balance(double newBalance) {
    balance = newBalance;
}
double Account::get_balance() {
    return balance;
}
```

### Separating Specification from Implementation

#### Specification

Account.h

```c++
class Account {
    private:
        double balance;
    public:
        void set_balance(double newBalance);
        double get_balance();
};
```

##### Include-Guards

A series of pre-processor directives that guarantees the file will only be included once.

```c++
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

// Account class declaration
class Account {
    private:
        double balance;
    public:
        void set_balance(double newBalance);
        double get_balance();
};
#endif
```

`#ifndef _ACCOUNT_H_`: checks if the pre-processor has a symbol called `_ACCOUNT_H_`, if its not define executes the
section inside.
`#define _ACCOUNT_H_`: adds to the pre-processor the symbol `_ACCOUNT_H`, Should be specific for header file. Can be
anything, but usually is some combination of the file name, in uppercase, with preceding and ending underscores.  
`#endif`: ends the if section

Some compilers support the `#pragma once` directive. It works the same as the Include-Guards.

```c++
#pragma once
class Account {
    // . . .
};
```

#### Implementation

Account.cpp

```c++
#include "Account.h"

void Account::set_balance(double newBalance) {
    balance = newBalance;
}
double Account::get_balance() {
    return balance;
}
```

> [!NOTE]
> `#include <>` is used to include *system* header files, which the compiler knows where they are.
> `#include "*.h"` is used to include header files *local to the project*.

### Using Classes with separated declaration and implementation

main.cpp, *or somewhere else*

```c++
#include <iostream>
#include "Account.h"

int main() {
    Account andres_account;
    andres_account.set_balance(1000.00);
    double balance = andres_account.get_balance();
    
    std::cout << bal << << std:endl; // 1000
}
```

## Constructors and Destructors

### Constructors

- Special member method
- Invoked during object creation
- Useful for initialization
- Same name as the class
- *No return type* specified
- Can be overloaded

```c++
class Player {
    private: 
        std::string name;
        int health;
        int xp;
    public:
        // overloaded constructors
        Player();
        Player(std::string name);
        Player(std::string name, int health, int xp);
};
```

### Destructors

- Special member method
- same name as the class, preceded with `~`
- Invoked automatically when the object is destroyed
- *No return type* and **no parameters**
- Only 1 destructor is allowed per class *- cannot be overloaded!*
- Useful to release memory and other resources

```cpp
class Player {
    // . . . 
    public:
        // . . .
        ~Player();
};
```

### Creating Objects

```c++
{
    Player slayer; // empty constructor called
    Player andres {"Andres", 100, 4}; // overloaded constructor called (3 parameters)
    Player hero {"Hero"}; // overloaded constructor called (1 parameter)
    
    Player* villain = new Player("Villain", 1000, 0); // overloaded constructor called (3 parameters). Object is in the heap
    delete villain; // destructor called
}
```

## Default Constructor

Does not expect any arguments. Also called no-args constructor.  
If you write no constructors at all for a class, the C++ compiler will generate a _Default Constructor_ that does
nothing.  
Called when you instantiate a new object with no arguments.

```c++
Player andres;
Player* villain = new Player;
```

**Account - using default constructor**

```c++
class Account {
    private:
        std::string name;
        double balance;
    public:
        bool withdraw(double amount);
        bool deposit(double amount);
};
```

**Using the default constructor**

```c++
Account andres_account;
Account* david_account = new Account;
delete david_account;
```

Since the class members are not initialized, they could contain garbage data.

**User Defined no-args constructor**
We can also define the no-args constructor.

```c++
class Account {
    private:
        std::string name;
        double balance;
    public:
        Account() {
            name = "no name";
            balamce = 0;
        }
        bool withdraw(double amount);
        bool deposit(double amount);
};
```

### No Default constructor

If we declare a no-args constructor, C++ will not create a Default *no-args* constructor anymore. If we still need the
no-args, then we will have to declare it ourselves,

```c++
class Account {
    private:
        std::string name;
        double balance;
    public:
        Account(std:string name_val, double bal) {
            name = name_val;
            balamce = bal;
        }
        bool withdraw(double amount);
        bool deposit(double amount);
};
```

> [!WARNING]
> If we try to use a constructor that doesn't exist, there will be a Compiler Error

## Overloading Constructors

Classes can have as many constructors as necessary. Each must have a unique signature.
The [Default Constructor](#default-constructor) is no longer compiler-generated once a constructor is declared.

```c++
class Player {
    private: 
        std::string name;
        int health;
        int xp;
    public:
        // overloaded constructors
        Player();
        Player(std::string name);
        Player(std::string name, int health_val, int xp_val);
};
```

**Implementing the constructors**

```c++
Player::Player() {
    name = "";
    health = 0;
    xp = 0;
}
Player::Player(std::string name_val) {
    name = name_val;
    health = 0;
    xp = 0;
}
Player::Player(std::string name_val, int health_val, int xp_val) {
    name = name_val;
    health = health_val;
    xp = xp_val;
}
```

## Constructor Initialization Lists

So far, all data member values have been set in the constructor body.

Constructo initialization lists

- Are more efficient
- Initialization list immediately follows the parameter list
- Initialized the data member as the object is created. Normal constructor will create the value and then assign them
  inside the constructor
- Order of initialization is the order of declaration in the class

Previous way

```c++
Player::Player() {
    name = "None"; // assignment, not initialization
    health = 0;
    xp = 0;
}
```

**Better way**

```c++
Player::Player() : name{"None"}, health{100}, xp{0} // This happens before the constructor is ever executed
{} 
```

This order in which the members are initialized is not necessarily the order we provide in the initialization list. The
data members will be initialized in the order that they were declared in the class declaration

```c++
// Previous way
Player::Player(std::string name_val) {
name = name_val;
health = 100;
xp = 0;
}
// Better way
Player::Player(std::string name_val) : name {
name_val
}, health{
100
}, xp{
0
} {
}
```

```c++
// Previous way
Player::Player(std::string name_val, int health_val, int xp_val) {
name = name_val;
health = healt_val;
xp = xp_val;
}
// Better way
Player::Player(std::string name_val, int health_val, int xp_val)
: name {
name_val
}, health{
health_val
}, xp{
xp_val
} {
}
```

## Delegating Constructors

Often the code for constructors is very similar. Duplicated code can lead to errors.

C++ allows delegating constructors. Code for one constructor can call another in the initialization list. Avoids
duplicating code.

```c++
class Player {
    private: 
        std::string name;
        int health;
        int xp;
    public:
        // overloaded constructors
        Player();
        Player(std::string name);
        Player(std::string name, int health_val, int xp_val);
};

Player::Player(std::string name_val; int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {}

Player::Player(std::string name_val) : Player {name_val, 0, 0} {}

Player::Player() : Player {"None", 0, 0}{}
```

## Constructor Parameters and Default Values

### Default constructor parameters

Can often simplify our code and reduce the number of overloaded constructors.  
Same rules apply as with non-member functions.

```c++
class Player {
    private: 
        std::string name;
        int health;
        int xp;
    public:
        Player(std::string name = "None", int health_val = 0, int xp_val = 0);
};
Player::Player(std::string name_val; int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {}
```

// The default values of the constructor prototype are supplied to the constructor implementation.

> [!IMPORTANT]
> Be careful to not create ambiguous constructors

## Copy Constructor

When objects are copied, C++ must create a new object from an existing one.  
When is a copy of an object made?

- Passing object by *value* as a parameter
  ```c++
  Player hero {"Hero", 100, 20};
  
  void display_player(Player p) {
    // p is a COPY of hero
    // use p
    // Destructor for p will be called
  }
  
  diplsay_player(hero);
  ```
- Returning an object from a function by *value*
  ```c++
  Player enemy;
  
  Player create_super_enemy() {
    Player an_enemy{"Super Enemy", 1000, 1000};
    return an_enemy; // A COPY of an_enemy is returned 
  }
  
  enemy = create_super_enemy();
  ```
- Constructing an object based on another of the same class
  ```c++
  Player hero {"Hero", 100, 100};
  Player another_hero {hero}; // A COPY of hero is made
  ```

C++ Must have a way of accomplishing this, so it provides a compiler-defined copy constructor if you don't.

**Copy Constructor**
If you don't provide you own way of copying objects by value then the compiler provides a default way of copying
objects.  
Copies the value of each data member to the new object, *default member-wise copy*.  
Perfectly fine in many cases.

> [!WARNING]
> Beware if you have a pointer data member: Pointer will be copied, **NOT** what it is pointing to.

### Best practices

- Provide a copy constructor when your class has raw pointer members
- Provide the copy constructor with a `const reference` parameter
- Use STL (Standard Template Library) classes as they already provide copy constructors
- Avoid using raw pointer data members if possible, or use [Smart Pointers](#smart-pointers)

### Declaring the Copy constructor

This is the syntax for declaring a copy constructor: `Type::Type(const Type &source);`.  
We must use `&` to pass the object by reference to the copy constructor, *otherwise why are we doing this*.  
Using `const` is intended to prevent modifying the source.

Examples

```c++
Player::Player(const Player &source);

Account::Account(const Account &source)
```

### Implementing the Copy Constructor

```c++
Type::Type(const Type &source) {
    // code or initialization list to copy the object
}
```

*Player*

```c++
Player::Player(const Player &source) : name{source.name}, health {soure.health}, xp {source.xp}
```

*Account*

```c++
Account::Account(const Account &source) : name {source.name}, balance {source.balance}
```

> [!NOTE]
> We can also use a delegating constructor `Type::Type(const Type &source) : Type {...}`.

## Shallow vs Deep Copying

Consider a class that contains a pointer as a data member.  
Constructor allocates storage dynamically and initializes the pointer.  
Destructor releases the memory allocated by the constructor.  
What happens in the default copy constructor?

### Shallow Copying

- Member-wise copy of all the object attributes
- Each data member is copied from the source object
- The pointer is copied, **NOT** what it points to

> [!WARNING]
> When we release the storage in the constructor, the other object still refers to the released storage!

### Deep Copying

Create a COPY of the pointed to data. Each *copy* will have a pointer to unique storage in the heap.

> [!NOTE]
> When you have raw pointers, use Deep Copy

```c++
class Deep {
    private:
        int *data;      // pointer
    public:
        Deep(int d);    // constructor    
        Deep(const Deep &source); // copy constructor
        ~Deep();        // destructor
};

Deep::Deep(int d) {
    data = new int; // allocate storage
    *data = d;      // set value in storage
}
~Deep::Deep() {
    delete data;    // free storage
}

Deep::Deep(const Deep &source) {
    data = new storage;     // allocate storage
    *data = *source.data;   // store copy content of source data
}
// other way
// Deep:Deep(const Deep &source) : Deep{*source.data} {}
```

When one object is deleted, its memory is freed. But there is *NO* problem because each object had it's own copy of the
data

## Move Constructor

Sometimes when we execute code, the compiler creates unnamed temporary values.

```c++
int total {0};
total = 100 + 200;
```

Here, `100 + 200` is evaluated into `300` and is stored as an *unnamed temp value*. Then, `300` is stored in `total`.
Finally, the *temp value* is discarded.  
This also happens with objects.

In the context of move semantics [R-Values](#r-values) also refer to temporary objects, and objects returned from
methods.

> [!NOTE]
> A rule of thump is that if you can refer to an object by name, or you can follow a pointer to get to an object, then
> that object is addressable, and it's an [**L-Value**](#l-values). [**R-Values**](#r-values) are everything else

Sometimes [copy constructors](#copy-constructor) are called many times automatically due to the copy semantics of C++.
Copy constructors doing deep copying can have a significant performance bottleneck.  
`C++11` introduced move semantics and the **move constructor**. Move constructor moves an object rather than copy it.

> [!NOTE]
> Copy elision - `C++` may optimize copying away completely (RVO - Return Value Optimization)

> [!IMPORTANT]
> It is optional, but *recommended** to use [Move Constructors](#move-constructor) when using raw pointers.

### R-Value References

Used in moving semantics and perfect forwarding.  
Move semantics is all about r-value references.  
Used by move constructor and move assignment operator to efficiently move an object rather than copy it.

**R-Value reference operator(`&&`)**

> [!NOTE]
> [L Value References](#l-values-references) are declared using a single
> ampersand (`&`). [R Value References](#r-value-references) are declared using 2(`&&`).

```c++
int x {100};
int& l_ref = x;     // l-value reference
l_ref = 10;         // change x to 10

int&& r_ref = 200;  // r-value ref
r_ref = 300;        // change r_ref to 300

int&& x_ref = x;    // COMPILER ERROR
```

### L-Value Reference Parameters

```c++
int x {100};    // x is an l-value

void func(int& num); // num is l-value reference

func(x);        // call function - x is an l-value
func(200);      // Error - 200 is an r-value
```

> Error: cannot bind non-const lvalue reference of type 'int&' to a rvalue of type 'int'

### R-Value Reference Parameters

```c++
int x {100};    // x is an l-value

void func(int&& num); // num is an r-value reference

func(200);      // calls function - 200 is an r-value
func(x);        // Error - x is an l-value
```

> error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'

### L-Value and R-Value Reference Parameters

```c++
int x {100};    // x is an l-value

void func(int& num); // num is l-value reference
void func(int&& num); // num is an r-value reference

func(x);        // call function - x is an l-value
func(200);      // calls function - 200 is an r-value
```

Instead of making a deep copy, the **move constructor**:

- 'Moves' the resource
- Simply copies the address of the resource from the source to the current object
- Nulls out the pointer in the source pointer

> [!NOTE]
> When we create temporal objects (r-values), they will occupy storage. We use the move constructor to copy the
> addresses of its resources in the heap and store them in the l-value object that will be created. Finally, we set the
> pointers of the source to null to prevent the resources from being deleted.

### Declaring the Move Constructor
Syntax of Move constructor: `Type::Type(Type&& source);`

```c++
Player::Player(Player&& source);

Account::Account(Account&& source);
```

> [!IMPORTANT]
> We don't use the `const` keyword because we are modifying the source by setting its pointers to null.

```c++
class Move {
    private: 
        int* data;
    public:
        Move(Move&& source);
        // . . .
};

Move::Move(Move&& source) : data{source.data} // in the new instance, set data to the pointer
{
    source.data = nullptr; // set source pointer to null
}

{
    Move m1{5};
    std:vector<Move> moves;
    moves.push_back(m1);    // add m1 (l-value) to vector
    
    moves.push_back(Move{10}); // add temporary value (r-value) to vector. moves data from temp to real value
    
}
```

'Steal' the data and then null out the source pointer.

> [!NOTE]
> An example of how efficient and important this is, is with vectors. Since the grow and reduce size to accommodate the
> values stores, they would need to copy the objects many times. By using the move constructor, the resources (pointers)
> of the objects are 'moved'. 


## This pointer
- `this` is a reserved keyword
- Contains the address of the object - so it's a pointer to the object
- Can only be used in class scope
- All member access is done via this pointer
- Can be used by the programmer:
  - To access data member and methods. *Names can be used, C++ uses `this` behind the scenes*.
  - To determine if two objects are the same
  - Can be dereferenced (`*this`) to yield the current object

```c++
void Account::set_balance(double bal) {
    balance = bal;  // this->balance is implied
}
```

To disambiguate identifier use:
```c++
void Account::set_balance(double balance) {
    balance = balance;  // which balance? The parameter
}

void Account::set_balance(double balance) {
    this->balance = balance;    // Unambiguous
}
```

### Determine Object Identity
Sometimes it's useful to know if two objects are the same object
```c++
int Account::compare_balance(const Account &other) {
    if (this == &other)
        std::cout << "The same objects" << endl;
}
```

## Using `const` with Classes
- Pass arguments to class member methods as `const`
- We can also create `const` objects
- What happens if we call member functions on const objects?
- `const`-correctnes

`villain is a const object, so it's attributes cannot change`
```c++
const Player villai {"Villain", 100, 55};

villain.set_name("Nice guy");             // ERROR
std:: << villain.get_name() << std::endl; // ERROR
```
> [!NOTE]
> The compiler is assuming that `get_name` could modify the object, so it gives am error.

We need to tell the compiler that the method `get_name` does not modify the object.
```c++
class Player{
    private:
    // . . . 
    public:
        std::string get_name() const;
    // . . .
};
```
Now we can use the method when the object is `const`.
> [!IMPORTANT]
> If we try to modify the object inside the `const` method, we will get an error.

## Static Class Members

Class data members can be declared as static. A single data member belongs to that class, not the objects.  
Useful to store class-wide information.

Class functions can be declared as static. Independent of any object. Can be called using the class name.

```c++
class Player {
    private:
        static int num_players;
    public:
        static int get_num_players();
        // . . .
};
```
Typically in "Player.cpp".
```c++
#include "Player.h"

int Player::num_players = 0; 

int Player::get_num_players() {
    return num_players;
}

Player(std::string name_val, int health_val, int ex_val) : // . . .
        {
            ++num_players;
        }
Player::~Player() {
    --num_players;
}
```

## Struct vs Classes
In addition to define a `class`, we can define a `struct`. `struct` comes from the *C Programming language*.  
Essentially the same as a class except *members are `public` by default*.

```c++
class Person {
    std::string name;
    std::string get_name();
};

Person p;
p.name = "Andres";   // compiler error - private
std::cout << p.get_name();  // compiler error - private
```
````c++
struct Person {
    std::string name;
    std::string get_name();
};

Person p;
p.name = "Andres";      // OK - public
std::cout << p.get_name();  // OK - public
````

### Some General Guidelines
- `struct`
  - Use for passive objects with *public* access
  - Don't declare methods inside
- `class`
  - Use for active objects with *private* access
  - Implement *getters/setters* as needed
  - Implement *member methods* as needed


## Friends of a Class
- Friend
  - A function or class that has access to private class member and that function or class is **NOT** a member of the class it's accessing.
- Function
  - Can be regular non-member functions
  - Can be member methods of another class
- Class
  - Another class can have access to private class members

- Friendship must be granted, NOT taken
  - Declared explicitly in the class that is granting friendship
  - Declared in the function prototype with the keyword `friend`
- Friendship is not symmetric
  - Must be explicitly granted
- Friendship is not transitive
  - Must be explicitly granted

### Non-Member function
Non-class methods that have the same name and signature can access all information of the `Player` class
Player.h
```c++
class Player {
    friend void display_player(Player& p);
    std::string name;
    int health;
    int xp;
    public:
    // . . .
};
```
Somewhere else
```c++
void display_player(Player& p) {
    std::cout << p.name << std::endl;
    std::cout << p.health << std::endl;
    std::cout << p.exp << std::endl;
}
```
`display_player` may also change data members

### Member function of Another Class
The friend method can access all information of the `Player` class
```c++
class Player {
    friend void Other_class::display_player(Player&p);
    std::string name;
    int health;
    int xp;
    public:
    // . . .
};
```

### Another Class as a Friend

All the methods from the friend class have access to the player private attributes.

```c++
class Player {
    friend class Other_class;
    std::string name;
    int health;
    int xp;
    public:
    // . . .
};
```



