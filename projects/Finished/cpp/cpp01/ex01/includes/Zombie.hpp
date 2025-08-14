/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:12:12 by kpires            #+#    #+#             */
/*   Updated: 2025/07/21 15:36:50 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
#define ZOMBIE_CLASS_H

#include <iostream>

class	Zombie {

	private:
		std::string	name;
	
	public:
		void announce( void );
		void setZombieName(std::string const zombieName);
		~Zombie();
};

Zombie *zombieHorde(int N, std::string const name);

#endif