/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:12:04 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		/* Variables */
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
		std::string		darkestSecret;
		std::string		phoneNumber;

	public:
		/* Constructor-Destructor */
		Contact(void);
		~Contact(void);

		/* Setters */
		void	setFirstName(std::string const &newFirstName);
		void	setLastName(std::string const &newLastName);
		void	setNickName(std::string const &newNickName);
		void	setDarkestSecret(std::string const &newDarkestSecret);
		void	setPhoneNumber(std::string const &newPhoneNumber);

		/* Getters */
		std::string		getFirstName() const;
		std::string		getLastName() const;
		std::string		getNickName() const;
		std::string		getDarkestSecret() const;
		std::string		getPhoneNumber() const;

		/* Others */
		void	searchContact(int contactIndex) const;
		void	printContact() const;
};

#endif