/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:32:06 by kpires            #+#    #+#             */
/*   Updated: 2026/01/28 12:11:49 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <exception>

class Intern
{
    public:
        Intern();
        Intern(Intern const &other);
        ~Intern();

        Intern &operator=(Intern const &rhs);

        AForm* makeForm(std::string const &formName, std::string const &target);

        class FormUnknownException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};