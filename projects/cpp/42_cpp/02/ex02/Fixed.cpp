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
Fixed::Fixed() : value(0) {}
Fixed::~Fixed() {}
Fixed::Fixed(Fixed const &operand) : value(operand.value) {}


/* Constructors */
Fixed::Fixed(int const value)
{
	this->value = value << fractionalBitsNb;
}
Fixed::Fixed(float const value)
{
	int		integerPart = (int)(value);
	float	fractionalPart = value - integerPart;

	this->value = (integerPart << fractionalBitsNb) + roundf(fractionalPart * (1 << fractionalBitsNb));
}

/* Others */
int		Fixed::getRawBits( void ) const
{
	return value;
}
void	Fixed::setRawBits( int const raw )
{
	value = raw;
}
int		Fixed::toInt( void ) const
{
	return value >> fractionalBitsNb;
}
float	Fixed::toFloat( void ) const
{
	float	integerPart = value >> fractionalBitsNb;
	float	fractionalPart = value & ((1 << fractionalBitsNb) - 1);

	return integerPart + (fractionalPart / (1 << fractionalBitsNb));
}
Fixed	&Fixed::min(Fixed &it1, Fixed &it2)
{
	return (it1 < it2) ? it1 : it2;
}
Fixed const	&Fixed::min(Fixed const &it1, Fixed const &it2)
{
	Fixed	it1_copy( it1 ), it2_copy( it2 );

	return (it1_copy < it2_copy) ? it1 : it2;
}
Fixed	&Fixed::max(Fixed &it1, Fixed &it2)
{
	return (it1 > it2) ? it1 : it2;
}
Fixed const	&Fixed::max(Fixed const &it1, Fixed const &it2) 
{
	Fixed	it1_copy( it1 ), it2_copy( it2 );

	return (it1_copy > it2_copy) ? it1 : it2;
}
