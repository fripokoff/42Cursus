/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:52:41 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"
#include "userInterface.hpp"

/* Constructor-Destructor */
PhoneBook::PhoneBook(void)
{
	this->contactsNumber = 0;
}
PhoneBook::~PhoneBook(void) {}


/* Setters */
void	PhoneBook::setContact(Contact newContact)
{
	int contactsNumber = this->getContactsNumber();

	if (contactsNumber != MAX_CONTACTS_NBR)
		setContactsNumber(contactsNumber + 1);
	else
		contactsNumber--;

	for (int i = contactsNumber - 1; i >= 0; i--)
		this->contacts[i + 1] = this->contacts[i];

	this->contacts[0] = newContact;
}
void	PhoneBook::setContactsNumber(int newContactsNumber)
{
	this->contactsNumber = newContactsNumber;
}


/* Getters */
Contact	PhoneBook::getContact(int contactIndex) const
{
	return this->contacts[contactIndex];
}
int		PhoneBook::getContactsNumber() const
{
	return this->contactsNumber;
}


/* Algorithm */
void	PhoneBook::search(int consecutiveFails)
{
	if (consecutiveFails == 0) {
		printLine(NULL, "\033[4m" TRANSITION "\033[0m");
		printLine(NULL, COLUMN_NAMES);

		for (int i = 0; i < getContactsNumber(); i++) {
			if (i == getContactsNumber() - 1) std::cout << "\033[4m";
			this->contacts[i].searchContact(i);
			if (i == getContactsNumber() - 1) std::cout << "\033[0m";
		}
		printLine(NULL, TRANSITION);
	}

	std::string index = readLine("Contact index");
	if (index.length() > 1
		|| !('0' <= index[0] && index[0] < this->getContactsNumber() + '0')) {
		printInvalid(++consecutiveFails, "index");
		if (consecutiveFails < 3)
			this->search(consecutiveFails);
	}
	else
		this->contacts[index[0] - '0'].printContact();
	return ;
}
void	PhoneBook::add()
{
	printLine(NULL, TRANSITION);

	Contact newContact;

	char prompts[5][20] = {"Firstname", "Lastname", "Nickname",
		"Phone number", "Darkest secret"};
	bool (*isValid[5])(std::string const &) = {&isValidName, &isValidName, &isValidName,
		&isValidPhoneNumber, &isNotEmptyString};
	void (Contact::*set[5])(std::string const &) = {&Contact::setFirstName, &Contact::setLastName,
		&Contact::setNickName, &Contact::setPhoneNumber, &Contact::setDarkestSecret};

	for (int i = 0; i < 5; i++) {
		int consecutiveFails = 0;
		while (consecutiveFails < 3) {
			std::string input = readLine(prompts[i]);
			if (!isValid[i](input)) {
				printInvalid(++consecutiveFails, "content");
				if (consecutiveFails == 3) {
					return ;
				}
			}
			else {
				(newContact.*set[i])(input);
				break ;
			}
		}
	}

	this->setContact(newContact);
	return ;
}
void	PhoneBook::getCommand(int consecutiveFails)
{
	if (consecutiveFails == 0)
		printLine(NULL, TRANSITION);

	std::string command = readLine("Phonebook");
	if (command.compare("SEARCH") == 0) {
		if (this->getContactsNumber() != 0)
			this->search(0);
		else
			printLine(NULL, "No contact found.");
	}
	else if (command.compare("ADD") == 0)
		this->add();
	else if (command.compare("EXIT") == 0)
		return ;
	else {
		printInvalid(++consecutiveFails, "command");
		if (consecutiveFails == 3)
			return ;
		this->getCommand(consecutiveFails);
		return ;
	}

	this->getCommand(0);
}
