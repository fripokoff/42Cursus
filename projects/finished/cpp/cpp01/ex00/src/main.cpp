/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:12:37 by kpires            #+#    #+#             */
/*   Updated: 2025/07/21 15:15:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main()
{
	Zombie zomb("Bob in stack");
	zomb.announce();

	Zombie *newZ = newZombie("Bob in heap");
	newZ->announce();
	delete newZ;

	randomChump("Bob random in stack");
	return (0);
}