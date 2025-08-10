/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:39 by kpires            #+#    #+#             */
/*   Updated: 2025/08/09 15:36:03 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap_default")
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap constructor called for '" << this->name << "' with parameters." << std::endl;
}

FragTrap::FragTrap(const FragTrap &o) : ClapTrap(o)
{
    *this = o;
    std::cout << "FragTrap '" << name << "' copied." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &o)
{
    attack_damage = o.attack_damage;
	energy_points = o.attack_damage;
	hit_points = o.hit_points;
	name = o.name;
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for '" << name << "'." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " is looking for an high fives." << std::endl;
}