/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:27:33 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 09:37:47 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# define PHONE_VERIFY 1

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cstring>
#include "Contact.class.hpp"

class   PhoneBook {

	private:
		Contact		_contacts[8];
		int			_Index;
		int			_TotalContacts;
		std::string	_GetDisplayName( int contactID ) const;
		int			_GetContactID( void ) const;
		void		_ShowTable( void ) const;
		void		_ShowContact( int ContactID ) const;

	public:
		PhoneBook	( void );
		~PhoneBook	( void );
		void		AddContact( void );
		void		FillWithTestData( int number );
		void		Search( void ) const;
};

#endif