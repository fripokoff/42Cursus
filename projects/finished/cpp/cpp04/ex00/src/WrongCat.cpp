/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 13:13:46 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*============ CONSTRUCTOR ============*/

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat"){
    announce("WrongCat Constructor called");
}

/*============ DESTRUCTOR ============*/

WrongCat::~WrongCat(){
     announce("WrongCat Destructor called");
}

/*============ COPY ASSIGN ============*/

WrongCat::WrongCat(const WrongCat &o) : WrongAnimal(o._type){
    announce("WrongCat copied.");
}

WrongCat &WrongCat::operator=(const WrongCat &o){
    if (this != &o)
		WrongAnimal::operator=(o);
    announce("WrongCat Copy assignment operator called");
    return *this;
}

/*============ METHODS ============*/

void WrongCat::makeSound( void ) const{
    announce("Wrong Miaou Miaou");
}