/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:11:17 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

static void	printPoints(Point const a, Point const b, Point const c, Point const p)
{
	a.print("a");
	b.print("b");
	c.print("c");
	p.print("p");
}

bool bsp(Point const a, Point const b, Point const c, Point const p);
int	main(int argc, char **argv)
{
	float aX, aY, bX, bY, cX, cY, pX, pY;
	if (argc >= 9) {
		aX = strtof(argv[1], NULL), aY = strtof(argv[2], NULL);
		bX = strtof(argv[3], NULL), bY = strtof(argv[4], NULL);
		cX = strtof(argv[5], NULL), cY = strtof(argv[6], NULL);
		pX = strtof(argv[7], NULL), pY = strtof(argv[8], NULL);
	}
	else {
		aX = 1.1471701951176, aY = 2.178569479715;
		bX = 2.7556197836526, bY = 3.3250767;
		cX = 2, cY = 1;
		pX = 2.06, pY = 2.91;
	}

	Point a(aX, aY);
	Point b(bX, bY);
	Point c(cX, cY);
	Point p(pX, pY);
	printPoints(a, b, c, p);

	if (bsp(a, b, c, p) == true)
		std::cout << "In!" << std::endl;
	else
		std::cout << "Out!" << std::endl;
}
