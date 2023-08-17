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

---
## Required Header
To use _Smart Pointers_ we must include the `<memory>` header.
```c++
#include <memory>
```
---


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
- The resource is acquired in a constructor

Resource Relinquishing  
Happens in the destructor
- Close file
- Deallocate Memory
- Release the lock


## Unique Pointer `unique_ptr<T>`

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


### Creating, Initializing and Using `unique_ptr`
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

## Shared Pointers `shared_ptr<T>`

Provides shared ownership of heap objects.

- Points to an object of type `T` on the heap.
- It is not unique - there can be many `shared_ptr`s pointing to the same object on the heap.
- Establishes **shared ownership** *relationship*
- _CAN_ be assigned and copied
- _CAN_ be moved
- Doesn't support managing arrays by default
- When the use *count is zero*, the managed object on the heap is *destroyed*
- 
### Creating, Initializing and Using `shared_ptr`
```c++
{
    std::shared_ptr<int> p1 {new int {100}};
    
    std::cout << *p1 << std::endl;  // 100
    
    *p1 = 200;
    
    std::cout << *p1 << std:.endl;  // 200
    
    std::cout << p1.use_count() << std::endl;   // 1
    
    std::shared_ptr<int> p2 {p1};   // shared ownership
    std::cout << p1.use_count() << std::endl;   // 2
    
    p1.reset();     // decrement the use_count; p1 is nulled out
    std::cout << p1.use_count() << std::endl;   // 0
    std::cout << p2.use_count() << std::endl;   // 1
} // automatically deleted
```

- `shared_ptr<T>.use_count()`: Returns the number of `shared_ptr` objects managing the heap object.
- `shared_ptr<T>.reset()`: decrements the `use_count` and sets the pointer to nullptr.


**User defined Classes**
```c++
{
    std::shared_ptr<Account> p1 {new Account{"Larry"}};
    
    p1->deposit(100);
    p1->withdraw(50);
}
```

**Vectors and Move**
```c++
{
    std::vector<std::shared_ptr<int>> vec;
    std::shared_ptr<int> ptr = {new int {100}};
    
    vec.push_back(ptr); // OK - copy IS allowed
    
    std::cout << ptr.use_count() << std::endl;  // 2
}
```

### `make_shared` C++14
```c++
{
    std::shared_ptr<int> p1 = std::make_shared<int>(100);   // use_count: 1
    std::shared_ptr<int> p2 {p1};   // use_count: 2
    std::shared_ptr<int> p3;
    p3 = p1;        // use_count: 3
}
```
- Use `std::make_shared`, it's more efficient.
- All 3 pointers point to the SAME object on the heap.
- When the `use_count` becomes 0 the heap object is deallocated

## Weak Pointer `weak_ptr<T>`
Provides a non-owning "weak" reference.
- Points to an object of type `T` on the heap
- Does not participate in owning relationships
- Always created from a [`shared_ptr`](#shared-pointers-sharedptrt)
- Does **NOT** increment or decrement reference `user_count`
- Used to prevent strong reference cycles which could prevent objects from being deleted.

### Circular or Cyclic References*  
- A refers to B
- B refers to A
- Shared Strong ownership prevents heap de-allocation.

Solution: Make one of the pointers non-owning or 'weak'. Now heap storage is deallocated properly


## Custom Deleters
Sometimes when we destroy a smart pointer we need more than to just destroy the object on the heap.  
These are special use-cases.  
C++ Smart pointers allow us to provide custom deleters, by using Functions, Lambdas, other...

### Custom Deleters - Functions
```c++
void my_deleter(Some_class *raw_pointer) {
    // you custom deleter code 
    delete raw_pointer;
}

std::shared_ptr<Some_class> ptr {new Some_class{}, my_deleter};
```

Using _Test_
```c++
void my_deleter(Test* ptr) {
    std::cout << "In my custom function deleter" << std::endl;
    delete ptr;
}

std::shared_ptr<Test> ptr { new Test{}, my_deleter };
```

### Custom Deleters - Lambda
```c++
std::shared_ptr<Test> ptr (new Test{100}, [] (Test *ptr) {
    std:.cout << "\tUsing my custom Lambda deleter"
    delete ptr;
})
```



