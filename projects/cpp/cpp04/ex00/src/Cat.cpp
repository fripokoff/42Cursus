/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 13:13:23 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*============ CONSTRUCTOR ============*/

Cat::Cat( void ) : Animal("Cat"){
    announce("Constructor Cat called");
}

/*============ DESTRUCTOR ============*/

Cat::~Cat(){
     announce("Destructor Cat called");
}

/*============ COPY ASSIGN ============*/

Cat::Cat(const Cat &o) : Animal(o._type){
    _type = o.getType();
    announce("Cat copied.");
}

Cat &Cat::operator=(const Cat &o){
    if (this != &o)
		Animal::operator=(o);
    announce("Cat Copy assignment operator called");
    return *this;
}

/*============ METHODS ============*/

void Cat::makeSound( void ) const{
    announce("Miaou Miaou");
}