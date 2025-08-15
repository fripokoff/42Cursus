/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 13:13:15 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*============ CONSTRUCTOR ============*/

Animal::Animal( void ) : _type("Animal"){
    announce("Animal Constructor called");
}

Animal::Animal(std::string type) : _type(type){
    announce("Animal Constructor type called");
}

/*============ DESTRUCTOR ============*/

Animal::~Animal(){
     announce("Animal Destructor called");
}

/*============ COPY ASSIGN ============*/

Animal::Animal(const Animal &o) : _type(o._type){
    announce("Animal copy constructor called.");
}

Animal &Animal::operator=(const Animal &o){
    if (this != & o){
        _type = o._type;
    }
    announce("Animal Copy assignment operator called");
    return *this;
}

/*============ METHODS ============*/

void Animal::makeSound( void ) const{
    announce("ZZzzzZZZzzz");
}

const std::string &Animal::getType( void ) const{
    return this->_type;
}

void Animal::announce(std::string msg) const{
    std::string emoji;

    if (_type == "Dog")
        emoji = "🐶";
    else if (_type == "Cat")
        emoji = "🐱";
    else
        emoji = "🐾";
    std::cout << emoji << " " << _type << ": " << msg << std::endl;
}