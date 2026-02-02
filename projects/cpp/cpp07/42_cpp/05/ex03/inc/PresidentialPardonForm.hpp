/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:44:08 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_HPP
# define PRESIDENTIAL_PARDON_HPP

# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		/* >------ Cons/Destructors ------< */
		PresidentialPardonForm(std::string const &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &other);

		/* >------ Overloads ------< */
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);

		/* >------ Actions ------< */
		void				execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

#endif