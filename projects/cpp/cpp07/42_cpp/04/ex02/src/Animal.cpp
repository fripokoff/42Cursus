/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:51:13 by kpires            #+#    #+#             */
/*   Updated: 2024/08/22 13:01:46 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AAnimal.hpp"

/* >----------- Cons/Destructors -----------< */
AAnimal::AAnimal() : _type("AAnimal") {
	announce("AAnimal default constructor called");
}

AAnimal::AAnimal(std::string type) : _type(type) {
	announce("AAnimal name constructor called");
}

AAnimal::~AAnimal() {
	announce("AAnimal destructor called");
}

AAnimal::AAnimal(AAnimal const &other) : _type(other.getType()) {
	announce("AAnimal copy constructor called");
}

AAnimal &AAnimal::operator=(AAnimal const &other) {
	_type = other.getType();
	announce("AAnimal copy assignment constructor called");
	return *this;
}
/* <----------------------------> */



/* >----------- Get/Set -----------< */
std::string	AAnimal::getType() const {
	return _type;
}

void AAnimal::setType(std::string newType) {
	_type = newType;
}
/* <----------------------------> */


/* >----------- Announcers -----------< */
void AAnimal::announce(std::string content) const {
	std::cout << _type << ": " << content << std::endl;
}
/* <----------------------------> */
