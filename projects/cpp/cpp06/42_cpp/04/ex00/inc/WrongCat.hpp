/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCatWrong.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:51 by kpires            #+#    #+#             */
/*   Updated: 2024/08/21 16:54:24 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WrongCat_HPP
# define	WrongCat_HPP

# include <string>

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		/* >------ Cons/Destructors ------< */
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat const &other);
		WrongCat	&operator=(WrongCat const &other);

		/* >------ Get/Set ------< */
		std::string	getType() const;
		void		setType(std::string newType);

		/* >------ Announcers ------< */
		void	announce(std::string content) const;
		void	makeSound() const;
};

#endif