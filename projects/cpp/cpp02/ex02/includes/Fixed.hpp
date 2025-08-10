/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:29 by kpires            #+#    #+#             */
/*   Updated: 2025/08/07 10:14:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed{

    private:
        int _val;
        static const int _fractBits = 8;

    public:
        Fixed();
        Fixed( const Fixed & o );
        Fixed(const int value);
        Fixed(const float value);
        Fixed& operator=(const Fixed & o);
        ~Fixed();

        //comparaison
        bool operator>(const Fixed& o);
        bool operator<(const Fixed& o);
        bool operator>=(const Fixed& o);
        bool operator<=(const Fixed& o);
        bool operator==(const Fixed& o);
        bool operator!=(const Fixed& o);

        // arithmetic
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // increments
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int); 
        Fixed operator--(int);

        // static functions
        static Fixed &min(Fixed &val1, Fixed &val2);
        static const Fixed &min(const Fixed &val1, const Fixed &val2);
        static Fixed &max(Fixed &val1, Fixed &val2);
        static const Fixed &max(const Fixed &val1, const Fixed &val2);

        int getRawBits( void ) const;
        void setRawBits (int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);