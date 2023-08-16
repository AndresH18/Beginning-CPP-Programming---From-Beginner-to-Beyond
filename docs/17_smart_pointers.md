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





