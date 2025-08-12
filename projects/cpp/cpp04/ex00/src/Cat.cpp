/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 11:26:22 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
    announce("Constructor Cat called");
}

Cat::~Cat(){
     announce("Destructor Cat called");
}

Cat::Cat(const Cat &o) : Animal("Cat"){
    type = o.getType();
    announce("Cat copied.");
}

Cat &Cat::operator=(const Cat &o){
    if (this != & o){
        type = o.getType();
    }
    announce("Cat Copy assignment operator called");
    return *this;
}

void Cat::makeSound() const{
    announce("Miaou Miaou");
}