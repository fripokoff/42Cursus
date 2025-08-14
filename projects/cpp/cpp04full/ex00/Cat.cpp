/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:43:10 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:18:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("chapoter"){
	std::cout << "Cat " << _type << " default constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat " << _type << " destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other._type){
	std::cout << "Cat " << _type << " copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other){
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::Cat(std::string type) : Animal(type){
	std::cout << "Cat " << _type << " constructor called" << std::endl;
}

void Cat::makeSound(void) const{
	std::cout << "Cat " << _type << " say miaouuu!" << std::endl;
}
