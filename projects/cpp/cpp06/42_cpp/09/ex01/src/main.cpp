/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:16 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <sstream>

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong number of parameters" << std::endl;
		return 0;
	}

	std::stringstream	stream(argv[1]);
	std::string			word;
	std::string			operators("+-*/");
	RPN					myOperation;
	try {
		while (stream >> word) {
			if (word.length() == 1) {
				if (operators.find(word.at(0)) != std::string::npos) {
					myOperation.operate(word.at(0));
					continue;
				}
				else if (!isdigit(word.at(0)))
					throw RPN::Exception(word + " is incorrect");
			}

			char *endPtr;
			double number = strtod(word.c_str(), &endPtr);
			if (*endPtr != '\0')
				throw RPN::Exception(word + " is incorrect");
			if (errno == ERANGE)
				throw RPN::Exception(word + " is too big");
			if (static_cast<long>(static_cast<int>(number)) != number)
				throw RPN::Exception(word + " is not an integer");

			myOperation.addNumber(number);
		}
		if (myOperation.getSize() == 0)
			throw RPN::Exception("no number");
		std::cout << static_cast<int>(myOperation.getResult()) << std::endl;
	}
	catch (RPN::Exception const & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "System error" << std::endl;
	}
	
	return 0;
}
