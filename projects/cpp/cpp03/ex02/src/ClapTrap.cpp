/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:39 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 14:08:13 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    :   _name("ClapTrap Default"),
        _hit_points(10),
        _energy_points(10),
        _attack_damage(0){
    std::cout << WHITE << "[ClapTrap]" << RESET << " default constructor called. Initialized " << UNDER << this->_name << RESET << " with 10 HP, 10 EP, and 0 AD." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    :   _name(name),
        _hit_points(10),
        _energy_points(10),
        _attack_damage(0){
    std::cout << WHITE << "[ClapTrap]" << RESET << " constructor called for " << UNDER << this->_name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &o)
    :   _name(o._name),
        _hit_points(o._hit_points),
        _energy_points(o._energy_points),
        _attack_damage(o._attack_damage){
    std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " created." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &o){
    if (this != & o){
        _name = o._name;
        _hit_points = o._hit_points;
        _energy_points = o._energy_points;
        _attack_damage = o._attack_damage;
    }
    std::cout << WHITE << "[ClapTrap]" << RESET << " Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << WHITE << "[ClapTrap]" << RESET << " destructor called for " << UNDER << this->_name << RESET << std::endl;
}

void ClapTrap::attack( const std::string &target){
    std::cout << "\033[1;34m[ATTACK]\033[0m";
    if (_hit_points <= 0 || _energy_points <= 0){
        std::cout << "\033[1;31m[FAIL]\033[0m";
        std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " can't attack because it's out of hit points or energy." << std::endl;
        return;
    }
    _energy_points--;
    std::cout << "\033[1;32m[SUCCESS]\033[0m";
    std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " attacks '" << target << "', causing "
                << _attack_damage << " points of damage. (EP left :" << _energy_points << ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "\033[1;33m[DAMAGED]\033[0m";
    if (_hit_points <= 0){
        std::cout << "\033[1;31m[DEAD]\033[0m";
        std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " can't take more damage, it's already destroyed." << std::endl;
        return;
    }
    if(amount >= _hit_points){
        std::cout << "\033[1;31m[DEAD]\033[0m";
        _hit_points = 0;
        std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " took " << amount << " damage and has been destroyed!" << std::endl;
        return;
    }
    else{
        _hit_points -= amount;
        std::cout << "\033[1;32m[SUCCESS]\033[0m";
        std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " took " << amount << " damage. (HP left :" << _hit_points << ")" << std::endl;
        return;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    std::cout << "\033[1;35m[REPAIR]\033[0m";
    if (amount == 0) {
        std::cout << "\033[1;31m[FAIL]\033[0m";
        std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " cannot be repaired from 0." << std::endl;
        return;
    }
    if(_energy_points <= 0){
        std::cout << "\033[1;31m[FAIL ENERGY]\033[0m";
        std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " doesn't have the energy to repair it" << std::endl;
        return;
    }
    if (_hit_points <= 0){
        std::cout << "\033[1;31m[DEAD]\033[0m";
        std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " can't be repaired, it's already destroyed." << std::endl;
        return;
    }
    if(_hit_points == 10){
        std::cout << "\033[1;31m[FULL]\033[0m";
        std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " doesn't need to be repaired, these hit_points are at max " << std::endl;
        return;
    }
    _energy_points--;
    _hit_points += amount;
    std::cout << "\033[1;32m[REPAIRED]\033[0m";
    std::cout << WHITE << "[ClapTrap]" << RESET << UNDER << this->_name << RESET << " repaired itself for " << amount << ". (HP left :" << _hit_points << "), (EP left :" << _energy_points << ")" << std::endl;
}