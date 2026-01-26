/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedOverloads.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:02:01 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <string>

#include "Fixed.hpp"

/* Copy assignment */
Fixed	&Fixed::operator=(Fixed const &operand)
{
	if (this != &operand)
		this->value = operand.value;

	return *this;
}

/* Stream insertion operator */
std::ostream	&operator<<(std::ostream& outputStream, const Fixed& fixed)
{
	outputStream << fixed.toFloat();
	return outputStream;
}

/* Arithmetic operations */
Fixed	Fixed::operator+(Fixed const &operand)  { return Fixed(toFloat() + operand.toFloat()); }
Fixed	Fixed::operator-(Fixed const &operand)  { return Fixed(toFloat() - operand.toFloat()); }
Fixed	Fixed::operator*(Fixed const &operand)  { return Fixed(toFloat() * operand.toFloat()); }
Fixed	Fixed::operator/(Fixed const &operand)
{
	if (operand.value == 0)
		return Fixed(__INT32_MAX__);
	return Fixed(toFloat() / operand.toFloat());
}

/* Comparison operations */
bool	Fixed::operator<(Fixed const &operand)  { return value < operand.value;  }
bool	Fixed::operator<=(Fixed const &operand) { return value <= operand.value; }
bool	Fixed::operator>(Fixed const &operand)  { return value > operand.value;  }
bool	Fixed::operator>=(Fixed const &operand) { return value >= operand.value; }
bool	Fixed::operator==(Fixed const &operand) { return value == operand.value;  }
bool	Fixed::operator!=(Fixed const &operand) { return value != operand.value; }

/* Pre-increment and Pre-decrement */
Fixed &Fixed::operator++()
{
	value += 1;
	return *this;
}
Fixed &Fixed::operator--()
{
	value -= 1;
	return *this;
}

/* Post-increment and Post-decrement */
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	value += 1;
	return temp;
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	value -= 1;
	return temp;
}
