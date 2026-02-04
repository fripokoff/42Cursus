/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:09:13 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ANIMALS_NUMBER 6

#include <iostream>
#include <sstream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << std::endl << " -------- Constructions part ------- " << std::endl;

	Animal *myAnimals[ANIMALS_NUMBER];
	Animal *simpleAnimal = new Animal;

	for (int i = 0; i < ANIMALS_NUMBER; i++) {
		if (i % 2)
			myAnimals[i] = new Cat();
		else
			myAnimals[i] = new Dog();
	}

	std::cout << std::endl << " ------------ Tests part ----------- " << std::endl;

	for (int i = 0; i < ANIMALS_NUMBER; i++)
		myAnimals[i]->makeSound();
	simpleAnimal->makeSound();

	std::cout << std::endl << " -------- Destructions part -------- " << std::endl;

	for (int i = 0; i < ANIMALS_NUMBER; i++)
		delete myAnimals[i];
	delete simpleAnimal;

	return 0;
}
