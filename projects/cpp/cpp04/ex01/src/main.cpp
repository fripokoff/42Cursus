/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:19:28 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 10:44:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    Animal *animals[10];

    std::cout << "------➕ CREATING PROCESS ➕-----" << std::endl << std::endl;

    for (int i = 0; i < 10; i++){
        std::cout << "[" << i + 1 << "]";
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << std::endl;
    }

    std::cout << "------🔊 MAKE SOUND PROCESS 🔊-----" << std::endl << std::endl;

    for (int i = 0; i < 10; i++){
        std::cout << "[" << i + 1 << "]";
        animals[i]->makeSound();
        std::cout << std::endl;
    }

    std::cout << "------🗑️ DELETING PROCESS 🗑️-----" << std::endl << std::endl;
    for (int i = 0; i < 10; i++){
        std::cout << "[" << i + 1 << "]";
        delete animals[i];
        std::cout << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;

    Dog dog1;
    Cat cat1;
    std::ostringstream oss;

    Brain* dogBrain = dog1.getBrain();
    Brain* catBrain = cat1.getBrain();


    std::cout << std::endl << "------💡 IDEA PROCESS 💡-----" << std::endl << std::endl;
    
    dogBrain->setIdea(0, "I am a dog");
    catBrain->setIdea(0, "I am a cat");

    for (int i = 0; i < 142; i++)
    {
        oss.str("");
        oss.clear();
        oss << "I am a kawai dog 🐶 number " << i;
        dogBrain->setIdea(i, oss.str());

        oss.str("");
        oss.clear();
        oss << "I am a shiny cat 🐱 number " << i;
        catBrain->setIdea(i, oss.str());
    
    } 

    dog1.announce(dogBrain->getIdea(0));
    cat1.announce(dogBrain->getIdea(0));

    dog1.announce(dogBrain->getIdea(99));
    cat1.announce(dogBrain->getIdea(99));

    dog1.announce(dogBrain->getIdea(-105));
    cat1.announce(dogBrain->getIdea(2147483647));


    std::cout << std::endl << "------🧠 DEEP COPY TEST 🧠-----" << std::endl << std::endl;

    Dog basic;

    Dog tmp = basic;
    tmp.getBrain()->setIdea(0, "I am a temporary dog");
    basic.getBrain()->setIdea(0, "I am the basic dog");

    std::cout << "tmp idea: " << tmp.getBrain()->getIdea(0) << std::endl;
    std::cout << "basic idea: " << basic.getBrain()->getIdea(0) << std::endl;

    std::cout << "basic idea after tmp destruction: " << basic.getBrain()->getIdea(0) << std::endl;


    std::cout << std::endl << "-----DESTRCUTOR PART------" << std::endl;

    return 0;
}