/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:19:28 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 21:48:29 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "-----CONSTRUCTOR PART------" << std::endl;
	const Animal* Animal1 = new Animal();
	const Animal* Dog1 = new Dog();
	const Animal* Cat1 = new Cat();
	const Animal* Dog2 = new Dog();
	const Animal* Cat2 = new Cat();

	WrongAnimal*  WrongCat1 = new WrongCat();
	const WrongAnimal*  WrongCat2 = new WrongCat();
	WrongCat wc;

    const WrongAnimal* WrongAnimal1 = new WrongAnimal();

	std::cout << std::endl << "-----🔊 MAKE SOUND 🔊 ------" << std::endl;
	Cat1->makeSound();
	Dog1->makeSound();
	Animal1->makeSound();
	Dog2->makeSound();
	Cat2->makeSound();
	WrongCat1->makeSound();
	WrongCat2->makeSound();
    WrongAnimal1->makeSound();
	wc.makeSound();
	std::cout << std::endl;

    std::cout << "-----DECONSTRUCTOR PART------" << std::endl;
	delete Animal1;
	delete Cat1;
	delete Dog1;
	delete Dog2;
	delete Cat2;
	delete WrongCat2;
	delete WrongCat1;
    delete WrongAnimal1;
	std::cout << std::endl;
	std::cout << std::endl;
}