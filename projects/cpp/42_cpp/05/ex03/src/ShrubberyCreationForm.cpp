/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:20:06 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

/* >----------- Cons/Destructors -----------< */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreation", 145, 137), _target(target) {
	std::cout << _target << ": ShrubberyCreation default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << _target << ": ShrubberyCreation destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {
	std::cout << _target << ": ShrubberyCreation copy constructor called" << std::endl;

	setIsSigned(other.getIsSigned());
	_target = other._target;
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	std::cout << _target << ": ShrubberyCreation copy assigment called" << std::endl;

	setIsSigned(other.getIsSigned());
	_target = other._target;
	return *this;
}
/* <----------------------------> */


/* >----------- Actions -----------< */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw FormNotSigned();

	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::string	fileName = _target + "_shrubbery";
	std::string trees = ASCII_TREES;

	std::ofstream	stream(fileName.c_str(), std::iostream::out);
	if (!stream.std::ofstream::is_open()) {
		throw FileException();
	}
	stream.std::ostream::write(trees.c_str(), trees.length());
}
/* <----------------------------> */
