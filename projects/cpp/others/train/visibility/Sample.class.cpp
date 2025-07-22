#include <iostream>
#include "Sample.class.hpp"

Sample::Sample ( void ) {

    std::cout << " Sample construit " << std::endl;
    this->pubFoo = 0;
    std::cout << " pubFoo " <<  this->pubFoo  << std::endl;
    this->_privFoo = 0;
    std::cout << " _privFoo " <<  this->_privFoo  << std::endl;
    this->_privPop();
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

void Sample::_privPop ( void ) const {
    std::cout << " _privPop called " << std::endl;
}