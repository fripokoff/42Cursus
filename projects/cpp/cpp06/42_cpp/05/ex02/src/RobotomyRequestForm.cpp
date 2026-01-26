/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:20:06 by kpires            #+#    #+#             */
/*   Updated: 2024/08/29 14:07:16 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "RobotomyRequestForm.hpp"

/* >----------- Cons/Destructors -----------< */
RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("RobotomyRequest", 72, 45), _target(target) {
	std::cout << _target << ": RobotomyRequest default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << _target << ": RobotomyRequest destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {
	std::cout << _target << ": RobotomyRequest copy constructor called" << std::endl;

	setIsSigned(other.getIsSigned());
	_target = other._target;
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	std::cout << _target << ": RobotomyRequest copy assigment called" << std::endl;

	setIsSigned(other.getIsSigned());
	_target = other._target;
	return *this;
}
/* <----------------------------> */


/* >----------- Actions -----------< */
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw FormNotSigned();

	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	
	if (rand() % 2)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << _target << " robotomization failed..." << std::endl;
}
/* <----------------------------> */
