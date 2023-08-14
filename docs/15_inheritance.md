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







