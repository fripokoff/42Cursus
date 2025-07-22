/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:58:12 by kpires            #+#    #+#             */
/*   Updated: 2025/07/21 15:36:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
    return ;
}

void Zombie::setZombieName(std::string const zombieName)
{
    name = zombieName;
    return ;
}

Zombie::~Zombie()
{
    std::cout << "[Destructor]" << name << std::endl;
    return ;
}
