# Standard Template Library (STL)

- Generic Programming/Meta-programming
    - Preprocessor macros
    - Function Templates
    - Class templates
- STL Containers
- STL Iterators
- STL Algorithms
- Array
- Vector
- Deque
- List and Forward List
- Set and Multi Set
- Map and Multi Map
- Stack and Queue
- Priority Queue
- Algorithms


- Container
    - Collections of objects or primitive types
- Algorithms
    - Functions for processing sequences of elements from containers (find, max, count, accumulate, sort, etc.)
- Iterators
    - Generate sequences of elements from containers (forward, reverse, by value, by reference, constant, etc.)
- Sequence Containers
    - array, vector, list, forward_list, deque
- Associative containers
    - set, multi set, map, multi map
- Container Adapters
    - stack, queue, priority queue

_Simple example_

```c++
#include <vector>
#include <algorithm>

std::vector<int> v {1, 5, 3};

// sort
std:.sort(v.begin(), v.end());
for (auto& elem : v) 
    std::cout << elem << std::endl; // 1 3 5
// reverse sort
std::reverse(v.begin(), v.end());
for (auto& elem : v) 
    std::cout << elem << std::endl; // 5 3 1
// accumulate
sum = std::accumulate(v.begin(), v.end(), 0);
std::cout << sum << std::endl;  // 9  - 1+3+5
    
```

**Types of Iterators**

- Input iterators
    - From container to the program
- Output iterators
    - From the program to the container
- Forward iterators
    - Navigate one item at a time in one direction
- Bi-directional iterators
    - Navigate one item at a time in both directions
- Random access iterators
    - Directly access a container item

## Generic Programming

Generic Programming
> Writing code that works with a variety of type as arguments, as long as those argument types meet specific syntactic
> and semantic requirements

### Preprocessor Directives _Macros_

`#define`

- C++ preprocessor directives
- No type information
- Simple substitution
- ```c++
  #define MAX_SIZE 100
  #define PI 3.14159
  ```

> Whenever the 'defined' elements are used in code, they are replaced with the

```c++
#define MAX(a, b) ((a > b) ?  a: b)

std::cout << MAX(10, 20) << std::endl;    // 20
std::cout << MAX(3.5, 2.4) << std::endl;    // 3.5
std::cout << MAX('A', 'C') << std::endl;    // C
```

### Function Templates

_we can use `typename` or `class`_

**Single type parameter**

```c++
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
template <class T> T min(T a, T b) {
    return (a < b) ? a : b;
}

int a {10};
int b {20};
std::cout << max<int>(a, b) << std::endl;   // 20
double c {1000};
double d {300};
std::cout << max<double>(c, d) << std::endl;   // 300
```

**Multiple type parameter**

```c++
template<typename T1, typename T2, typename R> R func(T1 a, T2 b) {  
    // Use a:T1, b:T2
    // . . .
    // Return R type
}
```

### Class Templates

- It's similar to a [function template](#function-templates) but at a class level
- Allows **plugging-in** any data type
- Compiler generates the appropriate class from the blueprint

```c++
template <typename T>
class Item {
    private:
        std::string name;
        T value;
    public:
        Item(std::string name, T value) : name{name}, value{value} {
        }    
        std::string get_name() const { return name;}
        T get_value() const { return value;}
};

template <typename T1, typename T2>
struct My_Pair {
    T1 first;
    T2 second;
};
```

## Containers

