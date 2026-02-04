/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:44:08 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_HPP
# define ROBOTOMY_REQUEST_HPP

# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		/* >------ Cons/Destructors ------< */
		RobotomyRequestForm(std::string const &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &other);

		/* >------ Overloads ------< */
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);

		/* >------ Actions ------< */
		void				execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

#endif