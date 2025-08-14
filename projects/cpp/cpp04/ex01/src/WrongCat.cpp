/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 18:54:56 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    announce("WrongCat Constructor called");
}

WrongCat::~WrongCat(){
     announce("WrongCat Destructor called");
}

WrongCat::WrongCat(const WrongCat &o) : WrongAnimal(o._type){
    announce("WrongCat copied.");
}

WrongCat &WrongCat::operator=(const WrongCat &o){
    if (this != &o)
		WrongAnimal::operator=(o);
    announce("WrongCat Copy assignment operator called");
    return *this;
}

void WrongCat::makeSound( void ) const{
    announce("Wrong Miaou Miaou");
}