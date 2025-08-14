/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:50 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 14:00:32 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#define CYAN    "\e[1;36m"
#define WHITE   "\e[1;37m"
#define PURPLE  "\e[35m"
#define UNDER   "\e[4;37m"
#define RESET   "\033[0m"

# include <iostream>

class ClapTrap
{
	private:
		std::string 	_name;
		unsigned int 	_hit;
		unsigned int	_energy;
		unsigned int	_attack;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
