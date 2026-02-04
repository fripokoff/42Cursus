#pragma once

template <typename T>
void iter(T* array, int const length, void (*f)(T&)){
    for(int a = 0; a < length; a++)
        f(array[a]);
}

template <typename T>
void iter(T const* array, int const length, void (*f)(T const&)){
    for(int a = 0; a < length; a++)
        f(array[a]);
}