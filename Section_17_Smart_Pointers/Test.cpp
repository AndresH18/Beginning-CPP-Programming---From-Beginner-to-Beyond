//
// Created by andre on 16/08/2023.
//

#include "Test.h"

#include <iostream>

Test::Test() : Test{0} {
}

Test::Test(int data) : data{data} {
    std::cout << "Test constructor (" << data << ")" << std::endl;
}

int Test::get_data() const {
    return data;
}

void Test::set_data(int i) {
    this->data = i;
}

Test::~Test() {
    std::cout << "Test destructor (" << data << ")" << std::endl;
}