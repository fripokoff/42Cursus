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
Harl::Harl(int filter) {

	msgsNames[0] = "DEBUG";
	msgsNames[1] = "INFO";
	msgsNames[2] = "WARNING";
	msgsNames[3] = "ERROR";

	for (size_t i = 0; i < 4; i++)
		msgsFunctions[i] = NULL;
	switch (filter) {
		case 1:
			msgsFunctions[0] = &Harl::debug;
		case 2:
			msgsFunctions[1] = &Harl::info;
		case 3:
			msgsFunctions[2] = &Harl::warning;
		case 4:
			msgsFunctions[3] = &Harl::error;
	}
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
void		Harl::complain( std::string &level )
{
	for (size_t i = 0; i < 4; i++)
		if (level == msgsNames[i] && msgsFunctions[i] != NULL)
			(this->*Harl::msgsFunctions[i])();
}
