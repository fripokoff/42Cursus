/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:52:56 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HALR_HPP
# define HALR_HPP

# include <string>

# define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-\
pickle-special-ketchup burger. I really do!"
# define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t \
put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been \
coming for years whereas you started working here since last month."
# define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

class Harl
{
	private:
		/* Variables */
		std::string	msgsNames[4];
		void		(Harl::*msgsFunctions[4])();

		/* Functions */
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		/* Constructor-Destructor */
		Harl();
		~Harl();

		void	complain( std::string level );
};

#endif