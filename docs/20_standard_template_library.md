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

## IMPORTANT NOTE ABOUT CLASSES

All custom classes must implement at least `operator<` and `operator==` in order to
use [Sequence Containers](#sequence-containers), [Associative Containers](#associative-containers)
and [Adapters](#stl-adapters)

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

### Sequence Container - Array (C++)

`std::array`

`#include <array>`

- Fixed size. Size must be known at compile time.
- Direct element access
- Provides access to the underlying raw array
- Use instead of raw arrays when possible
- All iterators are available and do not invalidate

```c++
#include <array>

// in C++11, we need to use double initialization list.
//std::array<int, 5> arr1 { {1, 2, 3, 4, 5} };
// in C++14+ we only need one initialization list
std::array<int, 5> arr1 {1, 2, 3, 4, 5};

std::array<std::string, 3> stoogers {
    std::string{"Larry"},
    "Moe",
    std::string{"Curly"}
};

arr1 = {2, 4, 6, 8, 10};
```

**Common methods**

```c++
std::array<int, 5> arr {1, 2, 3, 4, 5};

std::cout << arr.size();    // 5

std::cout << arr.at(0);     // 1
std::cout << arr[1];        // 2

std::cout << arr.front();   // 1
std::cout << arr.back();    // 5

std::cout << arr.empty();   // 0 (false)
std::cout << arr.max_size();// 5

std::array<int, 5> arr1 {10, 20, 30, 40, 50};
arr.swap(arr1);             // swap the 2 arrays

int* data = arr.data();     // get raw array address
```

### Sequence Container - Vector

`#include <deque>` & `std::vector<T>`

- Dynamic size
    - Handled automatically
    - Can expand and contract as needed
    - Elements are stored in contiguous memory as an array
- Direct element access (constant time)
- Rapid insertion and deletion at the back (constant time)
- Insertion or removal of elements (linear time)
- All iterators are available and may *invalidate*

```c++
#include <vector>

std::vector<int> vec {1, 2, 3};

vec.front();    // 1 - first element
vec.back();     // 3 - last element

vec.push_back(4); // add element to the end of vector
```

```c++
std::vector<int> vec {1, 2, 3, 4, 5};
std::vector<int> vec1 (10, 100);    // ten 100s

std::vecto<std::string> stooges {
    std::string {"Larry"},
    "Moe",
    std::string {"curly"}
};
vec1 = {2, 4, 6, 8, 10};
```

```c++
std::vector<int> vec {1, 2, 3, 4, 5};

std::cout << vec.size();    // 5
std::cout << vec.capacity();// 5
std::cout << vec.max_size();// a very large number

std::cout << vec.at(0);     // 1 
std::cout << vec[1];        // 2 

std::cout << vec.front();   // 1
std::cout << vec.back();    // 5

std::vector<Person> vec1;
Person p1 {"Andres", 23};

vec1.push_back(p1);     // add p1 to the back
vec1.pop_back();        // remove p1 from the back

vec.push_back(Person{"David", 22}); // create object and pass it

vec.emplace_back("David", 22); // create object in place using move semantics - pass object constructor parameters
```

```c++
std:.vector<int> vec1 {1, 2, 3, 4, 5};
std:.vector<int> vec1 {10, 20, 30, 40, 50};

std::cout << vec1.empty();  //0 (false)
vec1.swap(vec2);        // swaps the 2 vectors

std::sort(vec1.begin(), vec1.end());

auto it = std::find(vec1.begin(), vec1.end(), 3);
vec1.insert(it, 10);    // 1, 2, 10  , 3, 4, 5

it = std::find(vec1.begin(), vec1.end(), 4);
vec1::insert(it, vec2.begin(), vec2.end());
    // 1, 2, 10, 3, 10, 20, 30, 40, 50, 4, 5
```

### Sequence Containers - Deque

`#include <deque>` & `std::deque<T>`

- Dynamic Size
    - Handled automatically
    - Can expand and contract as needed
    - Elements are **NOT** stored in contiguous memory
- Direct element access (constant time)
- Rapid insertion and deletion at the front **and** back (constant time)
- Insertion or removal of elements (linear time)
- All iterators available and may invalidate

```c++
std::deque<int> d{1, 2, 3, 4, 5};
std::deque<int> d1(10,100); // ten 100s

std::deque<std::string> stooges {
    std:.string{"Larry"},
    "Moe",
    std::string("Curly")
};

d = {2, 4, 6, 8, 10};
d.front();      // 1
d.back();      // 10
d.push_back(12);    // 2, 4, 6, 8, 10, 12
d.push_front(1);    // 1, 2, 4, 6, 8, 10, 12

d = {1, 2, 3, 4, 5};

std::cout << d.size();  // 5
std::cout << d.max_size();  // a very large number

std::cout << d.at(0);   // 1
std::cout << d[1];   // 2
```

```c++
Person p1 {"Andres", 23};
std::deque<Person> d;

d.push_back(p1);    // add p1 to the back
d.pop_back();       // remove p1 from the back

d.push_front(Person{"David", 20}); // create and insert
d.pop_front();      // remove element from the front

d.emplace_back("David", 20);    // create at back
d.emplace_front("Andres", 23);  // create at front
```

### Sequence Containers - List & Forward List

[`std::list<T>`](#list) & [`std::forward_list<T>`](#forward-list)

- Sequence containers
- Non-contiguous memory
- No direct access to elements
- Very efficient for inserting and deleting elements once element is found

#### List

`#include <list>` & `std::list<T>`

- Dynamic size
    - List of elements
    - `list` is bidirectional (doubly-linked)
- Direct element access is **not** provided
- Rapid insertion and deletion of elements anywhere in the container (constant time) _after element is found_
- All iterators available and **invalidate** when corresponding element is deleted

```c++
std::list<int> l{1, 2, 3, 4, 5};
std::list<int> l1(10,100); // ten 100s

std::list<std::string> stooges {
    std:.string{"Larry"},
    "Moe",
    std::string("Curly")
};

l = {2, 4, 6, 8, 10};

std::cout << l.size();  // 5
std::cout << l.max_size(); // a very large number
std::cout << l.front(); // 1
std::cout << l.back();  // 10
```

```c++
Person p1 {"Andres", 23};
std::list<Person> l;

l.push_back(p1);    // add p1 to the back
l.pop_back();       // remove p1 from the back

l.push_front(Person{"David", 20}); // create and insert
l.pop_front();      // remove element from the front

l.emplace_back("David", 20);    // create at back
l.emplace_front("Andres", 23);  // create at front
```

```c++
std::list<int> l {1, 2, 3, 4, 5};
auto it = std::find(l.begin(), l.end(), 3);

l.insert(it, 10);   // 1 2 10 3 4 5

l.erase(it);        // erase the 3, 1 2 10 4 5

l.resize(2);        // 1 2

l.resize(5);        // 1 2 0 0 0
```

**Traversing the List**

```c++
std::list<int> l {1, 2, 3, 4, 5};
auto it = std::find(l.begin(), l.end(), 3);

std:.cout << *it;   // 3
it++;
std::cout << *it;   // 4
it--;
std::cout << *it;   // 3
```

#### Forward List

`#include <forward_list>` & `std::forward_list`

- Dynamic size
    - List of elements
    - `forward_list` is uni-directional (singly-linked)
    - Less overhead than [`std::list`](#list)
- Direct element access is **NOT** provided
- Rapid insertion and deletion of elements anywhere in the container (constant time) _after the element is found_
- Reverse iterators are **NOT** available. Iterators invalidate when corresponding element is deleted.

```c++
std::forward_list<int> l {1, 2, 3, 4, 5};

l = {2, 4, 6, 8, 10};

//std::cout << l.size();  // NOT AVAILABLE
std::cout << l.max_size(); // a very large number
std::cout << l.front(); // 1
//std::cout << l.back();  // NOT AVAILABLE
```

```c++
Person p1 {"Andres", 23};
std::forward_list<Person> l;

l.push_front(p1);   // add p1 to the front
l.pop_front();      // remove p1 from the front

l.emplace_front("Andres", 23);  // create at front
```

```c++
std::forward_list<int> l {1, 2, 3, 4, 5};
auto it = std::find(l.begin(), l.end(), 3);

l.insert_after(it, 10);     // 1 2 3 10 4 5
l.emplace_after(it, 100);   // 1 2 3 100 10 4 5

l.erase_after(it);  // erases the 100 - 1 2 3 10 4 5

l.resize(2);        // 1 2

l.resize(5);        // 1 2 0 0 0
```

## Associative Containers

### Associative Containers - Set

`#include <set>`

- Collection of stored objects that allow fast retrieval using a key
- STL provides Sets and Maps
- Usually implemented as balanced binary tree or hashsets
- Most operations are very efficient


- `std::set`
    - Similar to a mathematical set
    - Ordered by key
    - No duplicate elements
    - All iterators available and invalidate when corresponding element is deleted
    - ```c++
      std::set<int> s {1, 2, 3, 4, 5, 2, 3, 5}; // 1 2 3 4 5
      s = {2, 4, 6, 8, 10};
    
      std::cout << s.size();  // 5
      std::cout << s.max_size();  // a very large number
    
      s.insert(6);    // 1 2 3 4 5 6
      auto result = s.insert(7);    // 1 2 3 4 5 6 7
      // returns a std::pair<iterator, bool>, 
      // an iterator to the element just inserted to the duplicate, 
      // the boolean indicates if the operation was successful
    
    
      s.erase(3); // erase 3 from set - 1 2 4 5 6 7
    
      auto it = s.find(5);
      if (it != s.end())
        s.erase(it);  // erase 5

      // . . .  
      s = {1, 2, 3, 4, 5};
      int num = s.count(2); // returns 0 or 1 if element is found in set
      
      s.clear();  // remove all items
      s.empty();  // true or false
      
      ```
    - No concept of front or back
- `std::multiset`
    - Sorted by key
    - Allows duplicate elements
    - All iterators are available
    -
- `std::unordered_set`
    - Elements are unordered
    - No duplicate elements allowed
    - Elements cannot be modified
        - Must be erased and new element inserted
    - No reverse iterators are allowed
- `std::unordered_multiset`
    - Elements are unordered
    - Allows duplicate elements
    - No reverse iterators are allowed

### Associative Containers - Maps

`#include <map>`

- `std::map`
    - Similar to a dictionary
    - Elements are stores as _Key_, _Value_ pairs (`std::pair`)
    - Ordered by key
    - No duplicate elements (Keys are unique)
    - Direct element access using the key
    - All iterators available and invalidate when corresponding element is deleted
    - ```c++
      std::map<std::string, int> m1 { 
        {"Andres", 23},
        {"David", 22}
      };
            
      std::map<std::string, std::string> m { 
        {"Bob", "Butcher"},
        {"Anne", "Baker"},
        {"George", "Candlestick maker"}
      };
      
      std::cout << m.size();      // 3
      std::cout << m.max_size();  // a very large number
      
      
      std::pair<std::string, std::string> p1 {"Andres", "Player"};
      m.insert(p1);
      m.insert(std::make_pair("David", "Ranger"));
      m["Frank"] = "Teacher";       // insert
      m["Frank"] = "Instructor";    // update value
      m.at("Frank") = "Professor";  // update value
      // std::map::at will throw an exception if element is not found
      // std::map::[] will not throw an exception
      
      m.erase("Anne");      // erase Anne
      
      if (m.find("Bob") != m.end()) // find bob 
        std::cout << "Found Bob!";
      
      auto it = m.find("George");
      if (it != m.end())
        m.erase(it);        // erase George
      
      int num = m.count("Bob");  // returns 0 or 1 if element is key in set
      
      m.clear();        // remove all elements
      
      m.empty();        // true or false
      ```

- `std::multimap`
    - Ordered by key
    - Allows duplicate elements
    - All iterators are available
- `std::unordered_map`
    - Elements are unordered
    - No duplicate elements allowed
    - No reverse iterators are allowed
- `std::unordered_multimap`
    - Elements are unordered
    - Allows duplicate elements
    - No reverse iterators are allowed

## STL Adapters

### STL Adapter Container - Stack

`#include <stack>` & `std::stack`

- Last-In First-Out (LIFO) data structure
- Implemented as an adapter over other STL container
    - Can be implemented as
      a [vector](#sequence-container---vector), [list](#sequence-containers---list--forward-list), [deque](#sequence-containers---deque)
- All operations occur on one end of the stack(top)
- No iterators are supported

#### Stack - Methods

| Method  | Description                                 |
|---------|---------------------------------------------|
| `push`  | Insert an element at the top of the stack   |
| `pop`   | Remove an element from the top of the stack |
| `top`   | Access the top element of the stack         |
| `empty` | Is the stack empty?                         |
| `size`  | Number of elements in the stack             |

#### Stack - Initialization

| Declaration                             | Underlying type                                   |
|-----------------------------------------|---------------------------------------------------|
| `std::stack<int> s;`                    | [deque](#sequence-containers---deque)             |
| `std::stack<int, std::vector<int>> s1;` | [vector](#sequence-container---vector)            |
| `std::stack<int, std::list<int>> s2;`   | [list](#sequence-containers---list--forward-list) |
| `std::stack<int, std::deque<int>> s3;`  | [deque](#sequence-containers---deque)             |

### STL Adapter Container - Queue

`#include <queue>` & `std::queue`

- First-In First-Out (FIFO) data structure
- Implemented as an adapter over other STL container
    - Can be implemented as a [list](#sequence-containers---list--forward-list) or [deque](#sequence-containers---deque)
- Elements are pushed to the back and popped from the front
- No iterators are supported

#### Queue - Methods

| Method  | Description                                   |
|---------|-----------------------------------------------|
| `push`  | Insert an element at the top of the queue     |
| `pop`   | Remove an element from the start of the queue |
| `front` | Access the element  at the front              |
| `back`  | Access the element at the back                |
| `empty` | Is the queue empty?                           |
| `size`  | Number of elements in the queue               |

#### Stack - Initialization

| Declaration                            | Underlying type                                   |
|----------------------------------------|---------------------------------------------------|
| `std::queue<int> s;`                   | [deque](#sequence-containers---deque)             |
| `std::queue<int, std::list<int>> s2;`  | [list](#sequence-containers---list--forward-list) |
| `std::stack<int, std::deque<int>> s3;` | [deque](#sequence-containers---deque)             |

### STL Adapter Container - Priority Queue

`#include <queue>` & `std::queue`

- Allows insertions and removal of elements in order from the front of the container
- Elements are stored internally as a vector by default
- Elements are inserted in **priority** order (largest value will always be at the front)
- No iterators are supported

#### Queue - Methods

| Method  | Description                              |
|---------|------------------------------------------|
| `push`  | Insert an element into sorted order      |
| `pop`   | Remove the top element (greatest)        |
| `top`   | Access the top element (greatest)        |
| `empty` | Is the priority queue empty?             |
| `size`  | Number of elements in the priority queue |

#### Stack - Initialization

| Declaration                            | Underlying type                                   |
|----------------------------------------|---------------------------------------------------|
| `std::queue<int> s;`                   | [deque](#sequence-containers---deque)             |
| `std::queue<int, std::list<int>> s2;`  | [list](#sequence-containers---list--forward-list) |
| `std::stack<int, std::deque<int>> s3;` | [deque](#sequence-containers---deque)             |





