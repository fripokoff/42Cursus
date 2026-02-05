/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:39 by kpires            #+#    #+#             */
/*   Updated: 2026/01/29 11:58:26 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
    :   AForm("PresidentialPardonForm", 25 , 5), _target(target){
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
    :   AForm(other), _target(other._target){
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs){
    if (this != &rhs){
        AForm::operator=(rhs);
        this->_target = rhs.getTarget();
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget(void) const {
    return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{

    AForm::beExecuted(this->getSigned(), executor.getGrade(), this->getGradeToExec());

    std::cout << "✅ " << executor.getName() << " executed " << this->getName() << std::endl;
	std::cout << "✅ " << executor.getName() << " " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox. 🙏" << std::endl;
    return ;
}
