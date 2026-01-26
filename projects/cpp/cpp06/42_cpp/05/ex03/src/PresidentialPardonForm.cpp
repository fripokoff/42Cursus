/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
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

#include "PresidentialPardonForm.hpp"

/* >----------- Cons/Destructors -----------< */
PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm("PresidentialPardon", 25, 5), _target(target) {
	std::cout << _target << ": PresidentialPardon default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << _target << ": PresidentialPardon destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {
	std::cout << _target << ": PresidentialPardon copy constructor called" << std::endl;

	setIsSigned(other.getIsSigned());
	_target = other._target;
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	std::cout << _target << ": PresidentialPardon copy assigment called" << std::endl;

	setIsSigned(other.getIsSigned());
	_target = other._target;
	return *this;
}
/* <----------------------------> */


/* >----------- Actions -----------< */
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw FormNotSigned();

	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
/* <----------------------------> */
