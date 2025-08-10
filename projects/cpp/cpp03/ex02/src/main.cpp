/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:34:10 by kpires            #+#    #+#             */
/*   Updated: 2025/08/09 15:42:05 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	ScavTrap character1;
	ScavTrap character2("Nyan");

	std::cout<< "---------------------------" << std::endl;
	character1.attack("Nyan");
	character2.takeDamage(0);
	character1.takeDamage(2);
	character1.takeDamage(20);
	character1.beRepaired(1);
	character1.beRepaired(2);

	std::cout<< "---------------------------" << std::endl;
	character1.guardGate();
	character1.guardGate();
	character2.guardGate();
	std::cout<< "---------------------------" << std::endl;

	FragTrap character3;
	FragTrap character4("Cat");
	std::cout<< "---------------------------" << std::endl;

	character3.attack("Cat");
	character4.takeDamage(0);

	character3.takeDamage(2);
	character3.takeDamage(20);
	character3.beRepaired(1);
	character3.beRepaired(2);

	std::cout<< "---------------------------" << std::endl;
	character3.highFivesGuys();
	character3.highFivesGuys();
	character4.highFivesGuys();
}