/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:14:37 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:18:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap"){
	std::cout << "default FragTrap created" << std::endl;
	setValue(100, 100, 30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	setValue(100, 100, 30);
	std::cout << "FragTrap " << getName() << " created" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << getName() << " destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){}

FragTrap& FragTrap::operator=(const FragTrap &other){
	if (this != &other)
		ClapTrap(operator=(other));
	return (*this);
}

void FragTrap::highFivesGuys(){
	if (getHit() > 0)
		std::cout << "FragTrap " << getName() << " is asking: High five, guys!" << std::endl;
	else
		std::cout << "FragTrap " << getName() << " is dead and can't ask for hight five" << std::endl;
}
