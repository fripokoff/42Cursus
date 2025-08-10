/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:39 by kpires            #+#    #+#             */
/*   Updated: 2025/07/30 11:47:38 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed() : _val(0){

    std::cout << "Default constructor called" << std::endl;

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