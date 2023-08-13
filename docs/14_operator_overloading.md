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

## Overloading Operators as Global Member Functions
Since this are not member functions, we no longer have access to the `this` pointer to refer to the object. 
So, since we often need access to private attributes in the objects, we tend to declare this functions as friends of the class.

Member functions didn't need the caller as a parameter, but global functions need the caller as the first parameter.

### Unary Operators as Global Functions
```c++
ReturnType operatorOP(Type &obj);

Number operator-(const Number &obj);
Number operator++(const Number &obj);    // pre-increment
Number operator++(const Number &obj, int);    // post-increment
booloperator!(const Number &obj);

Number n1 {100};
Number n2 = -n1;    // n1.operator-();
n2 = ++n1;          // n1.operator++();
n2 = n1++;          // n1.operator++(int);
```

### binary Operators as Global Functions

```c++
ReturnType operatorOP(const Type &lhs, const Type &rhs);

Number operator+(const number &lhs, const Number &rhs);
Number operator-(const number &lhs, const Number &rhs);
bool operator==(const number &lhs, const Number &rhs);
bool operator<(const number &lhs, const Number &rhs);
```

Let's make the `!=` using global members:
```c++
bool operator!=(const MyString &lhs, const MyString &rhs) {
    return !(std::strcmp(lhs.str, rhs.str) == 0);
}
```
If declared as a friend of `MyString`, it can access private the `str` attribute. Otherwise, we must use getters
```c++
class MyString {
    friend bool operator!=(const MyString &lhs, const MyString &rhs);
    // . . .
};
```

> [!IMPORTANT]
> Do not overload the same operator as a member function and global function. C++ will not know which to use

## Stream Insertion and Extraction operators (>>, <<)
```c++
Player hero {"Hero", 100, 33};
std::cout << hero << endl;  // {name: hero, health: 100, xp: 30}

Player hero;
cin >> hero;
```

Doesn't make sense to implement as member methods, because the left operand must be a user-defined class.

We don't normally do this:
```c++
MyString andres;
andres << cout; // huh?

Player hero;
hero >> cin;    // huh?
```

### Stream Insertion Operator <<

```c++
std::ostream &operator<<(std::ostream &os, const MyString &obj) {
    os << obj.str;      // if friend function
    // os << obj.get_str(); if not friend function
    return os;
}
```
Return a reference to the `ostream`, so we can keep inserting.  
> [!WARNING]
> Don't return `ostream` by value

### Stream Extraction Operator >>
```c++
std::istream &operator>>(std::istream &is, MyString &obj) {
    char *buff = new char[1000];
    is >> buff;
    obj = MyString{buff}; // If you have a copy or move assignment
    delete[] buff;
    return is;
}
```
Update the object passed in.  
Return a reference to the `istream` so we can keep inserting.  





