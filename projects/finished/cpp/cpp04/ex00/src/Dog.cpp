/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 13:13:28 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*============ CONSTRUCTOR ============*/

Dog::Dog( void ) : Animal("Dog"){
    announce("Dog Constructor called");
}

/*============ DESTRUCTOR ============*/

Dog::~Dog(){
     announce("Dog Destructor called");
}

/*============ COPY ASSIGN ============*/

Dog::Dog(const Dog &o) : Animal(o._type){
    _type = o._type;
    announce("Dog copied.");
}

Dog &Dog::operator=(const Dog &o){
    if (this != &o)
		Animal::operator=(o);
    announce("Dog Copy assignment operator called");
    return *this;
}

/*============ METHODS ============*/

void Dog::makeSound( void ) const{
    announce("Waf Waf");
}