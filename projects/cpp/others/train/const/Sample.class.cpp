#include <iostream>
#include "Sample.class.hpp"

Sample::Sample ( const float  f) : pi(f){
    
    std::cout << " Sample construit " << std::endl;
    std::cout << f << std::endl;
    this->pop();
    return;
}

Sample::~Sample ( void ){
    std::cout << " Sample Deconstruit " << std::endl;
    return;
}

void Sample::pop ( void ){
    std::cout << " Pop called " << std::endl;
    this->qd = 0;
    return;
}