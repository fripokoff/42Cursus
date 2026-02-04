/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:38:37 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

/* Constructor-Destructor */
Zombie::Zombie(void)
{
	Zombie::setName("Default name");
	std::cout << "Zombie constructor called: " << Zombie::getName() << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << "Zombie destructor called: " << Zombie::getName() << std::endl;
}


/* Others */
void	Zombie::setName(std::string const &name)
{
	this->name = name;
}
std::string	Zombie::getName( void )
{
	return name;
}
void	Zombie::announce( void )
{
	std::cout << Zombie::getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
