/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:51:13 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

/* >----------- Cons/Destructors -----------< */
Dog::Dog() : Animal("Dog") {
	announce("Dog default constructor called");
}

Dog::~Dog() {
	announce("Dog destructor called");
}

Dog::Dog(Dog const &other) : Animal("Dog") {
	_type = other.getType();
	announce("Dog copy constructor called");
}

Dog &Dog::operator=(Dog const &other) {
	_type = other.getType();
	announce("Dog copy assignment constructor called");
	return *this;
}
/* <----------------------------> */


/* >----------- Get/Set -----------< */
std::string	Dog::getType() const {
	return _type;
}

void Dog::setType(std::string newType) {
	_type = newType;
}
/* <----------------------------> */


/* >----------- Announcers -----------< */
void Dog::announce(std::string content) const {
	std::cout << _type << ": " << content << std::endl;
}

void Dog::makeSound() const {
	announce("Wouaff");
}
/* <----------------------------> */
