/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:02:11 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 13:07:26 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
    announce("Constructor WrongAnimal called");
}

WrongAnimal::WrongAnimal(std::string type) : type(type){
    announce("Constructor name WrongAnimal called");
}

WrongAnimal::~WrongAnimal(){
    announce("Destructor WrongAnimal called");
}

WrongAnimal::WrongAnimal(const WrongAnimal &o) : type(o.getType()){
    *this = o;
    announce("WrongAnimal copied.");
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &o){
    if(this != & o){
        type = o.getType();
    }
    announce("WrongAnimal Copy assignment operator called");
    return *this;
}

void WrongAnimal::makeSound() const{
    announce("Wrong Grr");
    return ;
}

std::string WrongAnimal::getType() const{
    return this->type;
}

void WrongAnimal::setType(std::string newType){
    type = newType;
    return ;
}

void WrongAnimal::announce(std::string msg) const{
    std::cout << type << ": " << msg << std::endl;
}