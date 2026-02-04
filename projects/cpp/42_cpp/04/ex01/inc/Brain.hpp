/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:17:47 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# define IDEAS_NUMBER_MAX	100

# include <string>

class Brain
{
	public:
		/* >------ Cons/Destructors ------< */
		Brain();
		~Brain();
		Brain(Brain const &other);
		Brain	&operator=(Brain const &other);

		/* >------ Get/Set ------< */
		std::string	getIdea(int ideaIndex) const;
		void		setIdea(std::string const &newIdea);

	private:
		int			_ideasNumber;
		std::string	_ideas[IDEAS_NUMBER_MAX];
};

#endif