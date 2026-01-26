/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
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

/* OCCF */
Fixed::Fixed() : value(0) { std::cout << "Default constructor called" << std::endl; }
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(Fixed const &other) : value(other.value) { std::cout << "Copy constructor called" << std::endl; }

/* Operators overloads */
Fixed			&Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->value = other.value;

	return *this;
}
std::ostream	&operator<<(std::ostream& outputStream, const Fixed& fixed)
{
	outputStream << fixed.toFloat();
	return outputStream;
}

/* Constructors */
Fixed::Fixed(int const value) : value(value << fractionalBitsNb) { std::cout << "Int constructor called" << std::endl; }
Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;

	int		integerPart = (int)(value);
	float	fractionalPart = value - integerPart;

	this->value = (integerPart << fractionalBitsNb) + roundf(fractionalPart * (1 << fractionalBitsNb));
}

/* Others */
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return value;
}
void	Fixed::setRawBits( int const raw )
{
	value = raw;
}
int		Fixed::toInt( void ) const
{
	return this->value >> fractionalBitsNb;
}
float	Fixed::toFloat( void ) const
{
	float	integerPart = value >> fractionalBitsNb;
	float	fractionalPart = value & ((1 << fractionalBitsNb) - 1);

	return integerPart + (fractionalPart / (1 << fractionalBitsNb));
}
