/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:39 by kpires            #+#    #+#             */
/*   Updated: 2026/01/10 16:48:28 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
    :   AForm("RobotomyRequestForm", 72 , 45), _target(target)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    :   AForm(other), _target(other._target)
{
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs){
    if (this != &rhs){
        AForm::operator=(rhs);
        this->_target = rhs.getTarget();
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget(void) const {
    return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{

    AForm::beExecuted(this->getSigned(), executor.getGrade(), this->getGradeToExec());

    std::cout << "✅ " << executor.getName() << " executed " << this->getName() << std::endl;

    std::cout << "✅ " << executor.getName() << " " << "Drilling noises... " << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << "✅ " << executor.getName() << " " << this->getTarget() << " has been robotomized successfully. 🤖 ✅" << std::endl;
	else
		std::cout << "⛔ " << executor.getName() << " " << this->getTarget() << " has failed to be robotomized. 🤖 ⛔" << std::endl; 
    return ;
}