- Data structures that can store objects of _almost_ any type
    - _[template based classes](#class-templates)_
- Each container has member functions
    - Some are specific to the container
    - Others are available to all containers
- Each container has an associated header file
    - `#include <container_type>`

### Common Functionality Provided by STL Containers

| Function                      | Description                                               |
|:------------------------------|:----------------------------------------------------------|
| Default constructor           | Initializes an empty container                            |
| Overloaded constructors       | Initializes containers with many options                  |
| Copy constructor              | Moves existing container to new container                 |
| Move constructor              | Moves existing container to new container                 |
| Destructor                    | Destroys a container                                      |
| Copy assignment `operator=`   | Copy one container to another                             |
| Move assignment `operator=`   | Move one container to another                             |
| `size`                        | Returns the number of elements in the container           |
| `empty`                       | Returns boolean - is the container empty?                 |
| `insert`                      | Insert an element into the container                      |
| `operator<` and `operator<=`  | Returns boolean - compare contents of 2 containers        |
| `operator>` and `operator>=`  | Returns boolean - compare contents of 2 containers        |
| `operator==` and `operator!=` | Returns boolean - are the contents of 2 containers equal? |
| `swap`                        | Swap the elements of 2 containers                         |
| `erase`                       | Remove element(s) from a container                        |
| `clear`                       | Remove all elements from a container                      |
| `begin` and `end`             | Returns iterators to first or last element                |
| `rbegin` and `rend`           | Returns reverse iterators to the first or last element    |
| `cbegin` and `cend`           | Returns constant iterators to first or last element       |
| `crbegin` and `crend`         | Returns constant reverse iterators to first or            |

What types of the elements will be stored in the container?

- A **copy** of the elements will be stored in the container
    - All primitives OK
- Elements should be
    - Copyable and assignable (copy constructor / copy assignment)
    - Moveable for efficiency (move constructor / move assignment)
- Ordered associative containers must be able to compare elements
    - `operator<`, `operator==`, ...

## Iterators

- Allows abstracting an arbitrary container as a sequence of elements
- The are objects that work like pointers by design
- Most container classes can be traversed with iterators

### Declaring iterators

Iterators must be declared based on the container type they will iterate over

```c++
std::vector<int>::iterator it1;
std::list<std:.string>::iterator it2;
std::map<std::string, int>::iterator it3;
std::set<char>::iterator it4;
```

### `begin` and `end` methods

```c++
std::vector<int> vec {1, 2, 3};
```

`vec.begin()`: **first** element  
`vec.end()`: location **after** last element

```c++
std::vector<int>::iterator it = vec.begin();
// or 
auto it = vec.begin();
```

### Operators with iterators

`std::vector<int>::iterator it = vec.begin()`

|                      Operation                      | Description               | Type of iterator |
|:---------------------------------------------------:|:--------------------------|:-----------------|
|                       `++it`                        | Pre-increment             | All              |
|                       `it++`                        | Post-increment            | All              |
|                     `it = it1`                      | Assignment                | All              |
|                        `*it`                        | Dereference               | Input and Output | 
|                       `it->`                        | Arrow Operator            | Input and Output | 
|                     `it == it1`                     | Comparison for equality   | Input            |
|                     `it != it1`                     | Comparison for inequality | Input            |
|                       `--it`                        | Pre-decrement             | Bidirectional    |
|                       `it--`                        | Post-decrement            | Bidirectional    |
|                  `it + i`,`it - i`                  | Increment and decrement   | Random Access    |
| `it < it1`, `it <= it1`<br/>`it > it1`, `it >= it1` | Comparison                | Random Access    |

```c++
std:.vector<int> vec {1, 2, 3};

std::vector<int>::iterator it = vec.begin();

while (it != vec.end()) {
    std::cout << *it << " ";
    ++it;
}
// 1 2 3

for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << " ";
}
// 1 2 3
```

**Iterators - std::set**

```c++
std::set<char> suits {'C', 'H', 'S', 'D'};

auto it = suits.begin();

while (it != suits.end()) {
    std::cout << *it << " ";
    ++i;
}
// C H S D
```

### Reverse Iterators

- Work in reverse
- Las element is the first and the first is the last
- `++` moves backwards, and `--` moves forwards

```c++
std::vector<int> vec {1, 2, 3};
std::vector<int>::reverse_iterator it = vec.begin();
while(it != vec.end()) {
    std::cout << *it << " ";
    ++i;
}
// 3 2 1 
```

## Algorithms

- STL algorithms work on sequences of container elements provided to them by an iterator.
- STL has many common and useful algorithms
- Too many to describe in this section
    - https://en.cppreference.com/w/cpp/algorithm
- Many algorithms require extra information in order to do their work
    - Functors (function objects)
    - Function pointers
    - Lambda expressions `C++`

```c++
#include <algorithm>
```

- Different containers support different types of iterators
    - Determines the types of algorithms supported
- All STL algorithms expect iterators as arguments
    - Determines the sequence obtained from the container

### Iterator Invalidation

- Iterators point to container elements
- It's possible iterators become invalid during processing

> Suppose we are iterating over a vector of 10 elements, and we clear() the vector while iterating. This would cause
> undefined behaviour. Our iterators would be pointing to invalid locations.

### Algorithm - `find`

The `find` algorithm tries to locate the first occurrence of an element in a container. There are lots of variations.
Returns an iterator pointing to the located element or `end()`.

```c++
std::vector<int> vec {1, 2, 3};

auto loc = std::find(vec.begin(), vec.end(), 3);

if (loc != vec.end())
    std::cout << *loc << std::endl; // 3
```

**`find` needs to be able to compare objects, `operator==` is used and must be provided by the class**
```c++
std:.vector<Player> team {/* . . . */};
Player p {"Hero", 100, 20};

auto loc = std::find(team.begin(), team.end(), p);

if (loc != vec.end())
    std::cout << *loc << std::endl;
```

### Algorithms - `for_each`
- Applies a function to each element in the iterator sequence.
- Functions must be provided to the algorithm as:
  - Functor(function object)
  - Function pointer
  - Lambda expression (C++)

**Functors**
```c++
struct Square_Functor {
    void operator() (int x) {// overload () operator
        std::cout << x * x << " ";
    }
};

Square_Functor square;  
std::vector<int> vec {1, 2, 3, 4};

std::for_each(vec.begin(), vec.end(), square);
// 1 4 9 16
```
**Function Pointer**
```c++
void square(int x) {
    std::cout << x * x << " ";
}

std::vector<int> vec {1, 2, 3, 4};

std::for_each(vec.begin(), vec.end(), square);
// 1 4 9 16
```

**Lambda Expression**
```c++
std::vector<int> vec {1, 2, 3, 4};

std::for_each(vec.begin(), vec.end(), 
              [](int x) {std::cout << x * x << " ";}
              )
// 1 4 9 16
```
## Sequence Containers

### Sequence Container - Array
`std::array` 'C++11'














