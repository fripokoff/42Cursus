/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:34:10 by kpires            #+#    #+#             */
/*   Updated: 2025/08/13 12:02:35 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << std::endl << "for a:" << a.getRawBits() << std::endl;
    a.setRawBits(5);
    std::cout << "for a:" << a.getRawBits() << std::endl << std::endl;

    std::cout << "for b:" << b.getRawBits() << std::endl;

    std::cout << std::endl << "for c:" << c.getRawBits() << std::endl;
    c.setRawBits(42);
    std::cout << "for c:" << c.getRawBits() << std::endl << std::endl;

    b = c;
    std::cout << "for b:" << b.getRawBits() << std::endl << std::endl;
    return 0;
}