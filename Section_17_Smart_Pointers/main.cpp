#include <iostream>
#include <memory>
#include <vector>

#include "Test.h"

void weak_function(const std::weak_ptr<Test> ptr);

void shared_function(const std::shared_ptr<Test> ptr);

int main() {
    std::cout << "=== unique_ptr ===========================================" << std::endl;

    {
        Test t1{10};
        Test* ptr_t1 = new Test{20};
        delete ptr_t1;

        std::unique_ptr<Test> ptr_ut1{new Test{30}};
        std::unique_ptr<Test> ptr_ut2 = std::make_unique<Test>(40);

        std::unique_ptr<Test> ptr_ut3;
//    ptr_ut3 = ptr_t1; // Error - cannot assign
        std::cout << "ptr_ut1.get(): " << ptr_ut1.get() << std::endl;
        ptr_ut3 = std::move(ptr_ut1);
        std::cout << "ptr_ut1.get(): " << ptr_ut1.get() << std::endl;
        std::cout << "ptr_ut3.get(): " << ptr_ut3.get() << std::endl;

        std::vector<std::unique_ptr<Test>> tests;
        tests.push_back(std::make_unique<Test>(100));
        tests.push_back(std::make_unique<Test>(200));
        tests.push_back(std::make_unique<Test>(300));
        tests.push_back(std::make_unique<Test>(400));

        for (const auto& test: tests) {
            std::cout << "Test[" << test.get() << "]: data=" << test->get_data() << std::endl;
//        const Test* t = test.get();
//        t->set_data(1);
            // when using smart pointers, 'const' prevents the pointer from being modified,
            // NOT the data being pointed to. To enforce 'const' on the object, we must access it
            // using pointers marked with 'const'
        }
    }

    std::cout << "=== shared_ptr ===========================================" << std::endl;
    {
        std::shared_ptr<int> ptr_si1{new int{100}};
        std::cout << "ptr_si1.get(): " << ptr_si1.get() << std::endl;
        std::cout << "ptr_si1.use_count(): " << ptr_si1.use_count() << std::endl;

        std::shared_ptr<int> ptr_si2{ptr_si1};
        std::cout << "ptr_si1.use_count(): " << ptr_si1.use_count() << std::endl;
        std::cout << "ptr_si2.use_count(): " << ptr_si2.use_count() << std::endl;
        std::cout << "ptr_si2.get(): " << ptr_si2.get() << std::endl;

        std::shared_ptr<Test> ptr_st1{new Test{11}};

        std::cout << "ptr_st1.get(): " << ptr_st1.get() << std::endl;
        std::cout << "ptr_st1.use_count(): " << ptr_st1.use_count() << std::endl;

        std::shared_ptr<Test> ptr_st2{ptr_st1};
        std::cout << "ptr_st1.get(): " << ptr_st2.get() << std::endl;
        std::cout << "ptr_st1.use_count(): " << ptr_st2.use_count() << std::endl;

        std::cout << "Assignment" << std::endl;

        ptr_st2 = std::make_shared<Test>(22);

        std::cout << "ptr_st1.get(): " << ptr_st1.get() << std::endl;
        std::cout << "ptr_st1.use_count(): " << ptr_st1.use_count() << std::endl;

        std::cout << "ptr_st2.get(): " << ptr_st2.get() << std::endl;
        std::cout << "ptr_st2.use_count(): " << ptr_st2.use_count() << std::endl;

        std::shared_ptr<Test> ptr_st3{std::make_shared<Test>(44)};
        std::cout << "ptr_st3.get(): " << ptr_st3.get() << std::endl;
        std::cout << "ptr_st3.use_count(): " << ptr_st3.use_count() << std::endl;

        std::cout << "Scope assignment" << std::endl;
        {
            std::shared_ptr<Test> ptr_st4{ptr_st3};

            std::cout << "ptr_st3.get(): " << ptr_st3.get() << std::endl;
            std::cout << "ptr_st3.use_count(): " << ptr_st3.use_count() << std::endl;

            std::cout << "ptr_st4.get(): " << ptr_st4.get() << std::endl;
            std::cout << "ptr_st4.use_count(): " << ptr_st4.use_count() << std::endl;
        }

        std::cout << "Outside of scope" << std::endl;

        std::cout << "ptr_st3.get(): " << ptr_st3.get() << std::endl;
        std::cout << "ptr_st3.use_count(): " << ptr_st3.use_count() << std::endl;

        shared_function(ptr_st3);

        std::cout << "ptr_st3.get(): " << ptr_st3.get() << std::endl;
        std::cout << "ptr_st3.use_count(): " << ptr_st3.use_count() << std::endl;
    }

    std::cout << "=== weak_ptr =============================================" << std::endl;
    {
        std::cout << "weak_function" << std::endl;
        std::shared_ptr<Test> ptr1 = std::make_shared<Test>(99);
        std::cout << "ptr1: " << ptr1.get() << " -> use_count:" << ptr1.use_count() << std::endl;

        weak_function(ptr1);

    }

    return 0;
}

void shared_function(const std::shared_ptr<Test> ptr) {
    using namespace std;

    cout << "Inside shared_function" << endl;
    cout << "ptr.get(): " << ptr.get() << endl;
    cout << "ptr.use_count(): " << ptr.use_count() << endl;

    cout << "Leaving shared_function" << endl;
}

void weak_function(const std::weak_ptr<Test> ptr) {
    using namespace std;

    cout << "Inside weak_function" << endl;
    cout << "weakPtr: use_count: " << ptr.use_count() << endl;


    cout << "Leaving weak_function" << endl;
}
