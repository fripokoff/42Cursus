/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:02:11 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 20:53:53 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"){
    announce("WrongAnimal Constructor  called");
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
    announce("WrongAnimal Constructor name called");
}

WrongAnimal::~WrongAnimal(){
    announce("WrongAnimal Destructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal &o) : _type(o._type){
    announce("WrongAnimal copied.");
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &o){
    if (this != &o)
		_type = o._type;
    announce("WrongAnimal Copy assignment operator called");
    return *this;
}

void WrongAnimal::makeSound( void ) const{
    announce("ZZzzzZZZzzz");
    return ;
}

const std::string &WrongAnimal::getType( void ) const{
    return this->_type;
}

void WrongAnimal::announce(std::string msg) const {
    std::string emoji;
    if (_type == "WrongCat")
        emoji = "❌🐱";
    else
        emoji = "❌🐾";
    std::cout << emoji << " " << _type << ": " << msg << std::endl;
}