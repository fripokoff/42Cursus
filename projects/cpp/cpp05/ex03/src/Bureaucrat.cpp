/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:39 by kpires            #+#    #+#             */
/*   Updated: 2026/01/28 14:04:05 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade){
    
    if( grade < 1 ){
        throw Bureaucrat::GradeTooHighExcept();
    }else if ( grade > 150){
        throw Bureaucrat::GradeTooLowExcept();
    }
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade){
    return ;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs){
    if (this != &rhs){
        this->_grade = rhs._grade;
    }
    return *this;
}

void Bureaucrat::downGrade(){
    if(this->_grade >= 150)
        throw Bureaucrat::GradeTooLowExcept();
    this->_grade++;
}

void Bureaucrat::upGrade(){
    if(this->_grade <= 1)
        throw Bureaucrat::GradeTooHighExcept();
    this->_grade--;
}

const char *Bureaucrat::GradeTooHighExcept::what() const throw(){

    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowExcept::what() const throw(){

    return "Grade is too low";
}

int Bureaucrat::getGrade(void) const {
    return _grade;
}

std::string const Bureaucrat::getName(void) const {
    return _name;
}

void Bureaucrat::signForm(AForm &form){
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << "❌ " << this->_name << ": couldn't sign " << form.getName();
        std::cout << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form){
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << "❌ " << this->_name << ": couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other){
    os << other.getName() << ", bureaucrat grade " << other.getGrade();
    return os;
}