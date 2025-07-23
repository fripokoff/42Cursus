/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:22:15 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 10:36:17 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
#define HUMANA_CLASS_HPP


#include "Weapon.hpp"
#include <iostream>

class HumanA{

    private:
        std::string name;
        Weapon& weapon;
    
    public:
        HumanA(const std::string& name, Weapon& weapon);
        void attack() const;
        ~HumanA();

};

#endif