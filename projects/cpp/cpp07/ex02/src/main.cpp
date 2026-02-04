#include <iostream>
#include <exception>
#include <Array.hpp>
#include <cstdlib>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> empty;
    std::cout << "Empty array: Size: " << empty.size() << std::endl;
    
    try {
        empty[0] = 0;
    }
    catch(const std::exception& e) {
        std::cout << "Empty array exception: ";
        std::cerr << e.what() << std::endl;
    }


    std::cout << "\nArray with size [10]:" << std::endl;
    Array<int> intArray(10);
    std::cout << "Before: " << intArray << std::endl;
    
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 2;
    
    std::cout << "After:  " << intArray << std::endl;

    
    std::cout << "\nAssignment operator:" << std::endl;
    Array<int> intArray2(5);
    std::cout << "Array2 before: " << intArray2 << std::endl;
    
    intArray2 = intArray;
    std::cout << "Array2 after:  " << intArray2 << std::endl;


    std::cout << "\nDeep copy:" << std::endl;
    intArray2[0] = 999;
    std::cout << "Array1[0]: " << intArray[0] << std::endl;
    std::cout << "Array2[0]: " << intArray2[0] << std::endl;


    std::cout << "\nCopy constructor + destructor:" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand() % 10;
        numbers[i] = value;
        mirror[i] = value;
    }
    
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }  // tmp/test destroyed here
    
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "Copy constructor + destructor exception: didn't save the same value" << std::endl;
            delete [] mirror;
            return 1;
        }
    }
    std::cout << "Deep copy test passed!" << std::endl;


    std::cout << "\nOut of bounds exceptions:" << std::endl;
    try {
        std::cout << "Valid access: " << numbers[5] << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Out of bounds exception : " << e.what() << std::endl;
    }
    
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Out of bounds exception : (negative index): " << e.what() << std::endl;
    }
    
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Out of bounds exception : (too large index): " << e.what() << std::endl;
    }

    delete [] mirror;

    return 0;
}