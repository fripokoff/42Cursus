/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:34:10 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 12:10:59 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){
	ClapTrap bot1 = ClapTrap("Bot1");

	bot1.attack("Dummy1");
	bot1.takeDamage(20);
	bot1.beRepaired(2);
	bot1.attack("Dummy1");
	ClapTrap bot2 = ClapTrap("Bot2");
	bot2.beRepaired(5);
	bot2.takeDamage(3);
	bot2.beRepaired(2);
	bot2.beRepaired(2);
	bot2.beRepaired(2);
	std::cout << std::endl << "Starting loop attack !:"<< std::endl;
	for (int i = 0; i < 10; i++)
		bot2.attack("Dummy2");
	std::cout << std::endl;
	bot2.beRepaired(10);
}