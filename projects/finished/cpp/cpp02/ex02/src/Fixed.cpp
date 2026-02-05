/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:39 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 09:26:31 by kpires           ###   ########.fr       */
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

bool Fixed::operator>(const Fixed& o)
{
    return (_val > o._val);
}

bool Fixed::operator<(const Fixed& o)
{
    return (_val < o._val);
}

bool Fixed::operator>=(const Fixed& o)
{
    return (_val >= o._val);
}

bool Fixed::operator<=(const Fixed& o)
{
    return (_val <= o._val);
}

bool Fixed::operator==(const Fixed& o)
{
    return (_val == o._val);
}

bool Fixed::operator!=(const Fixed& o)
{
    return (_val != o._val);
}

Fixed Fixed::operator+(const Fixed& o) const{

    Fixed result;

    result.setRawBits(this->_val + o._val);
    return (result);
}

Fixed Fixed::operator-(const Fixed& o) const{

    Fixed result;

    result.setRawBits(this->_val - o._val);
    return (result);
}

Fixed Fixed::operator/(const Fixed& o) const{
    Fixed result;

    if (o._val == 0) {
        std::cerr << "Error: division by zero" << std::endl;
        return 0;
    }

    long long temp = (static_cast<long long>(_val) << _fractBits) / o._val;
    result.setRawBits(static_cast<int>(temp));
    return result;
}

Fixed Fixed::operator*(const Fixed& o) const{

    Fixed result;

    long long temp = static_cast<long long>(_val) * o._val;
    result.setRawBits(static_cast<int>(temp >> _fractBits));
    return result;
}

Fixed& Fixed::operator++()
{
    _val++;
    return (*this);
}

Fixed& Fixed::operator--()
{
    _val--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}


Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &val1, Fixed &val2)
{
    if (val1._val < val2._val)
        return (val1);
    else
        return (val2);
}

const Fixed &Fixed::min(const Fixed &val1, const Fixed &val2)
{
    if (val1._val < val2._val)
        return (val1);
    else
        return (val2);
}

Fixed &Fixed::max(Fixed &val1, Fixed &val2)
{
    if (val1._val > val2._val)
        return (val1);
    else
        return (val2);
}

const Fixed &Fixed::max(const Fixed &val1, const Fixed &val2)
{
    if (val1._val > val2._val)
        return (val1);
    else
        return (val2);
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