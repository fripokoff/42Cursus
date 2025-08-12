/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 14:51:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    announce("Constructor Brain called");
}

Brain::~Brain(){
     announce("Destructor Brain called");
}

Brain::Brain(const Brain &o) {
    *this = o;
    announce("Brain copied.");
}

Brain &Brain::operator=(const Brain &o){
    if (this != & o){
        *this = o;
    }
    announce("Brain Copy assignment operator called");
    return *this;
}

void Brain::announce(std::string msg) const{
    std::cout << msg << std::endl;
}