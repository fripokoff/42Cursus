/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:49 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:18:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("fabien");
	ClapTrap c("optimus prime");
	ScavTrap b("maria");
	ScavTrap g("lolilol");

	std::cout << std::endl;
	g = a;
	g.takeDamage(10);
	std::cout << std::endl;
	for(int i = 0; i <= 5; i++){
		a.attack(b.getName());
		b.takeDamage(a.getAttack());
	}
	c.attack(a.getName());
	a.takeDamage(c.getAttack());
	b.beRepaired(20);
	b.attack(a.getName());
	a.takeDamage(5000);
	std::cout << std::endl;
	std::cout << std::endl;
	a.guardGate();
	b.guardGate();
	std::cout << std::endl;
}
