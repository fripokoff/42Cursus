/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:37:24 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

/* OCCF */
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;

	damage = 20;
	energy = 50;
	hit = 100;
}
ScavTrap::ScavTrap(ScavTrap const &other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = other;
}
ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScavTrap copy assignment constructor called." << std::endl;

	damage = other.damage;
	energy = other.energy;
	hit = other.hit;
	name = other.name;

	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

/* Special constructor */
ScavTrap::ScavTrap(std::string const name)
{
	damage = 20;
	energy = 50;
	hit = 100;
	this->name = name;
	std::cout << "ScavTrap name constructor called." << std::endl;
}

/* Actions */
void ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
void	ScavTrap::attack(const std::string& target)
{
	if (hit == 0) {
		std::cout << "ScavTrap " << name << " can't attack because he's dead." << std::endl;
		return ;
	}

	if (energy == 0) {
		std::cout << "ScavTrap " << name << " can't attack without energy." << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << name << " attacks " << target;
	std::cout << ", causing " << damage << " points of damage." << std::endl;
	energy--;
}
