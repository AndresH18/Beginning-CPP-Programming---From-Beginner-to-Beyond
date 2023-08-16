#include <iostream>
#include <vector>
#include "Test.h"

int main() {
    Test t1{10};
    Test* ptr_t1 = new Test{20};
    delete ptr_t1;

    std::unique_ptr<Test> ptr_ut1{new Test{30}};
    std::unique_ptr<Test> ptr_ut2 = std::make_unique<Test>(40);

    std::unique_ptr<Test> ptr_ut3;
//    ptr_ut3 = ptr_t1; // Error - cannot assign
    std::cout << "ptr_ut1.get(): " << ptr_ut1 << std::endl;
    ptr_ut3 = std::move(ptr_ut1);
    std::cout << "ptr_ut1.get(): " << ptr_ut1 << std::endl;
    std::cout << "ptr_ut3.get(): " << ptr_ut3 << std::endl;

    std::vector<std::unique_ptr<Test>> tests;
    tests.push_back(std::make_unique<Test>(100));
    tests.push_back(std::make_unique<Test>(200));
    tests.push_back(std::make_unique<Test>(300));
    tests.push_back(std::make_unique<Test>(400));

    for (const auto& test: tests) {
        std::cout << "Test[" << test << "]: data=" << test->get_data() << std::endl;
//        const Test* t = test.get();
//        t->set_data(1);
        // when using smart pointers, 'const' prevents the pointer from being modified,
        // NOT the data being pointed to. To enforce 'const' on the object, we must access it
        // using pointers marked with 'const'
    }


    return 0;
}
