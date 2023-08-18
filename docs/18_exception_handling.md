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



















