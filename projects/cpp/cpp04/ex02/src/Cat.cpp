/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 22:15:38 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"){
    announce("Constructor Cat called");
    this->_brain = new Brain();
}

Cat::~Cat(){
     announce("Destructor Cat called");
     delete _brain;
}

Cat::Cat(const Cat &o) : AAnimal(o._type){
    _type = o.getType();
    _brain = new Brain(*o.getBrain()); 
    announce("Cat copied.");
}

Cat &Cat::operator=(Cat const &o)
{
    announce("Cat Assignation operator called");
    if (this != &o)
    {
        this->_type = o._type;
        if (_brain)
            delete _brain;
        _brain = new Brain(*o.getBrain());
    }
    return (*this);
}

void Cat::makeSound() const{
    announce("Miaou Miaou");
}

Brain *Cat::getBrain() const { return this->_brain; }