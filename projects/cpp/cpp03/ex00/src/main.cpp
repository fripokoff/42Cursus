/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:34:10 by kpires            #+#    #+#             */
/*   Updated: 2025/08/08 16:02:02 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bot1 = ClapTrap("Bot1");
	bot1.attack("Dummy1");
	bot1.takeDamage(20);
	bot1.beRepaired(14);
	bot1.attack("Dummy1");
	ClapTrap bot2 = ClapTrap("Bot2");
	bot2.beRepaired(5);
	bot2.takeDamage(3);
	for (int i = 0; i < 10; i++)
		bot2.attack("Dummy2");
	bot2.beRepaired(10);
}