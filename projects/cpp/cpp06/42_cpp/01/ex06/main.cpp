/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:55:29 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

static int	areArgsCorrect(int argc, char **argv)
{
	if (argc != 2)
		return 0;

	std::string	filter = argv[1];
	if (filter.std::string::empty() || filter.std::string::length() > 1
		|| filter[0] < '1' || filter[0] > '4')
		return 0;

	return 1;
}
int			main(int argc, char **argv)
{
	if (!areArgsCorrect(argc, argv)) {
		std::cout << "Invalid arguments" << std::endl;
		std::cout << "Program needs a parameter ([1, 4])" << std::endl;
	}
	else {
		Harl	harl2_0(argv[1][0] - '0');

		std::string complain;

		complain = "DEBUG";
		harl2_0.Harl::complain(complain);
		complain = "INFO";
		harl2_0.Harl::complain(complain);
		complain = "WARNING";
		harl2_0.Harl::complain(complain);
		complain = "ERROR";
		harl2_0.Harl::complain(complain);
		complain = "OTHER";
		harl2_0.Harl::complain(complain);
		complain = "";
		harl2_0.Harl::complain(complain);
	}
}
