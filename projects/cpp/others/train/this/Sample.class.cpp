#include <iostream>
#include "Sample.class.hpp"

Sample::Sample ( void ){
    
    std::cout << " Sample construit " << std::endl;
    std::cout << " foo is :" << this->foo << std::endl;
    this->foo = 42;
    std::cout << " foo is now :" << this->foo << std::endl;
    this->pop();
    return;
}

Sample::~Sample ( void ){
    std::cout << " Sample Deconstruit " << std::endl;
    return;
}

void Sample::pop ( void ){
    std::cout << " Pop called " << std::endl;
    return;
}