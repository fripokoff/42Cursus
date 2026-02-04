/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:21:21 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NO_VALUE	-1
#define FIRST		0
#define SECOND		1
#define DONE		1

#include <ctime>
#include <iostream>

#include "PmergeMe.hpp"

/* >----------- Utils -----------< */
void PmergeMe::printTimeSpent(double time, std::string containerName) {
	std::cout << "Time to process a range of " << _size << " elements with "
		<< containerName << "\t: \t" << time << " us" << std::endl;
}

static int getJacobsthalElement(int index) {
	switch (index) {
		case -2:
			return 0;
		case -1:
			return 1;
		default:
			return getJacobsthalElement(index - 1) + (2 * getJacobsthalElement(index - 2));
	}
}
/* <----------------------------> */



/* >----------- Operations on containers -----------< */
void PmergeMe::addNumber(int number) {
	if (number < 0)
		throw std::exception();

	_list.push_back(number);
	_vector.push_back(number);
	_size++;
}
/* <----------------------------> */



/* >----------- List -----------< */
static void sortListPairs(std::list<std::pair<int, int> > & pairs) {
	std::list<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first > it->second) {
			int second = it->first;
			it->first = it->second;
			it->second = second;
		}
	}
}

static std::list<int> halfList(std::list<int> list, int mode) {
	int	start, end;

	if (mode == FIRST) {
		start = 0;
		end = list.size() / 2;
	}
	else {
		start = list.size() / 2;
		end = list.size();
	}

	std::list<int> half;
	while (start < end) {
		std::list<int>::iterator it = list.begin();
		std::advance(it, start);
		half.push_back(*it);
		start++;
	}
	return half;
}

static std::list<int> mergeInsertionSortList(
	std::list<int> left, std::list<int> right) {
	if (left.size() > 1)
		left = mergeInsertionSortList(halfList(left, FIRST), halfList(left, SECOND));
	if (right.size() > 1)
		right = mergeInsertionSortList(halfList(right, FIRST), halfList(right, SECOND));

	std::list<int>::iterator rightIt;
	for (rightIt = right.begin(); rightIt != right.end(); ++rightIt) {
		std::list<int>::iterator leftIt;
		for (leftIt = left.begin(); leftIt != left.end(); ++leftIt) {
			if (*rightIt <= *leftIt) {
				left.insert(leftIt, *rightIt);
				break;
			}
		}
		if (leftIt == left.end())
			left.push_back(*rightIt);
	}

	return left;
}

static void insertList(std::list<int> & destination, int newElement) {
	std::list<int>::iterator it;
	for (it = destination.begin(); it != destination.end(); ++it) {
		if (newElement <= *it) {
			destination.insert(it, newElement);
			return ;
		}
	}
	destination.push_back(newElement);
}

static void insertLastNumbers(std::list<int> & s, std::list<std::pair<int, int> > & p) {
	int index = 0;
	while (p.back().second != DONE) {
		int jacobsthalIndex = getJacobsthalElement(index);
		if (jacobsthalIndex >= static_cast<int>(p.size()))
			jacobsthalIndex = p.size() - 1;

		while (jacobsthalIndex >= 0) {
			std::list<std::pair<int, int> >::iterator it = p.begin();
			std::advance(it, jacobsthalIndex);
			if (it->second != DONE) {
				insertList(s, it->first);
				it->second = DONE;
			}
			jacobsthalIndex--;
		}
		index++;
	}
}

void PmergeMe::sortList() {
	std::list<std::pair<int, int> > pairs;

	{
		std::list<int>::iterator it;
		for (it = _list.begin(); it != _list.end(); ++it) {
			std::list<int>::iterator previous = it;
			if (++it == _list.end()) {
				pairs.push_back(std::make_pair<int, int>(NO_VALUE, *previous));
				break;
			}
			pairs.push_back(std::make_pair<int, int>(*it, *previous));
		}
	}

	sortListPairs(pairs);

	std::list<int> s;
	std::list<std::pair<int, int> > p;

	{
		std::list<std::pair<int, int> >::iterator it;
		for (it = pairs.begin(); it != pairs.end(); ++it) {
			s.push_back(it->second);
			if (it->first != NO_VALUE)
				p.push_back(std::make_pair<int, int>(it->first, !DONE));
		}
	}

	s = mergeInsertionSortList(halfList(s, FIRST), halfList(s, SECOND));
	int smallestElementOfS = s.front();
	{
		std::list<std::pair<int, int> >::iterator it;
		for (it = p.begin(); it != p.end(); ++it) {
			if (it->first < smallestElementOfS) {
				s.insert(s.begin(), it->first);
				it->second = DONE;
				break;
			}
		}
	}

	insertLastNumbers(s, p);
	_list = s;
}
/* <----------------------------> */



