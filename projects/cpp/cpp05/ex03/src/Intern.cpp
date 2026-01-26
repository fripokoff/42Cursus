/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:50:57 by kpires            #+#    #+#             */
/*   Updated: 2026/01/20 17:56:30 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    return;
}

Intern::Intern(Intern const &other){
    *this = other;
    return ;
}

Intern::~Intern()
{
    return ;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

static AForm* createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string const &target) {
    return new PresidentialPardonForm(target);
}

const char* Intern::FormUnknownException::what() const throw()
{
    return "Form name unknown";
}


AForm* Intern::makeForm(std::string const &form, std::string const &target)
{
    std::string formNames[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};
    AForm* (*creators[3])(std::string const &) = {createPresidential, createShrubbery, createRobotomy };

    for (int i = 0; i < 3; i++)
    {
        if (form == formNames[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return creators[i](target);
        }
    }
    
    throw FormUnknownException();
}