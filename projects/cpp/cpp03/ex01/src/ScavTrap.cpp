/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:39 by kpires            #+#    #+#             */
/*   Updated: 2025/08/09 12:29:13 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap_default")
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap name constructor called for '" << this->name << "' with parameters." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &o) : ClapTrap(o)
{
    *this = o;
    std::cout << "ScavTrap '" << name << "' copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &o)
{
    attack_damage = o.attack_damage;
	energy_points = o.attack_damage;
	hit_points = o.hit_points;
	name = o.name;
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for '" << name << "'." << std::endl;
}

void ScavTrap::attack( const std::string &target)
{
    if (hit_points == 0 || energy_points == 0)
    {
        std::cout << "ScavTrap '" << name << "' can't attack because it's out of hit points or energy." << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ScavTrap '" << name << "' attacks '" << target << "', causing "
                << attack_damage << " points of damage. (EP left :" << energy_points << ")" << std::endl;

}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}