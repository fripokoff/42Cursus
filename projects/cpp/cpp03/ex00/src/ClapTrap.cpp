/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:39 by kpires            #+#    #+#             */
/*   Updated: 2025/08/08 17:56:30 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap default constructor called. Initialized '" << name << "' with 10 HP, 10 EP, and 0 AD." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap constructor called for '" << this->name << "'." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &o)
{
    *this = o;
    std::cout << "ClapTrap '" << name << "' copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &o)
{
    if (this != & o)
    {
        name = o.name;
        hit_points = o.hit_points;
        energy_points = o.energy_points;
        attack_damage = o.attack_damage;
    }
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for '" << name << "'." << std::endl;
}

void ClapTrap::attack( const std::string &target)
{
    if (hit_points == 0 || energy_points == 0)
    {
        std::cout << "ClapTrap '" << name << "' can't attack because it's out of hit points or energy." << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ClapTrap '" << name << "' attacks '" << target << "', causing "
                << attack_damage << " points of damage. (EP left :" << energy_points << ")" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points == 0)
    {
        std::cout << "ClapTrap '" << name << "' can't take more damage, it's already destroyed." << std::endl;
        return;
    }
    if(amount >= hit_points)
    {
        hit_points = 0;
        std::cout << "ClapTrap '" << name << "' took " << amount << " damage and has been destroyed!" << std::endl;
    }
    else
    {
        hit_points -= amount;
        std::cout << "ClapTrap '" << name << "' took " << amount << " damage. (HP left :" << hit_points << ")" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_points == 0)
    {
        std::cout << "ClapTrap '" << name << "' can't be repaired, it's already destroyed." << std::endl;
        return;
    }
    if(energy_points == 0)
    {
        hit_points = 0;
        std::cout << "ClapTrap '" << name << "' doesn't have the energy to repair it" << std::endl;
        return;
    }
    energy_points--;
    hit_points += amount;
    std::cout << "ClapTrap '" << name << "' repaired itself for " << amount << ". (HP left :" << hit_points << "), (EP left :" << energy_points << ")" << std::endl;
}