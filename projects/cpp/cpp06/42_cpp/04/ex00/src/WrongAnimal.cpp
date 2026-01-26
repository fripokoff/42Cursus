/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:51:13 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.hpp"

/* >----------- Cons/Destructors -----------< */
WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	announce("WrongAnimal default constructor called");
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	announce("WrongAnimal name constructor called");
}

WrongAnimal::~WrongAnimal() {
	announce("WrongAnimal destructor called");
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : _type(other.getType()) {
	announce("WrongAnimal copy constructor called");
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
	_type = other.getType();
	announce("WrongAnimal copy assignment constructor called");
	return *this;
}
/* <----------------------------> */



/* >----------- Get/Set -----------< */
std::string	WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(std::string newType) {
	_type = newType;
}
/* <----------------------------> */


/* >----------- Announcers -----------< */
void WrongAnimal::announce(std::string content) const {
	std::cout << _type << ": " << content << std::endl;
}

void WrongAnimal::makeSound() const {
	announce("Grrrrr");
}
/* <----------------------------> */
