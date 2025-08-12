/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 10:43:47 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal"){
    announce("Constructor animal called");
}

Animal::Animal(std::string type) : type(type){
    announce("Constructor name animal called");
}

Animal::~Animal(){
     announce("Destructor animal called");
}

Animal::Animal(const Animal &o) : type(o.getType()){
    *this = o;
    announce("Animal copied.");
}

Animal &Animal::operator=(const Animal &o){
    if (this != & o){
        type = o.getType();
    }
    announce("Animal Copy assignment operator called");
    return *this;
}

void Animal::makeSound() const{
    announce("Grr");
}

std::string Animal::getType() const{
    return this->type;
}

void Animal::setType(std::string newType)
{
    type = newType;
}

void Animal::announce(std::string msg) const{
    std::cout << type << ": " << msg << std::endl;
}