/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:19:28 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 17:19:08 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void){
    std::cout << "-----CONSTRUCTOR PART------" << std::endl;
    const Animal* Animal1 = new Animal();
    const Animal* Dog1 = new Dog();
    const Animal* Cat1 = new Cat();
    const Animal* Dog2 = new Dog();
    const Animal* Cat2 = new Cat();

    WrongAnimal*  WrongCat1 = new WrongCat();
    const WrongAnimal*  WrongCat2 = new WrongCat();

    const WrongAnimal* WrongAnimal1 = new WrongAnimal();

    std::cout << std::endl << "-----🔊 MAKE SOUND 🔊 ------" << std::endl;
    if (Cat1) Cat1->makeSound();
    else std::cerr << "Cat1 not allocated!" << std::endl;
    if (Dog1) Dog1->makeSound();
    else std::cerr << "Dog1 not allocated!" << std::endl;
    if (Animal1) Animal1->makeSound();
    else std::cerr << "Animal1 not allocated!" << std::endl;
    if (Dog2) Dog2->makeSound();
    else std::cerr << "Dog2 not allocated!" << std::endl;
    if (Cat2) Cat2->makeSound();
    else std::cerr << "Cat2 not allocated!" << std::endl;

    std::cout << std::endl << "-----WRONG PART WITHOUT VIRTUAL ------" << std::endl;
    if (WrongCat1) WrongCat1->makeSound();
    else std::cerr << "WrongCat1 not allocated!" << std::endl;
    if (WrongCat2) WrongCat2->makeSound();
    else std::cerr << "WrongCat2 not allocated!" << std::endl;
    if (WrongAnimal1) WrongAnimal1->makeSound();
    else std::cerr << "WrongAnimal1 not allocated!" << std::endl;
    std::cout << std::endl;

    std::cout << "-----DECONSTRUCTOR PART------" << std::endl;
    if (Animal1) delete Animal1;
    if (Cat1) delete Cat1;
    if (Dog1) delete Dog1;
    if (Dog2) delete Dog2;
    if (Cat2) delete Cat2;
    if (WrongCat2) delete WrongCat2;
    if (WrongCat1) delete WrongCat1;
    if (WrongAnimal1) delete WrongAnimal1;
}