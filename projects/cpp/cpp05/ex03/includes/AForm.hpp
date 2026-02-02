/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:37 by kpires            #+#    #+#             */
/*   Updated: 2026/01/28 14:03:19 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {

    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExec;
    
    public:
        AForm(std::string const name, int _gradeToSign, int _gradeToExec);
        AForm(AForm const &other);
        virtual ~AForm();

        AForm &operator=(AForm const &rhs);

        std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;
        
        void beSigned(Bureaucrat const &signer);
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighExcept : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowExcept : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        class FormNotSignedExcept : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        class CantOpenFileExcept : public std::exception{
            public:
                virtual const char *what() const throw();
        };
    
};

std::ostream& operator<<(std::ostream &os, const AForm &other);