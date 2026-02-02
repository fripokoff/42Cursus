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

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap character1;
	ScavTrap character2("Bob");

	std::cout << std::endl << "        ---------        " << std::endl << std::endl;

	character1.attack("Bob");
	character2.takeDamage(0);

	character1.takeDamage(2);
	character1.takeDamage(20);
	character1.beRepaired(1);
	character1.beRepaired(2);

	std::cout << std::endl << "        ---------        " << std::endl << std::endl;

	character1.guardGate();
	character1.guardGate();

	character2.guardGate();

	std::cout << std::endl << "        ---------        " << std::endl << std::endl;

	FragTrap character3;
	FragTrap character4("Alice");

	std::cout << std::endl << "        ---------        " << std::endl << std::endl;

	character3.attack("Alice");
	character4.takeDamage(0);

	character3.takeDamage(2);
	character3.takeDamage(20);
	character3.beRepaired(1);
	character3.beRepaired(2);

	std::cout << std::endl << "        ---------        " << std::endl << std::endl;

	character3.highFivesGuys();
	character3.highFivesGuys();

	character4.highFivesGuys();
}
