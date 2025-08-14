/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:27:03 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 10:31:15 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA(){
    std::cout << name << " destroyed." << std::endl;
}

void HumanA::attack() const {
    std::cout << name << " attack with their " << weapon.getType() << std::endl;
}
