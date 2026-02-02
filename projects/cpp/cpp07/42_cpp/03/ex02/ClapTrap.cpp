/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:32:41 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

/* OCCF */
ClapTrap::ClapTrap() : damage(0), energy(10), hit(10), name("DefaultName")
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
	*this = other;
}
ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap copy assignment constructor called." << std::endl;
	damage = other.damage;
	energy = other.energy;
	hit = other.hit;
	name = other.name;

	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

/* Special constructor */
ClapTrap::ClapTrap(std::string const name) : damage(0), energy(10), hit(10), name(name)
{
	std::cout << "ClapTrap name constructor called." << std::endl;
}

/* Actions */
void	ClapTrap::attack(const std::string& target)
{
	if (energy == 0) {
		std::cout << "ClapTrap " << name << " can't attack without energy." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << name << " attacks " << target;
	std::cout << ", causing " << damage << " points of damage." << std::endl;
	energy--;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " receives " << amount << " points of damage. ";

	if (amount > hit)
		hit = 0;
	else
		hit -= amount;
	std::cout << "(Update) Hit points: " << hit << "." << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit == 0) {
		std::cout << "ClapTrap " << name << " can't recover because he's dead." << std::endl;
		return ;
	}

	if (energy == 0) {
		std::cout << "ClapTrap " << name << " can't recover without energy." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << name << " recoveres " << amount <<  " hit points. ";

	hit += amount;
	energy--;
	std::cout << "(Update) Hit points: " << hit << "." << std::endl;
}
