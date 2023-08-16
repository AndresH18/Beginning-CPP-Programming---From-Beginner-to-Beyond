# Smart Pointers

## Some Issues with Raw Pointers
C++ provides absolute flexibility with memory management. Allocation, Deallocation, Lifetime management

Some potentially serous problems are: Uninitialized (wild) pointers, memory leaks, dangling pointers, Not exception safe.

Ownership: Who owns the pointer?, When should a pointer be deleted?


## What are Smart Pointers
- Objects
- Can only point to heap allocated memory
- Automatically call delete when no longer needed
- Adhere to RAII principles
- C++ Smart Pointers
  - Unique Pointers (`unique_ptr`)
  - Shared Pointers (`shared_ptr`)
  - Weak pointers (`weak_ptr`)
  - Auto pointers (`auto_ptr`) **DEPRECATED** 


```c++
#include <memory>
```

Defined by class Templates
- Wrapper around a raw pointer
- Overloaded operators
  - Dereference(`*`)
  - Member selection (`->`)
  - Pointer arithmetic not supported (`--`,`++`, etc.)
- Can have custom deleters


```c++
#include <memory>

{
    std::smart_pointer<Some_class> ptr = . . .;
    
    ptr->method();
    std::cout << (*ptr) << endl;
    
    // ptr will be destroyed automatically when no longer needed     
}
```

### RAII - Resource Acquisition Is Initialization

Common idiom or pattern used in software design based on container object lifetime

RAII objects are allcoated on the stack

Resource Acquisition
- Open a file
- Allocate memory
- Acquire a lock

Is Initialization
- The resource is acuired in a constructor

Resource Relinquishing  
Happens in the destructor
- Close file
- Deallocate Memory
- Release the lock


## Unique Pointer

```c++
unique_ptr
```

Simple smart pointer - Very Efficient.

`unique_ptr<T>`
- Points to an object of type `T` on the heap
- It is unique - there can only be one `unique_ptr<T>` pointing to the object on the heap
- Owns what it points to
- Cannot be assigned or copied, *their copy and move constructors are unavailable*
- **CAN** be moved
- When the pointer is destroyed, what it points to is automatically destroyed.


### Creating, Initializing and using unique_ptr
```cpp
{
    std::unique_ptr<int> p1 {new int{100}};
    std::cout << *p1 << std::endl;  // 100
    
    *p1 = 200;
    
    std::cout << *p1 << endl;       // 200
}// automatically deleted
```
**Some other useful methods**
```c++
{
    std::unique_ptr<int> p1 {new int{100}};
    std::cout << p1.get << std::endl;   // 0x543476
    
    p1.reset();     // p1 is not nullptr
    
    if (p1) // check if not nullptr
        std::cout << *p1 << std::endl;  // won't execute
}// automatically deleted
```
- `p1.get()` returns a pointer to the object in the heap
- `p1.reset()` set the pointer to nullptr and the memory it points to is released

**User defined classes**
```c++
{
    std::unique_ptr<Account> p1 {new Account {"Andres"}};
    std::cout << *ptr << std::endl; // display account
    
    p1->deposit(1000);
    p1->withdraw(500);
}// automatically deleted
```
**Vectors and move**
```c++
std::vector<std::unique_ptr<int>> vec;

std::unique_ptr<int> ptr {new int{100}};

vec.push_back(ptr); // Error - copy not allowed

vec.push_back(std::move(ptr));
```

`std::move(ptr)` ptr gives up ownership of the pointer, and it's moved to the vector. The vector now owns the pointer, and ptr will be set to nullptr.  
When the vector goes out of scope it will deallocate all its elements and the integer in the heap will be de-allocated correctly.

### `make_unique` (C++14)
More efficient, no calls to `new` or `delete` 
```c++
{
    std::unique_ptr<int> p1 = std::make_unique<int>(100);
    
    std::unique_ptr<Account> p2 = std::make_unique<Account>("Andres", 5000);
    
    auto p3 = make_unique<Player>("Hero", 100, 100);
} // automatically deleted
```









