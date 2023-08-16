//
// Created by andre on 16/08/2023.
//

#ifndef SECTION_17_SMART_POINTERS_TEST_H
#define SECTION_17_SMART_POINTERS_TEST_H


class Test {
private:
    int data;
public:
    Test();

    Test(int);

    int get_data() const;
    void set_data(int);

    ~Test();
};


#endif //SECTION_17_SMART_POINTERS_TEST_H
