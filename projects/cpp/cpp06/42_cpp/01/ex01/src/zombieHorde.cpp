/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 03:38:10 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <string>

#include "Zombie.h"
#include "Zombie.hpp"

#include <sstream>
#include <string>

static std::string intToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		std::string nameIndex = name + " " + intToString(i);
		horde[i].Zombie::setName(nameIndex);
	}

	return horde;
}
