/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:27:03 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 10:46:21 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

HumanB::~HumanB(){
    std::cout << name << " destroyed." << std::endl;
}

void HumanB::attack() const {
    if(this->weapon){
        std::cout << name << " attack with their " << weapon->getType() << std::endl;
        return ;
    }
    std::cout << name << " has no weapon" << std::endl;
    return ;
}

void HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
}