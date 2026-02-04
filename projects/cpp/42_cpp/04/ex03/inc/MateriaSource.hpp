/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:47:28 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# define _MATERIAS_SIZE	4

# include <string>

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		/* >------ Cons/Destructors ------< */
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &other);

		/* >------ Others ------< */
		void			learnMateria(AMateria *materia);
		AMateria*		createMateria(std::string const & type);

	private:
		AMateria	*_materias[_MATERIAS_SIZE];
};

#endif