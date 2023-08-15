# Polymorphism

Is a fundamental part of Object-Oriented Programming

**Compile Time**: Early binding, static binding.

**_Runtime_**: Late binding, dynamic binding. Being able to assign different meanings to the same function at runtime.

Allows to program more abstractly. Let C++ figure what function to call at runtime.  
Not the default in C++, run-time polymorphism is achieved via

- Inheritance
- Base class pointers or references
- Virtual functions

## How to implement runtime polymorphism

To use Runtime Polymorphism, we declare the **Base** methods that we want Derived classes to override as `virtual`.

```c++
class Base {
protected:
    virtual void method_1();
public:
    virtual int method_2();
        
};
```

Then, in the **Derived** class we declare the methods we want to override using `override`

```c++
class Derived : public Base {
    void method_1() override;
    int method_2() override;
    
};
```

If we don't want to override the function in the *Derived* class, we can also just declare it as `virtual`, but it's not
really necessary since it will be implicitly `virtual`. However, it's a good practice to use `virtual` in the derived types.

Now, when we have a pointer of type **Base** pointing to an object of type **Derived**, and try to call `method_1()`, we
will call the implementation of **Derived**.
By using `virtual`/`override`, we will always use the implementation of the real class type instead of the pointer type.

**The functions signature must be exactly the same in order to override. Otherwise, it is being redefined**

> [!NOTE]
> Redefined functions are bound statically.
>
> overridden functions are bound dynamically
>
> Virtual functions are overridden.  
> Allows us to treat all objects generally as objects of the Base class



> [!IMPORTANT]
> We must use a *Base* class `pointer` or `reference`

## Virtual Destructors

Problemas can happen when we destroy polymorphic objects, if a derived class is destroyed by deleting its storage via
the base class pointer, and the class non-virtual destructor. Then the behaviour is undefined in the C++ standard.

Derived objects must be destroyed in the correct order starting at the correct destructor

### Solution

If a class has virtual functions, **always** provide a public virtual destructor.  
If base class destructor is virtual, then all derived destructors are also virtual.

```c++
class Account {
public:
    virtual void withdraw(double amount);
    virtual ~Account();
    // . . .
};
```


## The `final` Specifier
C++ provides the final specifier.

When used at the class level it prevents the class from being derived from.

When used at the method level it prevents `virtual` methods from being *overridden* in derived classes.
### Class Level `final`
```c++
class My_class final {
    // . . .
};

class Derived final : public Base {
    // . . .
};
```

### Method Level `final`
```c++
class A {
 public:
    virtual void do_something();
};

class B : public A {
    virtual void do_something() final;  // prevent further overriding
};

class C : public B {
    virtual void do_something();    // COMPILER ERROR - can't override
};
```

## Using Base class References
```c++
Account a;
Account &ref = a;
ref.withdraw(1000); // Account::withdraw

Trust t;
Account &ref1 = t;
ref1.withdraw(1000);    // Trust::withdraw
```

Another example
```c++
void do_withdraw(Account& account, double amount) {
    account.withdraw(amount);
}

Account a;
do_withdraw(a, 1000);   // Account::withdraw

Trust t;
do_withdraw(t, 1000);   // Trust::withdraw
```

## Pure virtual functions and Abstract classes
### Abstract Class
Cannot instantiate objects.  
These classes are used as base classes in inheritance hierarchies.  
Often referred to as *Abstract Base Classes*.

> [!NOTE]
> To generic to create objects from. Example: _Shape_, _Employee_, _Account_, _Player_.  
> Serves as parent to Derived classes that may have objects.  
> Contains at least one [pure virtual function](#pure-virtual-functions)

**Concrete class**  
Used to instantiate objects from.  
All their member functions are defined.

### Pure Virtual Functions

A pure virtual function is a special type of virtual function in C++ that is declared in a base class but has no
implementation in that class. It's used to define an interface that derived classes must implement. Pure virtual
functions are also sometimes referred to as abstract methods.

Here's how you define a pure virtual function:

```c++
class Base {
public:
    virtual void pureVirtualFunction() = 0; // Pure virtual function declaration
};
```

Key points about pure virtual functions:

1. No Implementation: A pure virtual function is declared using the virtual keyword followed by the function's signature
   and = 0 at the end. This = 0 indicates that the function has no implementation in the base class.

2. Abstract Class: A class that contains at least one pure virtual function is considered an abstract class. An abstract
   class cannot be instantiated directly; it's meant to be used as a base class for other classes.

3. Derived Class Implementation: Any class that derives from an abstract class and intends to be instantiated must
   provide implementations for all pure virtual functions declared in the base class. This enforces a contract that
   derived classes must adhere to the interface defined by the pure virtual functions.

4. Override in Derived Classes: When a derived class inherits a pure virtual function from a base class, it must provide
   a concrete implementation (non-pure) for that function. This allows objects of the derived class to be instantiated.

Here's an example:

```c++
#include <iostream>

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
};

int main() {
    Circle circle;
    Square square;

    circle.draw(); // Outputs: Drawing a circle
    square.draw(); // Outputs: Drawing a square

    return 0;
}
```

In this example, the Shape class has a pure virtual function draw(), which makes it an abstract class. Both the Circle
and Square classes derive from Shape and provide concrete implementations for the draw() function. This allows instances
of Circle and Square to be created and the draw() method to be called on them


## Abstract Classes as Interfaces
An interface class in C++ is an [abstract class](#abstract-class) that only have [pure virtual functions](#pure-virtual-functions).  
These functions provide a general set of services to the user of the class.  
Provided as public.  
Each subclass is free to implement these services as needed.  
Every service(method) must be implemented.  
The service type information is strictly enforced 


C++ does not provide *true* interfaces. We use _abstract classes_ and _pure virtual functions_ to achieve it.

Suppose we want to provide `Printable` support for any object we wish without knowing it's implementation at compile time. `std::cout << any_object << std::endl;`
```c++
class Printable {
    friend std::ostream &operator<<(std::ostream&, const Printable& obj);
 public:
    virtual void print(std::ostream &os) = 0;
    virtual ~Printable() {};
};

std::ostream &operator<<(ostream &os, const Printable& obj) {
    obj.print(os);
    return os;
}
```

```c++
class Any_class : public Printable {
 public: 
    // must override Printable::print()
    virtual void print(std::ostream &os) override {
        os << "Hi from Any_class";
    }
};
```

```c++
Any_class* ptr = new Any_class();
cout << *ptr << endl;

void function1(Any_class& obj) {
    cout << obj << endl;
}
void function2(Printable& obj) {
    cout << obj << endl;
} 

function1(*ptr);    // "Hi from Any_class"
function2(*ptr);    // "Hi from Any_class"
```

> [!NOTE]
> Sometimes classes that are intended to be used as interfaces have prefix `I_` in their names `class I_Shape { . . .};












