/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:28:03 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.h"
#include "Zombie.hpp"

#define ZOMBIES_NUMBER 12

int main(void)
{
	Zombie *horde = zombieHorde(ZOMBIES_NUMBER, "Geoffroy");

	for (int i = 0; i < ZOMBIES_NUMBER; i++) {
		horde[i].Zombie::announce();
	}

	delete[] horde;
}
