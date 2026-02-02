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

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << std::endl << " -------- Constructions part ------- " << std::endl;

	AAnimal *myAnimals[ANIMALS_NUMBER];
	// AAnimal *simpleAnimal = new AAnimal;

	for (int i = 0; i < ANIMALS_NUMBER; i++) {
		if (i % 2)
			myAnimals[i] = new Cat();
		else
			myAnimals[i] = new Dog();
	}

	std::cout << std::endl << " ------------ Tests part ----------- " << std::endl;

	for (int i = 0; i < ANIMALS_NUMBER; i++)
		myAnimals[i]->makeSound();

	std::cout << std::endl << " -------- Destructions part -------- " << std::endl;

	for (int i = 0; i < ANIMALS_NUMBER; i++)
		delete myAnimals[i];

	return 0;
}
