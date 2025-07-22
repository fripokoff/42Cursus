/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:12:37 by kpires            #+#    #+#             */
/*   Updated: 2025/07/21 15:38:06 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main()
{
	int maxZombie = 3;
	Zombie *allZombies= zombieHorde(maxZombie, "Happy Zombie");

	for(int i = 0; i < maxZombie; i++)
		allZombies[i].announce();
	delete[] allZombies;
	return (0);
}