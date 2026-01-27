/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:37 by kpires            #+#    #+#             */
/*   Updated: 2026/01/27 10:25:23 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {

    private:
        std::string const _name;
        int         _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &other);
        ~Bureaucrat();

        Bureaucrat &operator=(Bureaucrat const &rhs);

        void upGrade();
        void downGrade();

        int getGrade(void) const;
        void signForm(Form &form);
        std::string const getName(void) const;

        class GradeTooHighExcept : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowExcept : public std::exception{
            public:
                virtual const char *what() const throw();
        };
    
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other);