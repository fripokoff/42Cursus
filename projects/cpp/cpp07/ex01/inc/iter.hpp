#pragma once

#include <iostream>

template<class T, size_t N>
size_t size(T (&)[N]) { return N; }

template <typename T>
void iter(T* array, int const length, void (*f)(T&)){
    for(int a = 0; a < length; a++)
        f(array[a]);
    std::cout << "Porte 1\n";
}

template <typename T>
void iter(T const* array, int const length, void (*f)(T const&)){
    for(int a = 0; a < length; a++)
        f(array[a]);
    std::cout << "Porte 2\n";
}

template <typename T>
void print(T const & x) {
    std::cout << x << std::endl;
}

template <typename T>
void beautiful_print(T const &array, const int len){

    for (int i = 0; i < len; i++)
    {
        std::cout << array[i];
        if(i < len - 1)
            std::cout << ",";
        else
            std::cout << std::endl << std::endl;
    }
}