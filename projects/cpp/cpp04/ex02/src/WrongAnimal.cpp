/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:02:11 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 13:06:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*============ CONSTRUCTOR ============*/

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal"){
    announce("WrongAnimal Constructor  called");
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
    announce("WrongAnimal Constructor name called");
}

/*============ DESTRUCTOR ============*/

WrongAnimal::~WrongAnimal(){
    announce("WrongAnimal Destructor called");
}

/*============ COPY ASSIGN ============*/

WrongAnimal::WrongAnimal(const WrongAnimal &o) : _type(o._type){
    announce("WrongAnimal copied.");
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &o){
    if (this != &o)
		_type = o._type;
    announce("WrongAnimal Copy assignment operator called");
    return *this;
}

/*============ METHODS ============*/

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