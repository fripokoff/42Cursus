/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:52:24 by kpires            #+#    #+#             */
/*   Updated: 2026/01/21 15:08:04 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <exception>

Base* generate(void){

    Base* base = NULL;
    int rdmInt = rand() % 3;

    if (rdmInt == 0)
        return (new A);
    if (rdmInt == 1)
        return (new B);
    if (rdmInt == 2)
        return (new C);

    return base;
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Error: bad cast, identify failed." << std::endl;
    return ;
}

void identify(Base& p){

    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (std::exception&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (std::exception&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (std::exception&) {}

    std::cout << "Error: bad ref, identify failed." << std::endl;
    return ;
}

int main(){

    srand(time(0));
    Base* b1 = generate();
    Base* b2 = generate();
    Base* b3 = generate();

    Base badCast;
    Base *nullTest = NULL;

    std::cout << "Cast b1 ptr* :";
    identify(b1);
    std::cout << "Cast b1 ref& :";
    identify(*b1);

    std::cout << std::endl << "Cast b2 ptr* :";
    identify(b2);
    std::cout << "Cast b2 ref& :";
    identify(*b2);

    std::cout << std::endl << "Cast b3 ptr* :";
    identify(b3);
    std::cout << "Cast b3 ref& :";
    identify(*b3);

    std::cout << std::endl << "TEST EXCEPTION" << std::endl;

    std::cout << std::endl << "Cast badCast ptr* :";
    identify(&badCast);
    std::cout << "Cast badCast ref& :";
    identify(badCast);

    std::cout << std::endl << "Cast nullTest ptr* :";
    identify(nullTest);

    delete b1;
    delete b2;
    delete b3;
    return 0;
}