/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:39 by kpires            #+#    #+#             */
/*   Updated: 2026/01/28 14:02:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <string>

Form::Form(std::string const name, int _gradeToSign, int _gradeToExec)
    :   _name(name),
        _signed(false),
        _gradeToSign(_gradeToSign),
        _gradeToExec(_gradeToExec)
{
    if( _gradeToSign < 1  || _gradeToExec < 1){
        throw Form::GradeTooHighExcept();
    }else if ( _gradeToSign > 150 || _gradeToExec > 150){
        throw Form::GradeTooLowExcept();
    }
    return ;
}

Form::Form(Form const &other)
    :   _name(other._name),
        _signed(other._signed),
        _gradeToSign(other._gradeToSign),
        _gradeToExec(other._gradeToExec)
{
    return ;
}

Form::~Form(){}

Form &Form::operator=(Form const &rhs){
    if (this != &rhs){
        this->_signed = rhs._signed;
    }
    return *this;
}

std::string Form::getName(void) const {
    return _name;
}

bool Form::getSigned(void) const {
    return _signed;
}

int Form::getGradeToSign(void) const {
    return _gradeToSign;
}

int Form::getGradeToExec(void) const {
    return _gradeToExec;
}

const char *Form::GradeTooHighExcept::what() const throw(){

    return "Grade is too high";
}

const char *Form::GradeTooLowExcept::what() const throw(){

    return "Grade is too low";
}

void Form::beSigned(Bureaucrat const &signer){
    if(this->_signed){
        std::cout << signer.getName() << " couldn't sign " << this->_name;
        std::cout << " because it is already signed" << std::endl;
        return;
    }
    if(signer.getGrade() <= this->_gradeToSign){
        this->_signed = true;
        std::cout << signer.getName() << " signed " << this->_name << std::endl;
    }else{
        throw Form::GradeTooLowExcept();
    }
    return ;
}

std::ostream& operator<<(std::ostream &os, const Form &other){
    os << other.getName() << ": is ";
    if (other.getSigned() == true)
        os << "signed.";
    else
        os << "not signed.";
    os << std::endl << "Grade to sign the " << other.getName() << ": " << other.getGradeToSign() << std::endl;
    return os;
}