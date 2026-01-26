/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:26:17 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {

	std::cout << std::endl << "Construct a Character and AMaterials" << std::endl;

	ICharacter *player1 = new Character("Bob");
	ICharacter *player2 = new Character("Timothee");

	AMateria *cure1 = new Cure;
	AMateria *cure2 = new Cure;
	AMateria *ice1 = new Ice;
	AMateria *ice2 = new Ice;

	AMateria *ice3 = new Ice;



	std::cout << std::endl << "Equip AMaterials" << std::endl;
	player1->equip(cure1);
	player1->equip(ice1);



	std::cout << std::endl << "Use available/unavailable AMaterials" << std::endl;
	player1->use(0, *player2);
	player1->use(1, *player2);
	player1->use(2, *player2);
	
	player2->use(0, *player1);



	std::cout << std::endl << "Re-equip too many AMaterials" << std::endl;
	player1->equip(cure2);
	player1->equip(ice2);
	player1->equip(ice3);



	std::cout << std::endl << "Unequip AMaterials" << std::endl;
	static_cast<Character*>(player1)->deleteMateria(1);
	player1->unequip(1);



	std::cout << std::endl << "Copy character" << std::endl;
	ICharacter *player3 = new Character(*static_cast<Character*>(player1));
	ICharacter *player4 = new Character();
	* static_cast<Character*>(player4) = * static_cast<Character*>(player1);



	std::cout << std::endl << "Destruct a Character and AMaterials" << std::endl;
	delete player1;
	delete player2;
	delete player3;
	delete player4;

	delete ice3;



	/* =================================================================== */
	std::cout << std::endl << "-------- subject's main function --------" << std::endl;



	std::cout << std::endl << "Construct MateriaSource, put Materias in it" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());



	std::cout << std::endl << "Construct Character, he equips from MateriaSource" << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("notexisting");
	


	std::cout << std::endl << "Construct Character, tries to use equipment on himself" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);



	std::cout << std::endl << "Destruct a Character and MaterialSource" << std::endl;
	delete bob;
	delete me;
	delete src;
	
	return 0;
}
