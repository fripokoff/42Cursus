/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:05:46 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>

#include "Span.hpp"

/* >----------- Cons/Destructors -----------< */
Span::Span() : _maxSize(DEFAULT_MAX_SIZE) {
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _maxSize(N) {
	std::cout << "Span defined-size constructor called" << std::endl;
}

Span::Span(Span const & other) {
	std::cout << "Span copy constructor called" << std::endl;

	_maxSize = other._maxSize;
	_storage = std::vector<int>(other._storage);
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}
/* <----------------------------> */


/* >----------- Other -----------< */
Span&	Span::operator=(Span const & other) {
	std::cout << "Span copy assignment called" << std::endl;

	_maxSize = other._maxSize;
	if (_storage.size() > _maxSize)
		_storage.resize(_maxSize);

	std::vector<int>::const_iterator it;
	for (it = other._storage.begin(); it != other._storage.end(); ++it)
		_storage[it - other._storage.begin()] = *it;

	return *this;
}

int		Span::shortestSpan() const {
	if (_storage.size() < 2)
		throw std::exception();

	int shortestSpan = std::abs(_storage[1] - _storage[0]);
	std::vector<int>::const_iterator it;
	for (it = _storage.begin() + 1; it != _storage.end(); ++it) {
		int currentSpan = std::abs(*it - it[-1]);
		if (currentSpan < shortestSpan)
			shortestSpan = currentSpan;
	}
	return shortestSpan;
}

int		Span::longestSpan() const {
	if (_storage.size() < 2)
		throw std::exception();

	return std::abs(*std::max_element(_storage.begin(), _storage.end())
		 - *std::min_element(_storage.begin(), _storage.end()));
}
/* <----------------------------> */


/* >----------- Set/Getters -----------< */
void	Span::addNumber(int value) {
	if (_storage.size() == _maxSize)
		throw std::exception();

	_storage.push_back(value);
}

int		Span::getMaxSize() const {
	return _maxSize;
}
/* <----------------------------> */
