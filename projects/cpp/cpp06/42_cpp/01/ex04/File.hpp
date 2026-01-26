/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:55:02 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

# include <string>

# define FAILURE	1
# define SUCCESS	0

class File
{
	private:
		std::string	&name;
		std::string	content;

	public:
		/* Constructor-Destructor */
		File(std::string &name);
		~File();

		/* Others */
		std::string	&getName() const;
		void		replace(std::string const target, std::string const replacement);
		bool		load(std::string const sourceFileName);
		bool		stream(std::string const &destinationFileName) const ;
};

#endif