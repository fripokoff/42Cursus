/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:59:41 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"

/* >----------- Cons/Destructors -----------< */
AForm::AForm(std::string const &name, int const toSign, int const toExecute)
	: _name(name), _gradeToSign(toSign), _gradeToExecute(toExecute) {
	std::cout << _name << ": Form constructor called" << std::endl;

	_isSigned = false;

	if (toSign < MAXIMAL_GRADE || toExecute < MAXIMAL_GRADE)
		throw GradeTooHighException();

	if (toSign > MINIMAL_GRADE || toExecute > MINIMAL_GRADE)
		throw GradeTooLowException();
}

AForm::~AForm() {
	std::cout << _name << ": AForm destructor called" << std::endl;
}

AForm::AForm(AForm const &other) : _name(other._name),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << _name << ": AForm copy constructor called" << std::endl;

	_isSigned = other._isSigned;
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
AForm &AForm::operator=(AForm const &other) {
	std::cout << _name << ": AForm copy assignment called" << std::endl;

	_isSigned = other._isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &outputStream, AForm const &it) {
	std::string	isSigned = (it.getIsSigned() == true) ? "signed" : "not-signed";

	outputStream << it.getName() << ": " << isSigned
		<< ", gradeToSign " << it.getGradeToSign()
		<< ", gradeToExecute " << it.getGradeToExecute() << ".";

	return outputStream;
}
/* <----------------------------> */


/* >----------- Actions -----------< */
void AForm::beSigned(Bureaucrat const &signatory) {
	if (_isSigned)
		throw FormAlreadySigned();

	if (signatory.getGrade() > _gradeToSign)
		throw GradeTooLowException();

	_isSigned = true;
}
/* <----------------------------> */
