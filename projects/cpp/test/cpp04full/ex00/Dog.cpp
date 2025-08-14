/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:09:26 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:18:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal("unknow"){
	std::cout << "Dog " << _type << " default constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog " << _type << " destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other._type){
	std::cout << "Dog " << _type << " copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other){
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::Dog(std::string type) : Animal(type){
	std::cout << "Dog " << _type << " constructor called" << std::endl;
}

void Dog::makeSound(void) const{
	std::cout << "Dog " << _type << " say OUAAAFFF!" << std::endl;
}
