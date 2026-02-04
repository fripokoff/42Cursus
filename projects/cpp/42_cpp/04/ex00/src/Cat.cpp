/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:51:13 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

/* >----------- Cons/Destructors -----------< */
Cat::Cat() : Animal("Cat") {
	announce("Cat default constructor called");
}

Cat::~Cat() {
	announce("Cat destructor called");
}

Cat::Cat(Cat const &other) : Animal("Cat") {
	_type = other.getType();
	announce("Cat copy constructor called");
}

Cat &Cat::operator=(Cat const &other) {
	_type = other.getType();
	announce("Cat copy assignment constructor called");
	return *this;
}
/* <----------------------------> */


/* >----------- Get/Set -----------< */
std::string	Cat::getType() const {
	return _type;
}

void Cat::setType(std::string newType) {
	_type = newType;
}
/* <----------------------------> */


/* >----------- Announcers -----------< */
void Cat::announce(std::string content) const {
	std::cout << _type << ": " << content << std::endl;
}

void Cat::makeSound() const {
	announce("Miaouu");
}
/* <----------------------------> */
