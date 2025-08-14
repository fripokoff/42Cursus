/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:12:37 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 10:44:30 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon mjolnir = Weapon("Mjolnir");

		HumanA thor("Thor", mjolnir);
		thor.attack();
		mjolnir.setType("GOD MJOLNIR");
		thor.attack();
	}
	{
		Weapon shield = Weapon("Shield");

		HumanB captainAmerica("Captain America");
		captainAmerica.setWeapon(shield);
		captainAmerica.attack();
		shield.setType("GOD SHIELD");
		captainAmerica.attack();
	}
	return (0);
}