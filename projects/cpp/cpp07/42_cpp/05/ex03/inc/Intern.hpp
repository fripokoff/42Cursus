/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:27:05 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		/* >------ Cons/Destructors ------< */
		Intern() { std::cout << "Intern constructor called" << std::endl; }
		~Intern() { std::cout << "Intern destructor called" << std::endl; }

		/* >------ Actions ------< */
		AForm static	*createShrubberyForm(std::string const &target) { return new ShrubberyCreationForm(target); }
		AForm static	*createRobotomyForm(std::string const &target) { return new RobotomyRequestForm(target); }
		AForm static	*createPresidentialForm(std::string const &target) { return new PresidentialPardonForm(target); }
		AForm			*makeForm(std::string const &formName, std::string const &target) const;

		/* >------ Exceptions ------< */
		class FormUnknownException : public std::exception
		{
			public:
				FormUnknownException() {}
				virtual const char* what() const throw() { return "Intern doesn't know this form name" ; }
		};

		/* since Intern has no attributes, operator= overloads is not needed */
		/* same logic for the copy construtor */
};

#endif