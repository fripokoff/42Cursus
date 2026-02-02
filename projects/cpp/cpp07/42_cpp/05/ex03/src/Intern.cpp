/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:17:49 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Intern.hpp"

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const {
	std::string const	formNames[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	AForm* (*forms[3])(std::string const &) = { &createShrubberyForm, &createRobotomyForm, &createPresidentialForm };

	for (int i = 0; i < 3; i++) {
		if (formName.compare(formNames[i]) == 0) {
			std::cout << "Intern creates " + formNames[i] << std::endl;
			return forms[i](target);
		}
	}

	throw FormUnknownException();
}
