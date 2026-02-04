/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:25:26 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"

/* >----------- Cons/Destructors -----------< */
AMateria::AMateria() : _type("DefaultType") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other) : _type(other._type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other) {
	std::cout << "AMateria copy assignment called" << std::endl;
	_type = other._type;

	return *this;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	std::cout << "AMateria type constructor called" << std::endl;
}
/* <----------------------------> */


/* >----------- Others -----------< */
std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "* Non-concretized Materia, non-affects " << target.getName() + " *";
	std::cout << std::endl;
}
/* <----------------------------> */
