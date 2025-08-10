/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:39 by kpires            #+#    #+#             */
/*   Updated: 2025/07/30 12:31:24 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed() : _val(0){

    std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed(const int value) {

    std::cout << "Int constructor called" << std::endl;
    _val = value << _fractBits;

}

Fixed::Fixed(const float value) {

    std::cout << "Float constructor called" << std::endl;
    _val = static_cast<int>(roundf(value * (1 << _fractBits)));

}

Fixed::Fixed(const Fixed& o) : _val(o._val){

    std::cout << "Copy constructor called" << std::endl;
    *this = o;

}

Fixed& Fixed::operator=(const Fixed& o){

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &o)
        this->_val = o.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{

    std::cout << "getRawBits member function called" << std::endl;
    return this->_val;
}

void Fixed::setRawBits( int const raw){
    this->_val = raw;
}

float Fixed::toFloat( void ) const{
    return static_cast<float>(_val) / (1 << _fractBits);
}

int Fixed::toInt( void ) const{
    return _val >> _fractBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}