/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:18:42 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS_NBR 8

class PhoneBook
{
	private:
		/* Variables */
		Contact		contacts[MAX_CONTACTS_NBR];
		int			contactsNumber;

	public:
		/* Constructor-Destructor */
		PhoneBook(void);
		~PhoneBook(void);

		/* Setters */
		void	setContact(Contact newContact);
		void	setContactsNumber(int newContactsNumber);

		/* Getters */
		Contact		getContact(int contactIndex) const;
		int			getContactsNumber() const;

		/* Algorithm */
		void	printBook() const;
		void	getCommand(int consecutiveFails);
		void	search(int consecutiveFails);
		void	add();
};

#endif