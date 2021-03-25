#include <iostream>

// option1
// float add(float a, float b);
#include "Adder/adder.h"

int main()
{
    std::cout << "hello form CMake Tutorial EP2 |Libaries and Subdirectories\n"; 
    std::cout << add(100.1f ,150.2f)<< '\n';
    return 0;
}