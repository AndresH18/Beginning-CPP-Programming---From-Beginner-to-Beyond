# Lambda Expressions

## Structure

`[] () -> return_type specifiers { }`

- `[]`: Capture List.
- `()`: Parameter list
- `return_type`: Return type, Can be omitted and the compiler will try to deduce it
- `specifiers`: Optional specifiers, _mutable_ and _constexpr_
- `{ }`: body

We can store lambdas in variables

```c++
auto l = [] () { std::cout << "Hi"; };

l();    // Displays Hi
```

```c++
auto l = [] (int x) { std::cout << x; };

l(10);      // Displays 10
l(100);     // Displays 100
```

```c++
auto l = [] (int x, int y) -> int { return x + y; };
// or
auto l = [] (int x, int y) { return x + y; };

std::cout << l(2, 3);   // displays 5
std::cout << l(10, 20); // displays 30
```

Just like with functions, the parameter list can contain `&` to specify that data is passed by reference; `*` for
pointers...

We can use the keyword `auto` on the parameter list to tell the compiler to deduce the parameter type

## Stateless Lambda Function

When the capture list is empty. The lambda function only knows about the information passed to it in the parameter list.

**Passing lambdas expressions to functions**

```c++
#include <functional>

// foo receives a function that returns void and has one parameter of type int
void foo(std::function<void(int)> l) {  // c++14
    l(10);
}
// or
void foo(void (*l)(int)) {  // c++14
    l(10);
}

// or

void foo(auto l) {  // c++20
    l(10);
}
```

**Returning lambda expressions from functions**

```c++
#include <functional>

std::function<void(int)> foo() {
    return [] (int x) { std::cout << x; }
}
// or
void (*foo()) (int) {
    return [] (int x) { std:: cout << x; }
}
// or 

auto foo() {
    return [] (int x) { std::cout << x; }
}
```

**Using lambda expressions as functions parameters**

```c++
foo([] (int x) { std::cout << x; });
//or
auto l = [] (int x) { std::cout << x; };
foo(l);
```

## Stateful Lambda Expression

`[captured_variables] () -> return_type specifiers { }`

- `captured_variables`: Non-Empty capture list, defines what information/variables should be captured

### Capture by Value

`[direct_variable_name] (parameter_list) -> return_type specifiers { }`

The captured variables cannot be modified inside the lambda. Only their `const` methods can be used.

```c++
int y {10};

auto l = [y] (int x) { std::cout << x + y; };
```

**Allow modification**

To allow modifying a _captured by value_ variable (use non-const methods) we can add the `mutable` specifier

```c++
int x {100};

[x] () mutable {
    x += 100;
    std::cout << x; // displays 200
}();

std::cout << x; // displays 100 - remember, variable is captured by value
```

### Capture by Reference

To capture variables by reference, we use the `&` operator on the capture list.  
This makes that any change to the captured variable inside the lambda will be visible outside the lambda.

```c++
int x {100};

[&x] () {x += 100;} ();

std::cout << x; // displays 200
```

## Mixing capture

We can capture variables by reference and/or value

| Capture Clause | Description                           | 
|----------------|---------------------------------------|
| `[x, y]`       | Capture both x and y by value         |
| `[x, &y]`      | Capture x by value and y by reference |
| `[&x, y]`      | Capture x by reference and y by value |
| `[&x, &y]`     | Capture both x and y by reference     |

## Default Captures

Instead of defining the capture type for each variable, we can use default captures.

A default capture allows the lambda to capture all variables referenced within its body according to the defined capture
mode. This allows not specifying the variables in the capture clause, they will be resolve based on the content of the
lambda's body.

| Mode     | Description                       |
|----------|-----------------------------------|
| `[=]`    | Default capture by value          |
| `[&]`    | Default capture by reference      |
| `[this]` | Default capture this by reference |

We can also mix the Default captures with value and reference

| Capture     | Description                                         |
|-------------|-----------------------------------------------------|
| `[=, &x]`   | Default capture by value but capture x by reference |
| `[&, y]`    | Default capture by reference but capture y by value |
| `[this, z]` | Default capture this but capture z by value         |
