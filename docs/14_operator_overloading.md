# Operator Overloading

Using traditional operators (`+`, `=`, `*`, etc.) with used.  
Allows user defined types to behave similar to built-in types.  
Can make code more readable and writeable.  
Not done automatically (except for the assignment operator). They must be explicitly defined.

Suppose we have a `Number` class that models any number.  
Using functions:

```c++
Number result = multiply(add(a,b), divide(c,d));
```

Using member methods:

```c++
Number result = (a.add(b)).multiply(c.divided(d));
```

> [!NOTE]
> This is hard to read.

Suppose we overloaded the operators:

```c++
Number result = (a + b) * (c / d);
```

> [!NOTE]
> This is easier to read

By overloading operators we can make code more readable, easier to understand and to use.

> [!IMPORTANT]
> The majority of C++ operators can be overloaded, **except**: `::`, `?:`, `. *`, `*`, `sizeof`

### Some Basic Rules

- Precedence and Associativity cannot be changed
- *arity* cannot be changed(i.e can't make the divisor operator unary)
- Can't overload operators for primitive type (e.g int, double, etc.)
- Can't create new operators
- `[]`, `()`, `->`, and `=` must be declared as member methods
- Other operators can be declared as member methods or global functions

View Class [MyString](../Section%2014_Operator%20Overloading/MyString.h)

## Assignment Operator

### Assignment operator (`=`)

#### Assignment - Copy

C++ provides a default assignment operator used for assigning one object to another.

```c++
MyString s1 {"Andres"};
MyString s2 = s1;   // NOT assignment, Initialization

s2 = s1; // assignment, because s2 already exists
```

Default is member-wise assignment (shallow copy). If we have raw pointer data, we must do deep copy.

**Copy Assignment Operator**: `Type & Type::operator=(const Type & rhs);`

```c++
MyString& MyString::operator=(const MyString &rhs);

s2 = s1;        // we write this
s2.operator=(s1); // operator= method is called
```

Implementing in [MyString](../Section%2014_Operator%20Overloading/MyString.cpp)

Step-by-Step

1. check for self assignment
    ```c++
    if (this == &rhs)   // p1 = p1;
        return *this;   // return current object
    ```
2. Deallocate storage for `this->str` since we are overwriting it
    ```c++
    delete[] str;
    ```
3. Allocate storage for the deep copy
    ```c++
    str = new char[std::strlen(rhs.str) + 1];
    ```
4. Perform the copy
    ```c++
    std::strcpy(str, rhs.str);
    ```
5. Return the current by reference to allow chain assignment
    ```c++
   return *this; 
   // s1 = s2 = s3;
   ```

In the [example](../Section%2014_Operator%20Overloading/main.cpp), we do:

```c++
MyString myString;
// . . .
myString = "Some string";
```

What happens is that we are creating a temporary variable of type `MyString` using the overloaded constructor (which
receives a string). Then we assign it to `myString`.


#### Assignment - Move
You can choose to overload the move assignment operator. C++ will use the copy assignment if necessary.
```c++
MyString s1;
s1 = MyString{"Andres"}; // Move Assignment
```
If we have raw pointer data, we should overload the move assignment operator for efficiency.

Syntax for overloading Move Assignment operator: `Type &Type::operator=(Type && rhs);`
```c++
MyString &MyString::operator=(MyString && rhs);

s1 = MyString("Andres"); // move operator= called
s1 = "David";            // move operator= called - implicit constructor
```
Implementing in [MyString](../Section%2014_Operator%20Overloading/MyString.cpp)


## Overloading Operators as Member Functions
### Unary Operators
Only interact with one argument.

Unary operators (`++`, `--`, `-`, `!`)

```c++
ReturnType Type::operatorOP();

Number Number::operator-() const;
Number Number::operator++();    // pre-increment
Number Number::operator(int);   // post-increment
bool Number::operator!() const;

Number n1 {100};
Number n2 = -n1;    // n1.operator-();
n2 = ++n1;          // n1.operator++();
n2 = n1++;          // n1.operator++(int);
```

Example: we could have the `operator-()` return a lower case string
```c++
MyString andres {"ANDRES"};
MyString andres2;

andres.display();   // ANDRES
andres2 = -andres;  // andres.operator-();

andres.display();   // ANDRES
andres2.display();   // andres

MyString MyString::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buf); i++) 
        buff[i] = std::tolower(buff[i]);
    
    MyString temp {buff};
    delete[] buff;
    return temp;
}
```

### Binary operators
Interact with two values.

Binary Operators (`+`, `-`, `==`, `!=`, `<`, `>`, etc.)

```c++
ReturnType Type::operatorOP(const Type &rhs);

Number Number::operator+(const Number &rhs) const;
Number Number::operator-(const Number &rhs) const;
bool Number::operator==(const Number &rhs) const;
bool Number::operator<(const Number &rhs) const;

Number n1 {100}, n2 {200};
Number n3 = n1 + n2;    // n1.operator+(n2);
n3 = n1 - n2;           // n1.operator-(n2);
if (n1 == n2)           // n1.operator==(n2);
    // . . . 

```