/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:15 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:27:42 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* wtf = new Animal();
	const Animal* noconst1 = new Dog();
	const Animal* noconst2 = new Cat();
	WrongAnimal*  k = new WrongCat();
	const WrongAnimal*  l = new WrongCat();

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wtf->makeSound();
	noconst1->makeSound();
	noconst2->makeSound();
	k->makeSound();
	l->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete noconst1;
	delete noconst2;
	delete l;
	delete k;
	delete wtf;
	std::cout << std::endl;
	std::cout << std::endl;
}
