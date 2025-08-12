/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:19:28 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 14:45:27 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main(void)
{
    // Animal test("hello");
    // Animal second;

    // second = test;
    // std::string protect;


    // test.announce("hi");
    // test.makeSound();
    // protect = test.getType();
    // test.announce(protect);

    // test.setType("bombino");
    // protect = test.getType();
    // test.announce(protect);
    // Dog testDog;
    // Cat testCat;

    // testDog.makeSound();
    // testCat.makeSound();
    const WrongAnimal* meta = new WrongAnimal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    return 0;
}