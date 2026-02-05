#include <iostream>
#include "Sample.class.hpp"

Sample::Sample ( void ){
    
    std::cout << " Sample construit " << std::endl;
    return;
}

Sample::~Sample ( void ){
    std::cout << " Sample Deconstruit " << std::endl;
    return;
}
