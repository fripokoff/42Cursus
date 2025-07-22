/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:27:33 by kpires            #+#    #+#             */
/*   Updated: 2025/04/09 00:26:12 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# define PHONE_VERIFY 1

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include "Contact.class.hpp"

class   PhoneBook {

	private:
		Contact		_contacts[8];
		int			_Index;
		std::string	_GetDisplayName( void ) const;
		int			_GetContactID( bool next ) const;
		void		_ShowTable( int accountID ) const;

	public:
		PhoneBook	( void );
		~PhoneBook	( void );
		void		AddContact( void );
		void		FillWithTestData( int number );
		void		Search( void ) const;
};

#endif