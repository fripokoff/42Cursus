/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:51 by kpires            #+#    #+#             */
/*   Updated: 2024/08/21 16:15:44 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WRONGANIMAL_HPP
# define	WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	public :
		/* >------ Cons/Destruction ------< */
		WrongAnimal();
		WrongAnimal(std::string type);
		~WrongAnimal();
		WrongAnimal(WrongAnimal const &other);
		WrongAnimal	&operator=(WrongAnimal const &other);

		/* >------ Get/Set ------< */
		std::string	getType() const;
		void		setType(std::string newType);


		/* >------ Announcers ------< */
		void	announce(std::string content) const;
		void	makeSound() const;

	protected :
		std::string	_type;
};

#endif