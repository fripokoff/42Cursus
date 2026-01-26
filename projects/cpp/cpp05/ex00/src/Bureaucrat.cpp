/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:39 by kpires            #+#    #+#             */
/*   Updated: 2026/01/24 16:41:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade){
    
    if( grade < 1 ){
        throw Bureaucrat::GradeTooHighExcept();
    }else if ( grade > 150){
        throw Bureaucrat::GradeTooLowExcept();
    }
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
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

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other){
    os << other.getName() << ", bureaucrat grade " << other.getGrade();
    return os;
}