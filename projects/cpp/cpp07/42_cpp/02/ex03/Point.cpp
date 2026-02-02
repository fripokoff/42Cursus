/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:10:07 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* OCCF */
Point::Point() : x(0), y(0) {}
Point::~Point() {}
Point::Point(float const x, float const y) : x(x), y(y) {}
Point::Point(Fixed const &x, Fixed const &y) : x(x), y(y) {}
Point::Point(Point const &operand) : x(operand.x), y(operand.y) {}
Point	&Point::operator=(Point &operand)
{
	(void) operand;
	return *this;
}

/* Others */
void	Point::print(std::string name) const
{
	std::cout << name << " : " << this->x.toFloat() << "x";
	std::cout << ", " << this->y.toFloat() << "y." << std::endl;
}
Fixed	Point::getX() const
{
	return Fixed(x);
}
Fixed	Point::getY() const
{
	return Fixed(y);
}
