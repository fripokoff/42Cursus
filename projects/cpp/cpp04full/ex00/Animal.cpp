/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:24:07 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:18:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Random animal"){
	std::cout << "Animal default constructor called with type " << _type << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal " << _type << " destructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type){
	std::cout << "Animal " << _type << " copy constructor called with type " << _type << std::endl;
}

Animal& Animal::operator=(const Animal &other){
	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::Animal(std::string type) : _type(type){}

void Animal::makeSound(void) const{
	std::cout << _type << " make a noise !" << std::endl;
}

const std::string& Animal::getType() const{return (_type);}
