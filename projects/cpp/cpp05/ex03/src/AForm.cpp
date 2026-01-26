/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:39 by kpires            #+#    #+#             */
/*   Updated: 2026/01/20 17:57:32 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
    :   _name("Default"),
        _signed(false),
        _gradeToSign(150),
        _gradeToExec(150){
    return ;
}

AForm::AForm(std::string const name, int _gradeToSign, int _gradeToExec)
    :   _name(name),
        _signed(false),
        _gradeToSign(_gradeToSign),
        _gradeToExec(_gradeToExec)
{
    if( _gradeToSign < 1  || _gradeToExec < 1){
        throw AForm::GradeTooHighExcept();
    }else if ( _gradeToSign > 150 || _gradeToExec > 150){
        throw AForm::GradeTooLowExcept();
    }
    return ;
}

AForm::AForm(AForm const &other)
    :   _name(other.getName()),
        _signed(other.getSigned()),
        _gradeToSign(other.getGradeToSign()),
        _gradeToExec(other.getGradeToExec())
{
    return ;
}

AForm::~AForm(){}

AForm &AForm::operator=(AForm const &rhs){
    if (this != &rhs){
        this->_signed = rhs._signed;
    }
    return *this;
}

std::string AForm::getName(void) const {
    return _name;
}

bool AForm::getSigned(void) const {
    return _signed;
}

int AForm::getGradeToSign(void) const {
    return _gradeToSign;
}

int AForm::getGradeToExec(void) const {
    return _gradeToExec;
}

const char *AForm::GradeTooHighExcept::what() const throw(){

    return "Grade is too high 🔋";
}

const char *AForm::GradeTooLowExcept::what() const throw(){

    return "Grade is too low 🪫";
}

const char *AForm::FormNotSignedExcept::what() const throw(){

    return "Form is not signed ❌";
}

const char *AForm::CantOpenFileExcept::what () const throw(){
    
    return "Can't open file ❌";
}

void AForm::beSigned(Bureaucrat const &signer){
    if(this->_signed){
        std::cout << "❌ " << signer.getName() << " couldn't sign " << this->_name;
        std::cout << " because it is already signed" << std::endl;
        return;
    }
    if(signer.getGrade() <= this->_gradeToSign){
        this->_signed = true;
        std::cout << "✅ " << signer.getName() << ": signed " << this->_name << " 🎉" << std::endl;
    }else{
        throw AForm::GradeTooLowExcept();
    }
    return ;
}

std::ostream& operator<<(std::ostream &os, const AForm &other){
    os << other.getName() << ": is ";
    if (other.getSigned() == true)
        os << "signed.";
    else
        os << "not signed.";
    os << std::endl << "Grade to sign the " << other.getName() << ": " << other.getGradeToSign() << std::endl;
    return os;
}