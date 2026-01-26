/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:36:11 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#include "ScalarConverter.hpp"

static int getType(std::string &literal) {
	if (literal.length() == 1 && isascii(literal.at(0)))
		return CHAR;

	if (literal == "nan" || literal == "-inf" || literal == "+inf")
		return DOUBLE_EXCEPTION;

	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		return FLOAT_EXCEPTION;

	for (std::string::iterator it = literal.begin(); it != literal.end(); it++) {
		if (isdigit(*it) || *it == '.')
			continue;
		if (*it == 'f' && it + 1 == literal.end())
			return FLOAT;
		return NONE;
	}

	if (literal.find('.') == std::string::npos)
		return INT;
	if (literal.find('.') == literal.rfind('.'))
		return DOUBLE;

	return NONE;
}


/* >----------- String->Double conversion -----------< */
static void printScalar(t_scalar *nb);
static void charString(std::string &literal) {
	t_scalar number = {
		literal.at(0),
		static_cast<int>(literal.at(0)),
		static_cast<float>(literal.at(0)),
		static_cast<double>(literal.at(0)),
		NO_OVERFLOW
	};

	printScalar(&number);
}
static void intString(std::string &literal) {
	long i = strtol(literal.c_str(), NULL, 10);
	if (i > static_cast<long>(std::numeric_limits<int>::max())
		|| i < static_cast<long>(std::numeric_limits<int>::min()))
		throw ScalarConverter::Overflow("Int");

	t_scalar number = {
		static_cast<char>(i),
		static_cast<int>(i),
		static_cast<float>(i),
		static_cast<double>(i),
		((i > static_cast<long>(std::numeric_limits<char>::max())
		|| i < static_cast<long>(std::numeric_limits<char>::min())) * CHAR_OF)
		+ ((i > static_cast<long>(std::numeric_limits<int>::max())
		|| i < static_cast<long>(std::numeric_limits<int>::min())) * INT_OF)
		+ (false * FLOAT_OF) + (false * DOUBLE_OF)
	};

	printScalar(&number);
}
static void floatString(std::string &literal) {
	double f = strtod(literal.c_str(), NULL);
	if (f > static_cast<double>(std::numeric_limits<float>::max())
		|| f < static_cast<double>(std::numeric_limits<float>::min()))
		throw ScalarConverter::Overflow("Float");

	t_scalar number = {
		static_cast<char>(f),
		static_cast<int>(f),
		static_cast<float>(f),
		f,
		((f > static_cast<double>(std::numeric_limits<char>::max())
		|| f < static_cast<double>(std::numeric_limits<char>::min())) * CHAR_OF)
		+ ((f > static_cast<double>(std::numeric_limits<int>::max())
		|| f < static_cast<double>(std::numeric_limits<int>::min())) * INT_OF)
		+ ((f > static_cast<double>(std::numeric_limits<float>::max())
		|| f < static_cast<double>(std::numeric_limits<float>::min())) * FLOAT_OF)
		+ (false * DOUBLE_OF)
	};

	printScalar(&number);
}
static void doubleString(std::string &literal) {
	double d = strtod(literal.c_str(), NULL);
	if (errno == ERANGE)
		throw ScalarConverter::Overflow("Double");

	t_scalar number = {
		static_cast<char>(d),
		static_cast<int>(d),
		static_cast<float>(d),
		d,
		((d > static_cast<double>(std::numeric_limits<char>::max())
		|| d < static_cast<double>(std::numeric_limits<char>::min())) * CHAR_OF)
		+ ((d > static_cast<double>(std::numeric_limits<int>::max())
		|| d < static_cast<double>(std::numeric_limits<int>::min())) * INT_OF)
		+ ((d > static_cast<double>(std::numeric_limits<float>::max())
		|| d < static_cast<double>(std::numeric_limits<float>::min())) * FLOAT_OF)
		+ (false * DOUBLE_OF)
	};

	printScalar(&number);
}
/* <----------------------------> */


/* >----------- Print -----------< */
static std::string getPrecision(float input) {
	if (input >= 1000000 || input != static_cast<float>(static_cast<long long>(input)))
		return "";
	else
		return ".0";
}
static void notypeExceptionPrint() {
	std::cout << "Literal incorrect." << std::endl;	
	throw ScalarConverter::Type();
}
static void	fractionalExceptionPrint(std::string const &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
	throw ScalarConverter::Type();
}
static void printScalar(t_scalar *nb) {
	if (nb->status & CHAR_OF)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(nb->c))
		std::cout << "char: '" << nb->c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	if (nb->status & INT_OF)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << nb->i << std::endl;

	if (nb->status & FLOAT_OF)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << nb->f << getPrecision(nb->f) << "f" << std::endl;

	if (nb->status & DOUBLE_OF)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << nb->d << getPrecision(nb->d) << std::endl;
}
/* <----------------------------> */


void ScalarConverter::convert(std::string &literal) {
	void	(*stringConverters[4])(std::string &literal) = {
		&charString, &intString,
		&floatString, &doubleString
	};

	int const literalType = getType(literal);
	try {
		switch (literalType) {
			case NONE:
				notypeExceptionPrint();
				break;
			case FLOAT_EXCEPTION:
				fractionalExceptionPrint(literal.substr(0, literal.length() - 1));
				break;
			case DOUBLE_EXCEPTION:
				fractionalExceptionPrint(literal);
				break;
		}
		stringConverters[literalType](literal);
	}
	catch (ScalarConverter::Type const &) {}
	catch (ScalarConverter::Overflow const &e) {
		std::cout << e.what() << " overflow." << std::endl;
	}
}
