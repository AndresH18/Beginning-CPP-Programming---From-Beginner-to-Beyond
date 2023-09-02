# Enumerations

A user defined type that models a set of constant integral values.

`enum-key enum-name : enumerator-type { };`

- `enum-key`: defines the scope of the enumeration. Regardless of the scope, it will **always** start with the
  keyword `enum`
- `enum-name`: name of the enumeration (Optional for scoped enumerations)
- `enumerator-type`: can be omitted and the compiler will try to deduce it. Can be used to reduce the amount of space
  the enumeration takes in memory or to increase the accuracy of any calculations involving the enumerator values
- `{ }`: Enumerator List. List of enumerator definitions

**Simplest enumeration**

```c++
enum { Red, Green, Blue };      // Implicit Initialization

enum { Purple = 3, Orange = 4, Pink = 5};   // Explicit Initialization
```

**Implicit Initialization**  
If an element is not initialized to a value, the compiler will initialize it to the previous element value plus 1.  
If the first element in the enumeration is not initialized, the compiler will assign the value 0 (zero).

**Explicit Initialization**  
We can assign the values of the elements ourselves

### Enumerator Type

If the underlying type of an enumeration is not fixed, the compiler assigns the first integral type that is able to hold
the enumerations entire value range. These integral types are listed bellow and rank order with signs given preference
over unsigned

| Integral Type | Width in bits |
|---------------|:-------------:|
| `int`         |

<table>
<thead>
<tr>
<th>Integral Type</th>
<th>Width in bits</th>
</tr>
</thead>
<tbody>
<tr>
<td>

`int`
</td>
<td rowspan="2">At least 16</td>
</tr>
<tr>
<td>

`unsigned int`
</td>
</tr>
<tr>
<td>

`long`
</td>
<td rowspan="2">At least 32</td>
</tr>
<tr>
<td>

`unsigned long`
</td>
</tr>
<tr>
<td>

`long long`
</td>
<td rowspan="2">At least 64</td>
</tr>
<tr>
<td>

`unsigned long long`
</td>
</tr>

</tbody>
</table>

### Enumeration Name

- Nameless
    - Since they don't have a name, it's not possible to declare variables with them and there is no type safety
    - ```c++
  enum {Red, Green, Blue};
    ```
- Named
    - We are defining the enumeration as a unique type that can only assume it's enumerated elements.
    - Type safety
    - ```c++ 
  enum Color {Red, Green, Blue};
    ```

## Unscoped Enumerations

`enum enum-name : enumerator-type { };`

When an enumeration is unscoped, it's enumerators are unqualified, and they're visible throughout the entire scope in
which the enumeration was declared.  
This means that if we want to use the enumeration's enumerators, it's not necessary to specify which enumeration the
enumerators belong to.

```c++
State state = get_state();

if (state == Nominal) 
    initiate(Launch);
else if (state == Inclement_Weather)
    initiate(Hold);
else if (state == Engine_Failure)
    initiate(Abort);

// or - switch statements are more efficient than if-else for enumerations
switch (state) {
    case Engine_Failure:
        initiate(Abort);
        break;
    case Inclement_Weater:
        initiate(Hold);
        break;
    case Nominal:
        initiate(Launch);
        break;
}
```

> [!IMPORTANT]
> If-else provides Linear access time to the execution block because it checks each condition successively until it
> reaches the condition.
>
> Switch-case provides constant time access to the execution block, making it more efficient

### Using cin and cout with Unscoped Enumerations

```c++
enum State {    // underlying type: int
    Engine_Failure,     // 0 
    Inclement_Weather,  // 1
    Nominal             // 2
};       

std::underlying_type<State> user_input; // type: int
std::cin >> user_input;                 // userInput = 2

State state = State(user_input);        // state = 3 => Nominal
```

`std::underlying_type<T>`: is a C++ object that represents the underlying type used by the object.

> [!WARNING] Using this approach allows enums that don't exist because the underlying type (int in this case) can hold
> integers bigger than the used in the enum.

**Overloading the Extraction Operator**

```c++
std:.istream& operator>>(std::istream& is, State& state) {
    std::underlying_type<State> user_input;     // type: int
    is >> user_input;
    switch (user_input) {
        case Engine_Failure: 
        case Inclement_Weather: 
        case Engine_Failure: 
            state = State{user_input}; 
            break;
        default:
            std::cout << "User input is not a valid State";
    }
    
    return is;
}

State state;
std::cin >> state;  // Valid with overloaded extraction operator
```

When using `cout`, the enumeration is implicitly converted to its underlying type. We could use a switch case or
overload the insertion operator

```c++
std::ostream& operator<<(std::ostream& os, const State& state) {
    switch (state) {
        case Engine_Falure:
            os << "Engine Failure";
            break;
        case Inclement_Weather:
            os << "Inclement Weather";
            break;
        case Nominal:
            os << "Nominal";
            break;
    }
    return os;
}
```

## Scoped Enumerations

`enum class enum-name : enumerator-type { };`

Enumerations whose enumerators are qualified and, therefore they're only visible by using the scope resolution Operator.

When using [Unscoped](#unscoped-enumerations), we could compare enumerators from different enumerations which could give
rise to errors since the enumerators could have the same underlying value. By using **Scoped** Enumerations, if we try
to compare enumerators from different enumerations, we would find that they are different even if they had the same
underlying value

```c++
enum class Whale {Blue, Beluga, Gray};

Whale whale = Whale::Beluga;

switch (whale) {
    case Whale::Blue:
        std::cout << "Blue Whale";
        break;
    case Whale::Beluga:
        std::cout << "Beluga Whale";
        break;
    case Whale::Gray:
        std::cout << "Gray Whale";
        break;
}
```



