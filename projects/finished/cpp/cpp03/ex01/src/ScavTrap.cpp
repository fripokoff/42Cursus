/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:39 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 14:07:44 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap_default"){
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << CYAN << "[ScavTrap]" << RESET << " " << UNDER << this->_name << RESET <<  " default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << CYAN << "[ScavTrap]" << RESET << " name constructor called for " << UNDER << this->_name << RESET <<" with parameters." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &o) : ClapTrap(o){
    std::cout << CYAN << "[ScavTrap]" << RESET << " " << UNDER << this->_name << RESET << " created." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &o){
    if (this != & o){
        _attack_damage = o._attack_damage;
        _energy_points = o._energy_points;
        _hit_points = o._hit_points;
        _name = o._name;
    }
    std::cout << CYAN << "[ScavTrap]" << RESET " Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << CYAN << "[ScavTrap]" << RESET " destructor called for " << UNDER << this->_name << RESET << std::endl;
}

void ScavTrap::attack( const std::string &target){
    std::cout << "\033[1;34m[ATTACK]\033[0m";
    if (_hit_points == 0 || _energy_points == 0){
        std::cout << "\033[1;31m[FAIL]\033[0m";
        std::cout << CYAN << "[ScavTrap]" << RESET << UNDER << this->_name << RESET << " can't attack because it's out of hit points or energy." << std::endl;
        return;
    }
    _energy_points--;
    std::cout << "\033[1;32m[SUCCESS]\033[0m";
    std::cout << CYAN << "[ScavTrap]" << RESET << UNDER << this->_name << RESET << " attacks '" << target << "', causing "
                << _attack_damage << " points of damage. (EP left :" << _energy_points << ")" << std::endl;
}

void ScavTrap::guardGate( void ){
    std::cout << BLUE << "[GUARD]" << RESET;
    std::cout << CYAN << "[ScavTrap] " << RESET << UNDER << this->_name << RESET << " is now in Gate keeper mode." << std::endl;
}