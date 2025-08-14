/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:12:12 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 10:21:13 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_H
#define WEAPON_CLASS_H

#include <iostream>

class	Weapon {

	private:
		std::string	type;
	
	public:
		Weapon(const std::string& type);
		~Weapon();

		const std::string& getType() const;
		void setType(const std::string& newType);
};


#endif