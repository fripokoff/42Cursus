/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 21:22:16 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout <<  "🧠 Brain Constructor called" << std::endl;
}

Brain::~Brain(){
    std::cout <<  "🧠 Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &o) {
    *this = o;
     std::cout <<  "🧠 Brain copied." << std::endl;
}

Brain &Brain::operator=(const Brain &o){
    if (this != &o) {
        for (int i = 0; i < 100; ++i)
            this->_ideas[i] = o._ideas[i];
    }
    std::cout << "🧠 Brain Copy assignment operator called" << std::endl;
    return *this;
}

void Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

const std::string &Brain::getIdea(int index) const
{
    static const std::string not_found = "Doesn't exist";

	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return (not_found);
}