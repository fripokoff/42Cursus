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
ClapTrap::ClapTrap() : _damage(0), _energy(10), _hit(10), _name("DefaultName")
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
	_damage = other._damage;
	_energy = other._energy;
	_hit = other._hit;
	_name = other._name;

	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

/* Special constructor */
ClapTrap::ClapTrap(std::string const name) : _damage(0), _energy(10), _hit(10), _name(name)
{
	std::cout << "ClapTrap name constructor called." << std::endl;
}

/* Actions */
void	ClapTrap::attack(const std::string& target)
{
	if (_hit == 0) {
		std::cout << "ClapTrap " << _name << " can't attack because he's dead." << std::endl;
		return ;
	}

	if (_energy == 0) {
		std::cout << "ClapTrap " << _name << " can't attack without energy." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _damage << " points of damage." << std::endl;
	_energy--;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " receives " << amount << " points of damage. ";

	if (amount > _hit)
		_hit = 0;
	else
		_hit -= amount;
	std::cout << "(Update) Hit points: " << _hit << "." << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit == 0) {
		std::cout << "ClapTrap " << _name << " can't recover because he's dead." << std::endl;
		return ;
	}

	if (_energy == 0) {
		std::cout << "ClapTrap " << _name << " can't recover without energy." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << _name << " recoveres " << amount <<  " hit points. ";

	_hit += amount;
	_energy--;
	std::cout << "(Update) Hit points: " << _hit << "." << std::endl;
}
