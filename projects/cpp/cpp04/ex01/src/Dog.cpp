/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 14:44:26 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
    announce("Constructor Dog called");
}

Dog::~Dog(){
     announce("Destructor Dog called");
}

Dog::Dog(const Dog &o) : Animal("Dog"){
    type = o.getType();
    announce("Dog copied.");
}

Dog &Dog::operator=(const Dog &o){
    if (this != & o){
        type = o.getType();
    }
    announce("Dog Copy assignment operator called");
    return *this;
}

void Dog::makeSound() const{
    announce("Waf Waf");
}