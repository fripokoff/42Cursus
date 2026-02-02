/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:22:06 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

/* OCCF */
DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called." << std::endl;

	hit = 100;
	energy = 50;
	damage = 30;
	name = "DefaultName";
	ClapTrap::name = name + "_clap_name";
}
DiamondTrap::DiamondTrap(DiamondTrap const &other)
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	*this = other;
}
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "DiamondTrap copy assignment constructor called." << std::endl;

	damage = other.damage;
	energy = other.energy;
	hit = other.hit;
	name = other.name;

	return *this;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

/* Special constructor */
DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap default constructor called." << std::endl;

	hit = 100;
	energy = 50;
	damage = 30;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
}


/* Others */
void DiamondTrap::whoAmI() const
{
	std::cout << "This DiamondTrap name is " << name << std::endl;
	std::cout << "Its ClapTrap name is " << ClapTrap::name << std::endl;
}
