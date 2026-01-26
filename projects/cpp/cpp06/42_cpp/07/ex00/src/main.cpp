/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:49:59 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "MyTemplates.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	MyTemplates<int>::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << MyTemplates<int>::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << MyTemplates<int>::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	MyTemplates<std::string>::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << MyTemplates<std::string>::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " <<MyTemplates<std::string>::max( c, d ) << std::endl;

	MyTemplates<std::string>::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	return 0;
}
