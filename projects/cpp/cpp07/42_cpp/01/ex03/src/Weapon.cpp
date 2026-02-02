/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:27:20 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Weapon.hpp"

/* Constructor-Destructor */
Weapon::Weapon()
{
	type = "default weapon type";
}
Weapon::Weapon(std::string const &type)
{	
	this->type = type;
}
Weapon::~Weapon() {}

/* Setter-Getter */
std::string const	&Weapon::getType() const
{
	return type;
}
void	Weapon::setType(std::string const &newType)
{
	type = newType;
}
