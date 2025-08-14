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

#include "FragTrap.hpp"

int main(void)
{
	FragTrap a("fabien");
	FragTrap b("maria");

	std::cout << std::endl;
	a.highFivesGuys();
	b.highFivesGuys();
	std::cout << std::endl;
	for(int i = 0; i <= 5; i++){
		a.attack(b.getName());
		b.takeDamage(a.getAttack());
	}
	b.beRepaired(20);
	b.attack(a.getName());
	a.takeDamage(5000);
	std::cout << std::endl;
	a.highFivesGuys();
	b.highFivesGuys();
	std::cout << std::endl;
}
