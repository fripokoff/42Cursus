/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:51 by kpires            #+#    #+#             */
/*   Updated: 2024/08/21 16:15:44 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

# include <string>

class Animal
{
	public :
		/* >------ Cons/Destruction ------< */
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(Animal const &other);
		Animal	&operator=(Animal const &other);

		/* >------ Get/Set ------< */
		std::string	getType() const;
		void		setType(std::string newType);


		/* >------ Announcers ------< */
		void 			announce(std::string content) const;
		virtual void	makeSound() const;

	protected :
		std::string	_type;
};

#endif