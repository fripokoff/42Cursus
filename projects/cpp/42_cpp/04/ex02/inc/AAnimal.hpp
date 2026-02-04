/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:51 by kpires            #+#    #+#             */
/*   Updated: 2024/08/21 16:15:44 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AANIMAL_HPP
# define	AANIMAL_HPP

# include <string>

class AAnimal
{
	public :
		/* >------ Cons/Destruction ------< */
		AAnimal();
		AAnimal(std::string type);
		virtual ~AAnimal();
		AAnimal(AAnimal const &other);
		AAnimal	&operator=(AAnimal const &other);

		/* >------ Get/Set ------< */
		std::string	getType() const;
		void		setType(std::string newType);

		/* >------ Announcers ------< */
		void 			announce(std::string content) const;
		virtual void	makeSound() const = 0;

	protected :
		std::string	_type;
};

#endif