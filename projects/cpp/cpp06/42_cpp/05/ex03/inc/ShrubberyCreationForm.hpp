/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:44:08 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# define ASCII_TREES "\n               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&**&*&&*,@@@@@/@@@@@@,8888)88/8o\n\
   ,*&)*&&*&&*,@@@)@@@/@@@88)88888/88'\n\
   *&&*&*&/*&&*@@)@@/ /@@@88888)88888'\n\
   *&&*/ *&**&&@@) V /@@' `88)8 `/88'\n\
   `&*) ` /*&'    |.|        ) '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    ))/ ._)//_/__/  ,)_//__))/.  )_//__/_\n"

# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		/* >------ Cons/Destructors ------< */
		ShrubberyCreationForm(std::string const &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);

		/* >------ Overloads ------< */
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &other);

		/* >------ Actions ------< */
		void					execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

#endif