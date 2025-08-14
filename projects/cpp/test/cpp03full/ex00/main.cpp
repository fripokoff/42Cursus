/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:49 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:27:33 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("kito");
	ClapTrap b("dodo");

	std::cout << std::endl;
	for(int i = 0; i <= 11; i++)
		a.attack("dodo");
	std::cout << std::endl;
	b.takeDamage(10);
	b.takeDamage(10);
	b.beRepaired(20);
	b.attack("berp");
	a.takeDamage(5000);
	a.beRepaired(10);
	std::cout << std::endl;
}
