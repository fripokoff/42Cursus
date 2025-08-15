/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:29 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 14:14:04 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define CYAN    "\e[1;36m"
#define WHITE   "\e[1;37m"
#define PURPLE  "\e[35m"
#define UNDER   "\e[4;37m"
#define BLUE    "\e[0;34m"
#define RESET   "\033[0m"

#include <iostream>

class ClapTrap{

    protected:
        std::string _name;
        unsigned int _hit_points;
        unsigned int _energy_points;
        unsigned int _attack_damage;

    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &o);
        ClapTrap &operator=(const ClapTrap &o);
        ~ClapTrap();

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif