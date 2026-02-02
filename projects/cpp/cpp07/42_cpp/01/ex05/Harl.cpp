/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:02:07 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

/* Constructor-Destructor */
Harl::Harl() {
	msgsNames[0] = "DEBUG";
	msgsFunctions[0] = &Harl::debug;

	msgsNames[1] = "INFO";
	msgsFunctions[1] = &Harl::info;

	msgsNames[2] = "WARNING";
	msgsFunctions[2] = &Harl::warning;

	msgsNames[3] = "ERROR";
	msgsFunctions[3] = &Harl::error;
}
Harl::~Harl() {}


/* Private */
void	Harl::debug( void )
{
	std::cout << DEBUG_MSG << std::endl;
}
void	Harl::info( void )
{
	std::cout << INFO_MSG << std::endl;
}
void	Harl::warning( void )
{
	std::cout << WARNING_MSG << std::endl;
}
void	Harl::error( void )
{
	std::cout << ERROR_MSG << std::endl;
}


/* Public */
void		Harl::complain( std::string level )
{
	for (size_t i = 0; i < 4; i++)
		if (level == Harl::msgsNames[i])
			(this->*Harl::msgsFunctions[i])();
}
