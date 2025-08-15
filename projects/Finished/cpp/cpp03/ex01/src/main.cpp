/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:34:10 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 11:24:03 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ScavTrap character1;
	ScavTrap character2("Nyan");

	ClapTrap character4("Hylo");

	character4.attack("Nyan");
	character1.attack("Nyan");

	character1.attack("Hylo");
	character4.takeDamage(20);
	character2.takeDamage(0);

	character1.takeDamage(2);
	character1.takeDamage(20);
	character1.beRepaired(1);
	character4.beRepaired(2);
	character2.attack("Hylo");

	character1.guardGate();
	character1.guardGate();

	character2.guardGate();
}