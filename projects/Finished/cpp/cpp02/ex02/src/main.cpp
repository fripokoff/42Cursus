/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:34:10 by kpires            #+#    #+#             */
/*   Updated: 2025/08/13 13:44:13 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ){

    float original = 54.21f;

    Fixed a;

    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    Fixed const c( Fixed( original ) / Fixed( 2 ) );

    Fixed const d( Fixed( original ) / Fixed( 0 ) );

    std::cout << "Fixed a (0):" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << std::endl << "Fixed b (multiplication):" << std::endl;
    std::cout << b << std::endl;
    std::cout << "Fixed max (" << a << "," << b << ")" << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << std::endl << "Fixed c (division) original value :" << original << std::endl;
    std::cout << c << std::endl;

    std::cout << std::endl << "Fixed d (division) par :0"<< std::endl;
    std::cout << d << std::endl;
    return 0;
}