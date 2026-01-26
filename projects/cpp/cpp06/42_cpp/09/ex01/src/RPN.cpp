/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:04 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <sstream>
#include <string>

#include "RPN.hpp"

/* >----------- Parsing -----------< */
std::string doubleToString(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}
/* <----------------------------> */


/* >----------- Operations -----------< */
void	RPN::addNumber(double number) {
	if (number < std::numeric_limits<int>::min()
		|| number > std::numeric_limits<int>::max()
		|| static_cast<int>(number) != number)
		throw Exception(doubleToString(number));
	_numbers.push(number);
}

void	RPN::operate(char it) {
	if (_numbers.size() < 2) {
		std::string exceptionMessage;
		exceptionMessage.append(1, '\'');
		exceptionMessage.append(1, it);
		exceptionMessage.append(1, '\'');

		throw Exception(exceptionMessage + " operation impossible");
	}

	double lastNumber = _numbers.top();
	_numbers.pop();

	switch (it) {
		case '+':
			_numbers.top() += lastNumber;
			break;
		case '-':
			_numbers.top() -= lastNumber;
			break;
		case '*':
			_numbers.top() *= lastNumber;
			break;
		case '/':
			_numbers.top() /= lastNumber;
			break;
	}
};

double	RPN::getResult() {
	if (_numbers.size() > 1)
		throw Exception("the numbers-operators rate is invalid");

	return _numbers.top();
}
/* <----------------------------> */
