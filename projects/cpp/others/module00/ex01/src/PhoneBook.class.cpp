/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:06:51 by kpires            #+#    #+#             */
/*   Updated: 2025/04/09 00:26:46 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.class.hpp"

PhoneBook::PhoneBook ( void ) {
	this->_Index = 0;
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

void    PhoneBook::AddContact ( void ) {

	std::string	input;
	int			contactID;
	int			steps;

	contactID = _GetContactID(false);

	//Check if will be overwritten
	if (this->_Index > 7){
		std::cout << "⚠️  Contact #" << _GetContactID(true) << " " << _GetDisplayName() << " will be overwritten! " << std::endl;
	}

	//Loop for all fields
	for (steps = Contact::FIRSTNAME; steps <= Contact::DARKESTSECRET; steps++) {
	
		if (steps == Contact::PHONENUMBER && PHONE_VERIFY) {
			std::cout << "❗ (digits only, optional '+' at beginning, min 10 digits)" << std::endl;
		}

		//Display field to fill
		std::cout << Contact::Fields_name[steps] << ": ";

		//
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
	if (this->_Index > 7) {
		std::cout << "✅ Contact #" << _GetContactID(true) << " successfully overwritten " << std::endl;
	} else {
		std::cout << "✅ Contact " << _GetDisplayName() << " successfully added " << _GetContactID(true) << "/8" << std::endl;
	}
	this->_Index++;
	return ;
}

void PhoneBook::Search(void) const {
	std::string input;
	bool validInput = false;
	bool isNumber = true;
	int selectedIndex = 0;

	//Check if phonebook is empty
	if (this->_contacts[0].GetField(0).empty()){
		std::cout << "📇 PhoneBook is empty !" << std::endl;
		std::cout << "🏠 Back to main menu." << std::endl;
		return ;
	}

	std::cout << "Select a contact by its index (1-" << this->_Index << ") or 0 to return: ";
	
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
			std::cout << "#️⃣ Please enter a number: ";
			continue;
		}
		//Check index choosed
		selectedIndex = std::atoi(input.c_str());
		if (selectedIndex == 0) {
			std::cout << "🏠 Back to main menu." << std::endl;
			return;
		} else if (selectedIndex < 1 || selectedIndex > this->_Index) {
			std::cout << "⚠️ Index must be between 1 and " << this->_Index << ". Please try again: ";
		} else if (this->_contacts[selectedIndex - 1].GetField(0).empty()) {
			std::cout << "⚠️  No contact at this index. Please try again: ";
		} else {
			validInput = true;
		}
	}
	PhoneBook::_ShowTable(selectedIndex - 1);
}

std::string PhoneBook::_GetDisplayName( void ) const {

	int id;

	id = _GetContactID(false);

	return this->_contacts[id].GetField(0) + " " + this->_contacts[id].GetField(1);
}

int PhoneBook::_GetContactID(bool next) const {

	if (next)
		return (this->_Index % 8) + 1;

	return (this->_Index % 8);
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
	}
}

void PhoneBook::_ShowTable(int accountID) const {

	int index;

	index = 0;
	if ( accountID == -1 ){
		accountID = this->_Index;
	}
	else {
		index = accountID;
	}

	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << std::setfill(' ');

	std::cout << "|" << std::setw(10) << "Index" << "|" 
			<< std::setw(10) << "First Name" << "|" 
			<< std::setw(10) << "Last Name" << "|" 
			<< std::setw(10) << "Nickname" << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << std::setfill(' ');

	for (int i = index; i < accountID + 1; i++) {
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