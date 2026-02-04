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

#define TABLE_SIZE	3

#include <iostream>
#include <string>

#include "Iter.hpp"

void toUpperCase(std::string & content) {
	for (std::string::iterator it = content.begin(); it != content.end(); it++) {
		*it = toupper(*it);
	}
}

void increase(int &number) {
	number++;
}

int main( void ) {

	/* >------TEST ON A STD::STRING ARRAY------< */
	std::string *stringTable = new std::string[TABLE_SIZE];
	stringTable[0] = "Bonjour";
	stringTable[1] = "12345 a";
	stringTable[2] = "test numero 3!";

	iter<std::string, void>(stringTable, TABLE_SIZE, &toUpperCase);

	for (int i = 0; i != TABLE_SIZE; i++)
		std::cout << "[" << i << "]: " << stringTable[i] << std::endl;
	std::cout << std::endl;


	/* >------TEST ON A INT ARRAY------< */
	int *intTable = new int[TABLE_SIZE];
	intTable[0] = 1;
	intTable[1] = -1;
	intTable[2] = 10;

	iter<int, void>(intTable, TABLE_SIZE, &increase);

	for (int i = 0; i != TABLE_SIZE; i++)
		std::cout << "[" << i << "]: " << intTable[i] << std::endl;

	delete[] stringTable;
	delete[] intTable;
	return 0;
}

// #include <iostream>
// #include "Iter.hpp"

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