/* >----------- Vector -----------< */
static void sortVectorPairs(std::vector<std::pair<int, int> > & pairs) {
	std::vector<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it < pairs.end(); ++it) {
		if (it->first > it->second) {
			int second = it->first;
			it->first = it->second;
			it->second = second;
		}
	}
}

static std::vector<int> halfVector(std::vector<int> it, int mode) {
	int	start;
	int	end;

	if (mode == FIRST) {
		start = 0;
		end = it.size() / 2;
	}
	else {
		start = it.size() / 2;
		end = it.size();
	}

	std::vector<int> half;
	while (start < end) {
		half.push_back(it[start]);
		start++;
	}
	return half;
}

static std::vector<int> mergeInsertionSortVector(
	std::vector<int> left, std::vector<int> right) {
	if (left.size() > 1)
		left = mergeInsertionSortVector(halfVector(left, FIRST), halfVector(left, SECOND));
	if (right.size() > 1)
		right = mergeInsertionSortVector(halfVector(right, FIRST), halfVector(right, SECOND));

	std::vector<int>::iterator rightIt;
	for (rightIt = right.begin(); rightIt < right.end(); ++rightIt) {
		std::vector<int>::iterator leftIt;
		for (leftIt = left.begin(); leftIt < left.end(); ++leftIt) {
			if (*rightIt <= *leftIt) {
				left.insert(leftIt, *rightIt);
				break;
			}
		}
		if (leftIt == left.end())
			left.push_back(*rightIt);
	}

	return left;
}

static void insertVector(std::vector<int> & destination, int newElement) {
	std::vector<int>::iterator it;
	for (it = destination.begin(); it < destination.end(); ++it) {
		if (newElement <= *it) {
			destination.insert(it, newElement);
			return ;
		}
	}
	destination.push_back(newElement);
}

static void insertLastNumbers(std::vector<int> & s, std::vector<std::pair<int, int> > & p) {
	int index = 0;
	while (p.back().second != DONE) {
		int jacobsthalIndex = getJacobsthalElement(index);
		if (jacobsthalIndex >= static_cast<int>(p.size()))
			jacobsthalIndex = p.size() - 1;

		while (jacobsthalIndex >= 0) {
			if (p.at(jacobsthalIndex).second != DONE) {
				insertVector(s, p.at(jacobsthalIndex).first);
				p.at(jacobsthalIndex).second = DONE;
			}
			jacobsthalIndex--;
		}
		index++;
	}
}

void PmergeMe::sortVector() {
	std::vector<std::pair<int, int> > pairs;

	{
		std::vector<int>::iterator it;
		for (it = _vector.begin(); it < _vector.end(); ++it) {
			std::vector<int>::iterator previous = it;
			if (++it == _vector.end()) {
				pairs.push_back(std::make_pair<int, int>(NO_VALUE, *previous));
				break;
			}
			pairs.push_back(std::make_pair<int, int>(*it, *previous));
		}
	}

	sortVectorPairs(pairs);

	std::vector<int> s;
	std::vector<std::pair<int, int> > p;

	{
		std::vector<std::pair<int, int> >::iterator it;
		for (it = pairs.begin(); it < pairs.end(); ++it) {
			s.push_back(it->second);
			if (it->first != NO_VALUE)
				p.push_back(std::make_pair<int, int>(it->first, !DONE));
		}
	}

	s = mergeInsertionSortVector(halfVector(s, FIRST), halfVector(s, SECOND));
	int smallestElementOfS = s[0];
	{
		std::vector<std::pair<int, int> >::iterator it;
		for (it = p.begin(); it < p.end(); ++it) {
			if (it->first < smallestElementOfS) {
				s.insert(s.begin(), it->first);
				it->second = DONE;
				break;
			}
		}
	}

	insertLastNumbers(s, p);
	_vector = s;
}
/* <----------------------------> */



/* >----------- Sorting -----------< */
void PmergeMe::sortContainers() {
	std::string containersNames[2] = { "std::list", "std::vector" };
	void (PmergeMe::*sort[2])() = { &PmergeMe::sortList, &PmergeMe::sortVector };

	std::cout << "Before\t: \t";
	for (int i = 0; i < static_cast<int>(_vector.size()); ++i) {
		std::cout << _vector.at(i) << " ";
	}
	std::cout << std::endl;

	std::clock_t start[2], end[2];
	for (int i = 0; i < 2; ++i) {

		start[i] = std::clock();
		if (_size > 1)
			(this->*sort[i])();
		end[i] = std::clock();

	}
	std::cout << "After\t: \t";
	std::list<int>::iterator it = _list.begin();
	for (int i = 0; i < static_cast<int>(_list.size()); ++i) {
		std::cout << *it << " ";
		std::advance(it, 1);
	}
	std::cout << std::endl;

	printTimeSpent(static_cast<double>(end[0] - start[0]), containersNames[0]);
	printTimeSpent(static_cast<double>(end[1] - start[1]), containersNames[1]);
}
/* <----------------------------> */
