#include <iostream>
#include <iomanip>

int main() {
    double num{1234.5678};
    std::string hello{"Hello"};
    std::cout << "Hello, World!" << std::endl;
    std::cout << std::setfill('*') << std::setw(10) << num
              << std::setfill('-') << std::setw(10) << std::right << hello
              << std::setw(15) << std::right << hello
              << std::endl;
    return 0;
}
