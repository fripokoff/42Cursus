/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:37:24 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

/* OCCF */
FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;

	damage = 30;
	energy = 100;
	hit = 100;
}
FragTrap::FragTrap(FragTrap const &other)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = other;
}
FragTrap &FragTrap::operator=(FragTrap const &other)
{
	std::cout << "FragTrap copy assignment constructor called." << std::endl;

	damage = other.damage;
	energy = other.energy;
	hit = other.hit;
	name = other.name;

	return *this;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

/* Special constructor */
FragTrap::FragTrap(std::string const name)
{
	damage = 30;
	energy = 100;
	hit = 100;
	this->name = name;
	std::cout << "FragTrap name constructor called." << std::endl;
}

/* Actions */
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " is looking for an high fives." << std::endl;
}
