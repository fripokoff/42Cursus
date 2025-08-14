/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 21:52:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
    announce("Dog Constructor called");
    this->_brain = new Brain();
}

Dog::~Dog(){
     announce("Dog Destructor called");
     delete _brain;
}

Dog::Dog(const Dog &o) : Animal(o._type){
    _type = o._type;
    _brain = new Brain(*o.getBrain()); 
    announce("Dog copied.");
}

Dog &Dog::operator=(Dog const &o)
{
    announce("Dog Assignation operator called");
    if (this != &o)
    {
        this->_type = o._type;
        if (_brain)
            delete _brain;
        _brain = new Brain(*o.getBrain());
    }
    return (*this);
}

void Dog::makeSound( void ) const{
    announce("Waf Waf");
}

Brain *Dog::getBrain() const { return this->_brain; }