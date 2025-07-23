/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:30:44 by kpires            #+#    #+#             */
/*   Updated: 2025/07/19 14:30:24 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class Contact {

	private:
		std::string			_Fields[5];
		static std::string	_TrimString(const std::string& str);
		static bool			_IsValidPhoneNumber(const std::string& str);

	public:
		Contact						( void );
		~Contact					( void );
		int							SetAndValidateField(int step, const std::string data, bool phoneVerify);
		std::string					GetField(int index) const;
		static const std::string	Fields_name[5];
		enum FieldIndex {
			FIRSTNAME = 0,
			LASTNAME = 1,
			NICKNAME = 2,
			PHONENUMBER = 3,
			DARKESTSECRET = 4
		};
};

#endif