/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 20:52:36 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(){
    announce("AAnimal Constructor called");
}

AAnimal::AAnimal(std::string type) : _type(type){
    announce("AAnimal Constructor type called");
}

AAnimal::~AAnimal(){
     announce("AAnimal Destructor called");
}

AAnimal::AAnimal(const AAnimal &o) : _type(o._type){
    announce("AAnimal copy constructor called.");
}

AAnimal &AAnimal::operator=(const AAnimal &o){
    if (this != & o){
        _type = o._type;
    }
    announce("AAnimal Copy assignment operator called");
    return *this;
}

void AAnimal::makeSound( void ) const{
    announce("ZZzzzZZZzzz");
}

const std::string &AAnimal::getType( void ) const{
    return this->_type;
}

void AAnimal::announce(std::string msg) const{
    std::string emoji;

    if (_type == "Dog")
        emoji = "🐶";
    else if (_type == "Cat")
        emoji = "🐱";
    else
        emoji = "🐾";
    std::cout << emoji << " " << _type << ": " << msg << std::endl;
}