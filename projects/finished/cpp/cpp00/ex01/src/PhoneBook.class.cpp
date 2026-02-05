/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:06:51 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 09:57:51 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook ( void ) {
	this->_Index = 0;
	this->_TotalContacts = 0;
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << "📇 PhoneBook up to 8 contacts" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	return ;
}

PhoneBook::~PhoneBook ( void ) {
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << "📇 PhoneBook deleted ! 🗑️" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	return ;
}

std::string PhoneBook::_GetDisplayName( int contactID ) const {

	return this->_contacts[contactID].GetField(0) + " " + this->_contacts[contactID].GetField(1);
}

int PhoneBook::_GetContactID( void ) const {

	return (this->_TotalContacts % 8);
}

void    PhoneBook::AddContact ( void ) {

	std::string	input;
	int			contactID;
	int			DisplayedContactID;
	std::string	DisplayName;
	int			steps;

	contactID = _GetContactID();
	DisplayedContactID = contactID + 1;
	DisplayName = _GetDisplayName(contactID);

	//Check if will be overwritten
	if (this->_TotalContacts > 7){
		std::cout << "⚠️  Contact #" << DisplayedContactID << " " << DisplayName << " will be overwritten! " << std::endl;
	}
	if(this->_Index > 7) {
		this->_Index = 0;
	}

	//Loop for all fields
	for (steps = Contact::FIRSTNAME; steps <= Contact::DARKESTSECRET; steps++) {
	
		if (steps == Contact::PHONENUMBER && PHONE_VERIFY) {
			std::cout << "❗ (digits only, optional '+' at beginning, min 10 digits)" << std::endl;
		}

		//Display field to fill
		std::cout << Contact::Fields_name[steps] << ": ";

		while (!(std::getline(std::cin, input)) || input.length() == 0) {
			if(std::cin.eof() == true ) {
				std::cout << std::endl << "👋 You Pressed ^D. Exiting phonebook now." << std::endl;
				exit(0);
			} else if (input.length() == 0) {
				input.clear();
				std::cout << "\033[31m⚠️  Field \033[0m<" << Contact::Fields_name[steps] << ">\033[31m cannot be empty\033[0m" << std::endl;
				std::cout << Contact::Fields_name[steps] << ": ";
			}
		}

		//Check and trim
		if (this->_contacts[contactID].SetAndValidateField(steps, input, PHONE_VERIFY) == 1) {
			input.clear();
			steps--;
		}
	}

	// If over or added
	if (this->_TotalContacts > 7) {
		std::cout << "✅ Contact #" << DisplayedContactID << " successfully overwritten " << std::endl;
	} else {
		std::cout << "✅ Contact " << DisplayName << " successfully added " << DisplayedContactID << "/8" << std::endl;
	}
	this->_Index++;
	this->_TotalContacts++;
	return ;
}

void PhoneBook::Search(void) const {
	std::string input;
	bool validInput = false;
	bool isNumber = true;
	int selectedIndex = 0;
	int DisplayTotalContacts = this->_TotalContacts;

	if(DisplayTotalContacts > 8)
		DisplayTotalContacts = 8;
	//Check if phonebook is empty
	if (this->_contacts[0].GetField(0).empty()){
		std::cout << "📇 PhoneBook is empty !" << std::endl;
		std::cout << "🏠 Back to main menu." << std::endl;
		return ;
	}

	PhoneBook::_ShowTable();

	std::cout << "Select a contact by its index (1-" << DisplayTotalContacts << ") or 0 to return: ";
	
	while (!validInput) {
		//Check empty or valid
		if (!(std::getline(std::cin, input)) || input.empty()) {
			if (std::cin.eof()) {
				std::cout << std::endl << "👋 You Pressed ^D. Exiting phonebook now." << std::endl;
				exit(0);
			}
			std::cout << "❌ Invalid input. Please try again: ";
			continue;
		}
		//Check if is number
		isNumber = true;
		for (size_t i = 0; i < input.length(); i++) {
			if (!std::isdigit(input[i])) {
				isNumber = false;
				break;
			}
		}
		if (!isNumber) {
			std::cout << "#️⃣  Please enter a number: ";
			continue;
		}
		//Check index choosed
		selectedIndex = std::atoi(input.c_str());
		if (selectedIndex == 0) {
			std::cout << "🏠 Back to main menu." << std::endl;
			return;
		} else if (selectedIndex < 1 || selectedIndex > DisplayTotalContacts) {
			std::cout << "⚠️  Index must be between 1 and " << DisplayTotalContacts << ". Please try again: ";
		} else if (this->_contacts[selectedIndex - 1].GetField(0).empty()) {
			std::cout << "⚠️   No contact at this index. Please try again: ";
		} else {
			validInput = true;
		}
	}
	PhoneBook::_ShowContact(selectedIndex);
	return ;
}

void PhoneBook::FillWithTestData(int number) {
	std::string testData[][5] = {
		{"Jean", "Dupont", "JD42", "+33123456789", "Il collectionne des chaussettes"},
		{"Marie", "Martin", "MM21", "+33612345678", "Ne boit que du café froid"},
		{"Pierre", "Leroy", "PLR", "+33687654321", "Peur des escargots"},
		{"Sophie", "Bernard", "Soso", "+33654321987", "A volé un bonbon à 5 ans"},
		{"Lucas", "Petit", "Luc", "+33698765432", "Déteste la pizza"},
		{"Emma", "Dubois", "Emmy", "+33612378945", "Dort avec une peluche"},
		{"Thomas", "Moreau", "Tom", "+33678912345", "Chante sous la douche"},
		{"Camille", "Simon", "Cam", "+33645678912", "Collectionne les timbres"}
	};
	
	for (int i = 0; i < number; i++) {
		for (int j = Contact::FIRSTNAME; j <= Contact::DARKESTSECRET; j++) {
			this->_contacts[i].SetAndValidateField(j, testData[i][j], PHONE_VERIFY);
		}
		this->_Index++;
		this->_TotalContacts++;
	}
}

void PhoneBook::_ShowContact(int ContactID) const {

	for (int i = Contact::FIRSTNAME; i <= Contact::DARKESTSECRET; i++) {
		std::cout << Contact::Fields_name[i] << ": " << this->_contacts[ContactID - 1].GetField(i) << std::endl;
	}
}


void PhoneBook::_ShowTable() const {

	int TotalContacts = this->_TotalContacts;

	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << std::setfill(' ');

	std::cout << "|" << std::setw(10) << "Index" << "|" 
			<< std::setw(10) << "First Name" << "|" 
			<< std::setw(10) << "Last Name" << "|" 
			<< std::setw(10) << "Nickname" << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << std::setfill(' ');
	
	if(TotalContacts > 8)
		TotalContacts = 8;
	for (int i = 0; i < TotalContacts ; i++) {
		if (!this->_contacts[i].GetField(0).empty()) {
			std::cout << "|" << std::setw(10) << i + 1;
			
			for (int j = 0; j < 3; j++) {
				std::string field = this->_contacts[i].GetField(j);
				if (field.length() > 10)
					field = field.substr(0, 9) + ".";
				std::cout << "|" << std::setw(10) << field;
			}
			std::cout << "|" << std::endl;
		}
	}
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
}