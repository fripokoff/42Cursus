/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:49:59 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.hpp"

int main( void ) {
	
	/* >------ AN ARRAY OF STRING ------< */
	std::cout << "----STRING PART----" << std::endl;
	Array<std::string> myArray(8);

	try {
		myArray[0] = "Waou";
		myArray[2] = "Impressive!";
		myArray[8] = "Index out of range";
	}
	catch (std::exception &e) {
		std::cout << "0: " << e.what() << std::endl;
	}

	try {
		std::cout << "[" << 0 << "]: " << myArray[0] << std::endl;
		std::cout << "[" << 1 << "]: " << myArray[1] << std::endl;
		std::cout << "[" << 2 << "]: " << myArray[2] << std::endl;
		std::cout << "[" << 3 << "]: " << myArray[3] << std::endl;
		std::cout << "[" << 4 << "]: " << myArray[4] << std::endl;
		std::cout << "[" << 5 << "]: " << myArray[5] << std::endl;
		std::cout << "[" << 6 << "]: " << myArray[6] << std::endl;
		std::cout << "[" << 7 << "]: " << myArray[7] << std::endl;
		std::cout << "[" << 8 << "]: " << myArray[8] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "1: " << e.what() << std::endl;
	}


	/* >------ AN ARRAY OF INT ------< */
	std::cout << "\n----INT PART----" << std::endl;
	Array<int> myIntegers(3);
	try {
		std::cout << "[" << 0 << "]: " << myIntegers[0] << std::endl;
		std::cout << "[" << 1 << "]: " << myIntegers[1] << std::endl;
		std::cout << "[" << 2 << "]: " << myIntegers[2] << std::endl;
		std::cout << "[" << 3 << "]: " << myIntegers[3] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "0: " << e.what() << std::endl;
	}

	try {
		myIntegers[0] = 1;
		myIntegers[1] = 2;
		myIntegers[2] = 3;
		myIntegers[3] = 4;
	}
	catch (std::exception &e) {
		std::cout << "1: " << e.what() << std::endl;
	}

	try {
		std::cout << "[" << 0 << "]: " << myIntegers[0] << std::endl;
		std::cout << "[" << 1 << "]: " << myIntegers[1] << std::endl;
		std::cout << "[" << 2 << "]: " << myIntegers[2] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "2: " << e.what() << std::endl;
	}
	return 0;
}
