/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:17:46 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Brain.hpp"

/* >----------- Cons/Destructors -----------< */
Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;

	_ideasNumber = 0;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &other) {
	std::cout << "Brain copy constructor called" << std::endl;

	_ideasNumber = other._ideasNumber;
	for (int i = 0; i < _ideasNumber; i++)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(Brain const &other) {
	std::cout << "Brain copy assignment constructor called" << std::endl;

	_ideasNumber = other._ideasNumber;
	for (int i = 0; i < _ideasNumber; i++)
		_ideas[i] = other._ideas[i];

	return *this;
}
/* <----------------------------> */


/* >----------- Get/Set -----------< */
std::string	Brain::getIdea(int ideaIndex) const {
	if (ideaIndex >= _ideasNumber)
		return "No idea at this index";

	return _ideas[ideaIndex];
}

void Brain::setIdea(std::string const &newIdea) {
	if (_ideasNumber == IDEAS_NUMBER_MAX) {
		std::cout << "Brain's full, can't think about more idea" << std::endl;
		return ;
	}

	_ideas[_ideasNumber] = newIdea;
	_ideasNumber++;
}
/* <----------------------------> */
