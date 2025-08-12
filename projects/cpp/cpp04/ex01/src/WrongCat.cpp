/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 14:33:50 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    announce("Constructor WrongCat called");
}

WrongCat::~WrongCat(){
     announce("Destructor WrongCat called");
}

WrongCat::WrongCat(const WrongCat &o) : WrongAnimal("WrongCat"){
    type = o.getType();
    announce("WrongCat copied.");
}

WrongCat &WrongCat::operator=(const WrongCat &o){
    if (this != & o){
        type = o.getType();
    }
    announce("WrongCat Copy assignment operator called");
    return *this;
}

void WrongCat::makeSound() const{
    announce("Waf Waf");
}