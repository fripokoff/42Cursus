/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:52:33 by kpires            #+#    #+#             */
/*   Updated: 2026/02/04 14:58:15 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template<class T, size_t N>
static size_t size(T (&)[N]) { return N; }

template <typename T>
void print(T const & x) {
    std::cout << x << std::endl;
}

template <typename T>
static void beautiful_print(T const &array, const int len){

    for (int i = 0; i < len; i++)
    {
        std::cout << array[i];
        if(i < len - 1)
            std::cout << ",";
        else
            std::cout << std::endl << std::endl;
    }
}

static void toUpperCase(std::string & content) {
    for (std::string::iterator it = content.begin(); it != content.end(); it++) {
        *it = toupper(*it);
    }
}

static void addOne(int &value){
    value++;
}

int main( void ) {
    std::cout << "--STRING TABLE--" << std::endl;
    std::string stringTable[] = {"ecole", "42", "world"};
    int stableLen = size(stringTable);

    std::cout << "Before iter :" <<std::endl;
    beautiful_print(stringTable, stableLen);

    iter(stringTable, stableLen, toUpperCase);

    std::cout << "After iter :" <<std::endl;
    beautiful_print(stringTable, stableLen);

    std::cout << "--INT TABLE--" << std::endl;
    int intTable[] = {99, 0, -1};
    int itableLen = size(intTable);

    std::cout << "Before iter :" <<std::endl;
    beautiful_print(intTable, itableLen);

    iter(intTable, itableLen, addOne);

    std::cout << "After iter :" <<std::endl;
    beautiful_print(intTable, itableLen);

    std::cout << "--CONST INT TABLE--" << std::endl;
    int const tab[] = {0, 1, 2, 3, 4};
    iter(tab, 5, print<>);

    std::cout << "--FUNCTION TAKING CONST REFERENCE--" << std::endl;
    int normalArray[] = {10, 20, 30};
    iter(normalArray, 3, print<int>);

    return 0;
}