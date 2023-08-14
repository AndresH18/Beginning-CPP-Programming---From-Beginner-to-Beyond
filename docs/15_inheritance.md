# Inheritance

```c++
class Account {
    // balance, deposit, withdraw, . . .
};

class Savings_Account : public Account {
    // interest_rate, specialized withdraw, . . . 
};

class Checking_Account : public Account{};

class Trust_Account : public Account{};
```

## Terminology and Notation

### Terminology

*Inheritance*  
Process of creating new classes from existing classes. Reuse mechanism.

*Single Inheritance*  
A new class is created from another 'single' class

*Multiple Inheritance*  
A new class is created from two (or more) other classes.

**_Base_ Class**  
'Parent class', 'super class'. The class being extended or inherited from

**_Derived_ Class**  
'Child class', 'sub class'. The class being created from the Base Class. Will inherit attributes and operations from the
Base Class

> [!IMPORTANT]
> We graph this relationship using a solid line, with an empty triangle, pointing to the _base_ class from the _derived_
> class


_Is-A_ Relationship:  
Public Inheritance, Derived classes are subtypes of the base class. Can use a derived class object wherever we use a
base class object.


> [!NOTE]
> The class from which other classes are derived, but that doesn't derive from another type is typically referred as the
**root class** of the hierarchy.

## Inheritance vs Composition

Both allow reuse of existing code.

Public Inheritance: is-a relationship
> Employee 'is-a' Person  
> Checking Account 'is-a' Account  
> Circle 'is-a' Shape

Composition: has-a relationship
> Person 'has-a' Account  
> Player 'has-a' Special Attack  
> Circle 'has-a' Location

> [!IMPORTANT]
> We graph **composition** using a solid line

## Inheritance Syntax

```c++
class Base {
    // base class members . . .
};

class Derived : <access-modifier> Base {
    // derived class members . . .
};
```

`<access-modifier>` can be: `public`, `private` or `protected`. If no specified, `private` is used by default.

`public`: Establishes a 'is-a' relationship between Derived and Base classes. Most common.

`private` and `protected`: Establishes 'derived class **has a** base class' relationship. It's used to implement one
class in terms of another. It's different from composition.
> [!NOTE]
> The `protected` modifier makes all public Base properties protected in the derived class.  
> The `private` modifier makes all public and protected properties private in the derived class.

## Constructors and Destructors

### Constructors

A derived class inherits from its base class.  
The base part **must** be initialized __before__ the derived class is initialized.  
When a derived object is created: The **Base** constructor executes first, then the **Derived* constructor

### Destructors

Class destructor is invoked in _reversed_ order as constructors.  
The _Derived_ part **must** be destroyed _before_ the Base destructor is invoked.

1. The Derived destructor is called
2. Base destructor is called

Each destructor should free resources allocated in its own constructors.

> [!NOTE]
> The Derived destructor should free resources from the '_derived_' part. The Base destructor handles the resources of
> the '_base_' part.


**A Derived class does _NOT_ inherit**:

- Base class constructors
- Base class destructor
- Base class overloaded assignment operators
- Base class friend functions

However, the derived class constructors, destructors and overloaded assign operators can invoke the base-class versions.

> [!NOTE]
> C++11 allows explicit inheritance of base 'non-special' constructors with `using Base::Base`; anywhere in the derived
> class declaration.
>
> Special case constructors would be **move constructor**, **copy constructor**

## Passing Arguments to the Base Class Constructor

The Base part of the Derived class must be initialized first.

```c++
class Account {
private:
    double amount;
public:
    Account(double amount) : amount{amount} {}
};

class SavingsAccount : public Account {
private:
    double rate;
public:
    SavingsAccount(double amount, double rate) 
        : Account{amount}, // calling base constructor
        rate{rate}
};
```

## Copy and Move constructors and Overloaded Operator=

**Not inherited from the Base class**.  
You may not need to provide you own, The compiler versions may be just fine.  
We can explicitly invoke the Base class versions from the Derived class.

### Copy Constructor

If we are going to copy a derived object, then we need to ensure that the Base part is also copied.

Can invoke Base copy constructor explicitly. Derived object 'other' will be *sliced*

```c++
Derived::Derived(const Derived &other) : Base(other), {Derived initialization list} {
    // code
}
```

The following code is to understand this. In real life, this code is simple enough that the compiler generated
*copy/move constructor* would be best.

````c++
class Base {
    int value;
public:
    // same constructors as previous examples
    Base(const Base &other) : value {other.value} {
        std::cout << "Base copy constructor" << endl;
    }
};

class Derived : public Base {
    int doubled_value;
public:
    // same constructors as previous examples
    
    Derived(const Derived &other) : Base(other), double_value {other.double_value} {
        std::cout << "Derived copy constructor" << endl;
    }
};
````

### Move constructor

The move constructor works the same way as the [copy constructor](#copy-constructor).

### Overloaded operator=

#### Copy Assignment

```c++
class Base {
    int value;
public:
    // same constructos as previous examples
    
    Base &operator=(const Base &rhs) {
        if (this != &rhs) {
            value = rhs.value;
        }
        retunr *this;
    }
};

class Derived : public Base {
    int doubled_value;
public: 
    // same constructos as previous example
    Derived &operator=(const Derived &rhs) {
        if (this != &rhs) {
            Base::operator=(rhs); // assign Base part 
            // since we work with references, the object is modified but the reference is not changed.
            // Therefore, the rhs doesn't reference something else.
            
            doubled_value = rhs.doubled_value; // assign Derived part
        }
        return *this;
    }
};
```

#### Move Assignment

Move assignment works the same way as with the [copy assignment](#copy-assignment).

Often we don't need to provide our own [Copy](#copy-constructor)/[Move](#move-constructor)
and [Overloaded Operator=](#overloaded-operator).

If we **DO NOT** define them in _Derived_, the compiler will create them automatically and call the _Base_ class's
version.

If we **DO** provide _Derived_ versions, then **WE** must invoke the _Base_ versions explicitly

> [!WARNING]
> Be careful with *raw pointers*. Especially if Base and Derived each have *raw pointers*. Provide them with deep copy
> semantics.

## Redefining Base Class Methods

Derived class can directly invoke Base class methods. Derived class can **override** or **redefine** Base class methods.

```c++
class Account {
public:
    void deposit(double amount) {balance += amount);}
};

class SavingsAccount : public Account {
public:
    void deposit(double amount) {// REDEFINE Base class method
        amount += some_interest;
        Account::deposit(amount); // INVOKE Bae class method
    }
};
```

### Static Binding of Method calls

Binding of which method to use is done at compile time. Basically, the compiler determines which methods to call based
on what it sees at compile time.

- Default binding for C++ is static
- Derived class objects will use `Derived::deposit`. But we can explicitly invoke `Base::deposit`
  from `Derived::deposit`.

```c++
Base b;
b.deposit(100);     // Base::deposit

Derived d;
d.deposit(100);     // Derived::deposit

Base* ptr = new Derived();
ptr->deposit(1000); // Base::deposit
```

By assigning a derived type to a base type variable, all method calls are to the Base implementation, **NOT** the
Derived.


## Multiple Inheritance
- A derived class inherits from 2 or more Base classes at the same time.
- The Bases classes may belong to unrelated class hierarchies.

```c++
class Department_Chair : public Faculty, public Administrator {
    
};
```

## Const Expressions `constexpr`
Constants that are available only to the class.

```c++
class Account {
    static constexpr const char* def_name = "Unnamed Account";
};
```

