/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:39 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 14:14:50 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap_default"){
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << PURPLE << "[FragTrap]" << RESET << " " << UNDER << this->_name << RESET <<  " default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name){
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << PURPLE << "[FragTrap]" << RESET << " name constructor called for " << UNDER << this->_name << RESET <<" with parameters." << std::endl;
}

FragTrap::FragTrap(const FragTrap &o) : ClapTrap(o){
     std::cout << PURPLE << "[FragTrap]" << RESET << " " << UNDER << this->_name << RESET << " created." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &o){
    if (this != & o){
        _attack_damage = o._attack_damage;
        _energy_points = o._energy_points;
        _hit_points = o._hit_points;
        _name = o._name;
    }
    std::cout << PURPLE << "[FragTrap]" << RESET " Copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << PURPLE << "[FragTrap]" << RESET " destructor called for " << UNDER << this->_name << RESET << std::endl;
}

void	FragTrap::highFivesGuys(void){
    std::cout << BLUE << "[FIVES]" << RESET;
    std::cout << CYAN << "[FragTrap] " << RESET << UNDER << this->_name << RESET << " is looking for an high fives." << std::endl;
}