/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:37 by kpires            #+#    #+#             */
/*   Updated: 2026/01/28 14:03:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {

    private:
        std::string const _name;
        int         _grade;
    
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &other);
        ~Bureaucrat();

        Bureaucrat &operator=(Bureaucrat const &rhs);

        void upGrade();
        void downGrade();

        int getGrade(void) const;
        std::string const getName(void) const;

        void signForm(AForm &form);
        void executeForm(AForm const &form);

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