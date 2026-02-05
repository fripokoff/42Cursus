/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:52:33 by kpires            #+#    #+#             */
/*   Updated: 2026/02/05 14:23:20 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

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
    int tableLen = size(tab);
    iter(tab, tableLen, print<>);

    std::cout << "--FUNCTION TAKING CONST REFERENCE--" << std::endl;
    int normalArray[] = {10, 20, 30};
    int nmtableLen = size(normalArray);
    iter(normalArray, nmtableLen, print<const int>);

    return 0;
}