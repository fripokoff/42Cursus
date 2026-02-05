/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:42:14 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 09:58:10 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact ( void ) {

	for (int i = FIRSTNAME; i <= DARKESTSECRET; i++) {
		this->_Fields[i] = std::string();
	}

	return ;
}

Contact::~Contact ( void ) {
	return ;
}

const std::string Contact::Fields_name[5] =
{
	"👤 First Name",
	"👤 Last Name",
	"👤 Nickname",
	"📞 Phone Number",
	"🔐 Darkest Secret"
};

int Contact::SetAndValidateField(int step, const std::string data, bool phoneVerify) {

	std::string dataTrimed = this->_TrimString(data);

	if (phoneVerify && step == PHONENUMBER && !(this->_IsValidPhoneNumber(dataTrimed))) {
		std::cout << "⚠️  Invalid phone number! Use only digits with an optional '+' at the beginning." << std::endl;
		return (1);
	}

	this->_Fields[step] = dataTrimed;

	return (0);
}

std::string Contact::GetField(int index) const {
	return (this->_Fields[index]);
}

std::string Contact::_TrimString(const std::string& str) {

	std::string		result;
	bool			needSpace = false;
	char			c;
	
	for (size_t i = 0; i < str.length(); i++) {
		c = str[i];
		if (c == ' ' || c == '\t') {
			needSpace = true;
		} else {
			if (needSpace && !result.empty()) {
				result += ' ';
			}
			result += c;
			needSpace = false;
		}
	}
	
	return result;
}

bool Contact::_IsValidPhoneNumber(const std::string& str) {

	const size_t	MIN_DIGITS = 10;
	size_t			digitCount = 0;
	size_t			startIndex = 0;

	if (str.empty())
		return (false);

	if (str[0] == '+')
		startIndex = 1;
	if (startIndex >= str.length())
		return (false);
	for (size_t i = startIndex; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (false);
		digitCount++;
	}
	if (digitCount < MIN_DIGITS) {
		std::cout << "⚠️  Phone number must have at least " << MIN_DIGITS << " digits!" << std::endl;
		return (false);
	}
	return (true);
}
