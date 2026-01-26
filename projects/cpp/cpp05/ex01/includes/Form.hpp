/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:37 by kpires            #+#    #+#             */
/*   Updated: 2026/01/20 17:23:55 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExec;
    
    public:
        Form();
        Form(std::string const name, int _gradeToSign, int _gradeToExec);
        Form(Form const &other);
        ~Form();

        Form &operator=(Form const &rhs);

        std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;
        
        void beSigned(Bureaucrat const &signer);

        class GradeTooHighExcept : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowExcept : public std::exception{
            public:
                virtual const char *what() const throw();
        };
    
};

std::ostream& operator<<(std::ostream &os, const Form &other);