/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:41:39 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

typedef Point Vector;

static bool	isOnRight(float vector) { return vector > 0 ;}
static bool	isOnLeft(float vector) { return vector < 0 ;}

bool	bsp( Point const a, Point const b, Point const c, Point const p)
{
	/* Calculate a vector from 2 points, A(x, y) B(x', y') : AB = (x' - x, y' - y) */
	Vector AB(b.getX() - a.getX(), b.getY() - a.getY());
	Vector AP(p.getX() - a.getX(), p.getY() - a.getY());

	Vector BC(c.getX() - b.getX(), c.getY() - b.getY());
	Vector BP(p.getX() - b.getX(), p.getY() - b.getY());

	Vector CA(a.getX() - c.getX(), a.getY() - c.getY());
	Vector CP(p.getX() - c.getX(), p.getY() - c.getY());

	/* Multiply pairs together with a cross-product v1(x, y) v2(x', y') : v1 * v2 = (x * y') - (x' * y) */
	float productABP = (AB.getX() * AP.getY() - AP.getX() * AB.getY()).toFloat();
	float productBCP = (BC.getX() * BP.getY() - BP.getX() * BC.getY()).toFloat();
	float productCAP = (CA.getX() * CP.getY() - CP.getX() * CA.getY()).toFloat();
	std::cout << productABP << " / " << productBCP << " / " << productCAP << std::endl;

	return ((isOnRight(productABP) && isOnRight(productBCP) && isOnRight(productCAP))
		|| (isOnLeft(productABP) && isOnLeft(productBCP) && isOnLeft(productCAP)));
}
