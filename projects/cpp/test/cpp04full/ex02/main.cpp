/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:15 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:26:23 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
	Dog a("fab the dog");
	Cat b("lap the kitty");
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = new Cat();
	// const Animal* j = new Animal();

	i = k;
	std::cout << std::endl;
	a.makeSound();
	b.makeSound();
	i->makeSound();
	std::cout << std::endl << a.getType() << std::endl << b.getType() << std::endl;
	// b.printIdeas();
	delete j;
	delete i;
	(void)k;
}
