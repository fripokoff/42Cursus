/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:48:41 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "MateriaSource.hpp"

/* >----------- Cons/Destructors -----------< */
MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;

	for (int i = 0; i < _MATERIAS_SIZE; i++)
		_materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;

	for (int i = 0; i < _MATERIAS_SIZE; i++) {
		if (_materias[i] != NULL)
			delete _materias[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;

	for (int i = 0; i < _MATERIAS_SIZE; i++)
		_materias[i] = other._materias[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	std::cout << "MateriaSource copy assignment called" << std::endl;

	for (int i = 0; i < _MATERIAS_SIZE; i++)
		_materias[i] = other._materias[i];

	return *this;
}
/* <----------------------------> */


/* >----------- Others -----------< */
void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < _MATERIAS_SIZE; i++) {
		if (_materias[i] == NULL) {
			_materias[i] = materia;
			std::cout << "MateriaSource successfully add materia" << std::endl;
			return ;
		}
	}

	std::cout << "MateriaSource is full, can't learn the materias" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < _MATERIAS_SIZE; i++) {
		if (_materias[i] != NULL && _materias[i]->getType().compare(type) == 0)
			return _materias[i]->clone();
	}

	std::cout << "MateriaSource didn't find this type of AMateria" << std::endl;
	return NULL;
}
/* <----------------------------> */
