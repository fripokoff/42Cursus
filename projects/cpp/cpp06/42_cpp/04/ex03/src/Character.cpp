/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:32:39 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"

/* >----------- Cons/Destructors -----------< */
Character::Character() : _name("DefaultName"), _materiasNumber(0) {
	std::cout << "Character default constructor called" << std::endl;
	
	for (int i = 0; i < _MATERIAS_SIZE; i++)
		_materias[i] = NULL;
}

Character::Character(std::string const &name) : _name(name), _materiasNumber(0) {
	std::cout << "Character name constructor called" << std::endl;
	
	for (int i = 0; i < _MATERIAS_SIZE; i++)
		_materias[i] = NULL;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;

	for (int i = 0; i < _MATERIAS_SIZE; i++)
		delete _materias[i];
}

Character::Character(Character const &other) : _name(other._name) {
	std::cout << "Character copy constructor called" << std::endl;

	for (int i = 0; i < _MATERIAS_SIZE; i++)
		_materias[i] = NULL;

	copyInventory(other);
}

Character &Character::operator=(Character const &other) {
	std::cout << "Character copy assignment called" << std::endl;

	_name = other._name;
	copyInventory(other);

	return *this;
}
/* <----------------------------> */


/* >----------- Getters -----------< */
std::string const &Character::getName() const {
	return _name;
}
/* <----------------------------> */


/* >----------- Others -----------< */
void	Character::deleteMateria(int idx) {
	if (0 <= idx && idx <= 3)
		delete _materias[idx];
}

void	Character::copyInventory(Character const &other) {
	for (int i = 0; i < _MATERIAS_SIZE; i++) {
		if (_materias[i] != NULL) {
			delete _materias[i];
			_materias[i] = NULL;
		}
	}

	for (int i = 0; i < _MATERIAS_SIZE; i++)
		if (_materias[i] != NULL)
			_materias[i] = other._materias[i]->clone();

	_materiasNumber = other._materiasNumber;
}

void Character::equip(AMateria* m) {
	if (_materiasNumber == 4)
		std::cout << _name + ": Can't equip, inventory is full" << std::endl;
	else {
		int i;
		for (i = 0; i < _MATERIAS_SIZE; i++) {
			if (_materias[i] == NULL) {
				_materias[i] = m;
				break;
			}
		}
		_materiasNumber++;
		std::cout << _name + ": equips " + m->getType() << " at index " << i << std::endl;
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || _materias[idx] == NULL)
		std::cout << _name + ": Can't unequip, nothing's there" << std::endl;
	else {
		std::cout << _name + ": unequips its " << idx << " materia" << std::endl;
		_materias[idx] = NULL;
		_materiasNumber--;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || _materias[idx] == NULL)
		std::cout << _name + ": Can't use, nothing's there" << std::endl;
	else
		_materias[idx]->use(target);
}
/* <----------------------------> */
