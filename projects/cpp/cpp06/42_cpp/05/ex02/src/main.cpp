/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:41:58 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {

	std::cout << std::endl << "-----------CREATE AND UPGRADE BUREAUCRAT-----------" << std::endl;
	Bureaucrat *Arthur;
	try {
		Arthur = new Bureaucrat("Arthur", 47);
	}
	catch (IException &e) {
		std::cout << e.what() << std::endl;
		Arthur = NULL;
	}
	if (Arthur != NULL) {
		std::cout << *Arthur << std::endl;
		while (Arthur->getGrade() > 45) {
			try {
				Arthur->upGrade();
			}
			catch (IException &e) {
				std::cout << e.what() << std::endl;
				break ;
			}
			std::cout << *Arthur << std::endl;
		}
	}


	std::cout << std::endl << "-----------CREATE ROBOTOMYREQUEST, SIGN AND EXECUTE IT-----------" << std::endl;
	RobotomyRequestForm myForm("myForm");
	std::cout << myForm << std::endl;
	std::cout << *Arthur << std::endl;
	try {
		myForm.beSigned(*Arthur);
		Arthur->signForm(myForm);
		try {
			myForm.execute(*Arthur);
			Arthur->executeForm(myForm);
		}
		catch (IException &e) {
			Arthur->executeForm(myForm, e.what());
		}
	}
	catch (IException &e) {
		Arthur->signForm(myForm, e.what());
	}
	std::cout << myForm << std::endl;


	std::cout << std::endl << "-----------DOWNGRADE BUREAUCRAT-----------" << std::endl;
	while (Arthur->getGrade() < 145) {
		if (Arthur->getGrade() % 10 == 0)
			std::cout << *Arthur << std::endl;
		Arthur->downGrade();
	}
	std::cout << *Arthur << std::endl;


	std::cout << std::endl << "-----------SAME, CREATE, SIGN BUT FAIL TO EXECUTE IT-----------" << std::endl;
	ShrubberyCreationForm myForm2("myForm2");
	std::cout << myForm2 << std::endl;
	std::cout << *Arthur << std::endl;
	try {
		myForm2.beSigned(*Arthur);
		Arthur->signForm(myForm);
		try {
			myForm2.execute(*Arthur);
			Arthur->executeForm(myForm2);
		}
		catch (IException &e) {
			Arthur->executeForm(myForm2, e.what());
		}
	}
	catch (IException &e) {
		Arthur->signForm(myForm2, e.what());
	}
	std::cout << myForm2 << std::endl;


	std::cout << std::endl << "-----------CREATE PRESIDENTIALPARDON AND BUREAUCRATE, SIGN AND EXECUTE IT-----------" << std::endl;
	Bureaucrat *President;
	try {
		President = new Bureaucrat("Emmanuel Macron", 1);
		PresidentialPardonForm myForm3("myForm3");
		std::cout << myForm3 << std::endl;
		std::cout << *President << std::endl;
		try {
			myForm3.beSigned(*President);
			President->signForm(myForm3);
			try {
				myForm3.execute(*President);
				President->executeForm(myForm3);
			}
			catch (IException &e) {
				President->executeForm(myForm3, e.what());
			}
		}
		catch (IException &e) {
			President->signForm(myForm3, e.what());
		}
		std::cout << myForm3 << std::endl;
	}
	catch (IException const &e) {
		std::cout << e.what() << std::endl;
		President = NULL;
	}
	catch (std::exception const &e) {
		std::cout << "Here is my error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "-----------DESTRUCTION-----------" << std::endl;
	delete Arthur;
	delete President;
}
