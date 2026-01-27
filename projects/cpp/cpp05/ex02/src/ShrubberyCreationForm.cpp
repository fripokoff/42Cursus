/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:00:00 by kpires            #+#    #+#             */
/*   Updated: 2026/01/27 10:25:57 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    :AForm("ShrubberyCreationForm", 145, 137), _target("default"){
        return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
    :AForm("ShrubberyCreationForm", 145, 137), _target(target){
        return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    :   AForm(other), _target(other._target){
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs){
    if (this != &rhs){
        AForm::operator=(rhs);
        this->_target = rhs.getTarget();
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const {
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(!this->getSigned())
        throw AForm::FormNotSignedExcept();
    if(executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowExcept();

    std::ofstream out((executor.getName() + "_shrubbery").c_str());
	if (!out.is_open())
		throw AForm::CantOpenFileExcept();

	std::cout << "✅ " << executor.getName() << ": executed " << this->getName() << " 🌳" << std::endl;
	
	out << "    oxoxoo    ooxoo" << std::endl;
	out << "  ooxoxo oo  oxoxooo" << std::endl;
	out << " oooo xxoxoo ooo ooox" << std::endl;
	out << " oxo o oxoxo  xoxxoxo" << std::endl;
	out << "  oxo xooxoooo o ooo" << std::endl;
	out << "    ooo\\oo\\  /o/o" << std::endl;
	out << "        \\  \\/ /" << std::endl;
	out << "         |   /" << std::endl;
	out << "         |  |" << std::endl;
	out << "         | O|" << std::endl;
	out << "         |  |" << std::endl;
	out << "         |  |" << std::endl;
	out << "  ______/____\\____" << std::endl;

    out.close();
}