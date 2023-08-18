# Exception Handling

## Basic Concepts

**Exception Handling**:

- Dealing with extraordinary situations.
- Indicates that an extraordinary situation has been detected or has occurred.
- Program can deal with the situations in a suitable manner.

**What Causes Exceptions**:

- Insufficient resources
- Missing resources
- Invalid operations
- Range operations
- Range violations
- Underflow and overflows
- Illegal data
- Many others

**Exception Safe**: when code handles exceptions

### Terminology

**Exception**: an object or primitive type that signals that an error has occurred.

**Throwing and Exception (Raising an Exception)**:

- The code detects that an error has occurred or will occur
- The place where the error occurred may not know how to handle the error
- The code can throw the exception describing the error to another part of the program that knows how to handle the
  error.

**Catching an Exception (Handle the Exception)**: Code that handles the exception. May or may not cause the program to
terminate

### Syntax

- `throw`: Throws an exception, followed by an argument
- `try { . . . }`: You place code that may throw an exception in a *try/catch* block. If the code throws an exception,
  the try block is exited; the thrown exception is handles by a catch handler; if no catch handler handles the
  exception, the program terminates.
- `catch(Exception ex) { . . . }`: code that handles the exception; can have multiple catch handlers; may or may not
  cause the program to terminate

Example: Dividing by zero

```c++
double average {};
try {                       // try block
    if (total == 0) 
        throw 0;            // throw the exception
      
    average = sum / total;  // won't execute if total == 0
    // use average . . .
} catch (int &ex) {         // exception handler
    std::cout << "can't divide by zero" << std::endl;
}
std::cout << "program continues" << std::endl;
```

## Throwing an Exception from a Function

What do we return if `total` is zero?

```c++
double calculate_avg(int sum, int total) {
    return static_cast<double>(sum) / total;
}
```

Throw an exception if we can't complete successfully

```c++
double calculate_avg(int sum, int total) {
    if (total == 0) 
        throw 0;
    
    return static_cast<double>(sum) / total;
}
```

Catching the exception:

```c++
double average {};
try {
    average = calculate_avg(sum, total);
    std::cout << average << std::endl;
} catch (int &ex) {
    std::cerr << "You can't divide by zero" << std::endl;
}

std::cout << "bye" << std::endl;
```

> [!NOTE]
> C++ will keep searching the stack until it finds a handler for the exception

## Handling Multiple Exceptions

Throwing multiple exceptions from a function

What if a function can fail in several ways:

- `gallons` is zero
- `miles` or `gallons` is negative

```c++
double calculate_mpg(int miles, int gallons) {
    return static_cast<double>(miles) / gallons;
}
```

```c++
double calculate_mpg(int miles, int gallons) {
    if (gallons == 0) 
        throw 0;
    
    if (miles < 0 or gallons < 0) 
        throw std::string{"Negative value error"};
    return static_cast<double>(miles) / gallons;
}
```

The try block

```c++
try {
    miles_per_gallon = calculate_mpg(miles, gallons);
    std::cout << miles_per_gallon << std::endl;
} catch(int &ex) {
    std::cerr << "You can't divide by zero" << std::endl;
} catch (std::string &ex) {
    std::cerr << ex << std::endl;
} 
std::cout << "Bye" << std::endl;
```

### Catch all block

```c++
// other try/catch s
} catch (...) {
// respond to exception, but don't have access to it.
}
```

## Stack Unwinding

If an exception is thrown but not caught in the current scope, C++ tries to find a handler for the exception by
unwinding the stack

- Function in which the exception was not caught terminates and is removed from the stack. All resources on that stack
  are deleted, objects on the heap remain intact. It's important to manage lifetimes using RAII and Smart Pointers
- If a try block was used, catch blocks are checked for a match
- If no try block was used or the catch blocks handlers don't match, stack unwinding occurs again
- If the stack is unwound back to main and no catch handler handles the exception, the program terminates

## User Defined Exceptions
We can create exception classes and throw instances of those classes.

Best practices:
- throw an object, not a primitive type
- throw an object by value
- catch an object by reverence (or const reference)

```c++
class DivideByZeroExeception {
    
};

class NegativeValueException {};
```
We can provide constructors, attributes and methods for these classes


```c++
double calculate_mpg(int miles, int gallons) {
    if (gallons == 0) 
        throw DivideByZeroException();
    
    if (miles < 0 or gallons < 0) 
        throw NegativeValueException();
    return static_cast<double>(miles) / gallons;
}


try {
    miles_per_gallon = calculate_mpg(miles, gallons);
    std::cout << miles_per_gallon << std::endl;
} catch(const DivideByZeroException &ex) {
    std::cerr << "You can't divide by zero" << std::endl;
} catch (const NegativeValueException &ex) {
    std::cerr << ex << std::endl;
} 
std::cout << "Bye" << std::endl;
```

## Class-Level Exceptions
Exceptions can also be thrown from within a class:
- Method: these work the same way as the do for normal functions
- Constructor: Constructors may fail; constructor do not return any value; throw an exception in the constructor if you cannot initialize an object
- Destructor: Do **NOT** exceptions from a Destructor






