/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:44 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:46 by kpires            #+#    #+#             */
/*   Updated: 2024/08/22 17:18:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Ice.hpp"
#include "ICharacter.hpp"

/* >----------- Cons/Destructors -----------< */
Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other.getType()) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &other) {
	std::cout << "Ice copy assignment called" << std::endl;

	_type = other.getType();
	return *this;
}
/* <----------------------------> */


/* >----------- Others -----------< */
AMateria *Ice::clone() const {
	AMateria *newIce = new Ice;

	*newIce = *this;
	return newIce;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() + " *";
	std::cout << std::endl;
}
/* <----------------------------> */
