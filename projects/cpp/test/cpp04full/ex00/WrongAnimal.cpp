/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:31:48 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:18:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(): _type("Random WrongAnimal"){
	std::cout << "WrongAnimal default constructor called with type " << _type << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal " << _type << " destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type){
	std::cout << "WrongAnimal " << _type << " copy constructor called " << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other){
	if (this != &other)
		_type = other._type;
	return (*this);
}
WrongAnimal::WrongAnimal(std::string type): _type(type){}

void WrongAnimal::makeSound(void) const{
	std::cout << _type << " make a noise !" << std::endl;
}

const std::string& WrongAnimal::getType() const{return (_type);}
