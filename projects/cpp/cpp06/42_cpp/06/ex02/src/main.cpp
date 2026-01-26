/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:49:59 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base* generateA(void) {
	std::cout << "Generating a A-class ptr" << std::endl;

	A* ptr = new A;
	return dynamic_cast<Base*>(ptr);
}
static Base* generateB(void) {
	std::cout << "Generating a B-class ptr" << std::endl;

	B* ptr = new B;
	return dynamic_cast<Base*>(ptr);
}
static Base* generateC(void) {
	std::cout << "Generating a C-class ptr" << std::endl;

	C* ptr = new C;
	return dynamic_cast<Base*>(ptr);
}

Base* generate(void){
	Base* (*generater[3])(void) = { &generateA, &generateB, &generateC };

	std::srand(std::time(0));
	return generater[rand() % 3]();
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p){
	try {
		A& ref = dynamic_cast<A&>(p);
		(void) ref;
	}
	catch (...) {
		try {
			B& ref = dynamic_cast<B&>(p);
			(void) ref;
		}
		catch (...) {
			try {
				C& ref = dynamic_cast<C&>(p);
				(void) ref;
			}
			catch (...) {
				return ;
			} 
			std::cout << "C" << std::endl;
			return ;
		}
		std::cout << "B" << std::endl;
		return ;
	}
	std::cout << "A" << std::endl;
}

int main() {
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);

	delete ptr;
}
