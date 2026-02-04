/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:26:28 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap character1;
	ClapTrap character2("Bob");

	character1.attack("Bob");
	character2.takeDamage(0);

	character1.takeDamage(2);
	character1.takeDamage(20);
	character1.beRepaired(1);
	character1.beRepaired(2);
	character1.beRepaired(3);
	character1.beRepaired(4);
	character1.beRepaired(5);
	character1.beRepaired(6);
	character1.beRepaired(7);
	character1.beRepaired(8);
	character1.beRepaired(9);
	character1.beRepaired(10);
}
