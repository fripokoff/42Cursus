/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:48:41 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void printField(std::string field)
{
	if (field.length() > 10) {
		field.resize(10);
		field[9] = '.';
	}
	else {
		for (int i = 0; i + field.length() < 10; i++)
			std::cout << ' ';
	}
	std::cout << field;
}

void printLine(char const *fieldName, char const *line)
{
	const std::string FIELDNAME_COLOR = "\033[34m";
	const std::string DEFAULT_COLOR = "\033[0m";
	
	if (fieldName != NULL)
		std::cout << FIELDNAME_COLOR << fieldName << DEFAULT_COLOR;
	std::cout << line << std::endl;
}

void printInvalid(int trialNumber, char const *invalidType)
{
	std::cout << "Invalid " << invalidType << " (" << trialNumber << "/3).";
	if (trialNumber < 3)
		std::cout << " Try again.";
	std::cout << std::endl;
}

std::string readLine(char const *prompt)
{
	const std::string PROMPT_COLOR = "\033[31m";
	const std::string DEFAULT_COLOR = "\033[0m";
	std::cout << PROMPT_COLOR << prompt << DEFAULT_COLOR << " ➡️  ";

	std::string line;
	std::getline(std::cin, line);
	return line;
}


/* Parsing (ADD command) */
static int	isSeparator(std::string const name, int separatorI)
{
	if (name[separatorI] != ' ' && name[separatorI] != '-')
		return false;

	if (name[separatorI + 1] == '\0')
		return false;

	if (!isalpha(name[separatorI - 1]) || !isalpha(name[separatorI + 1]))
		return false;

	return true;
}
bool	isValidName(std::string const &name)
{
	if (name.empty() || !isalpha(name[0]))
		return false;

	for (int i = 1; name[i]; i++) {
		if (!islower(name[i]))
			if (!isSeparator(name, i++))
				return false;
	}
	return true;
}
bool	isNotEmptyString(std::string const &name)
{
	return !name.empty();
}
bool	isValidPhoneNumber(std::string const &phoneNumber)
{
	/* Country code (+33 ) is optional */
	int i = 0;
	if (phoneNumber[0] == '+') {
		i++;
		while (phoneNumber[i] && phoneNumber[i] != ' ')
			i++;
		if (phoneNumber[i] != '\0')
			i++;
	}

	/* Local code (06********) is mandatory */
	int j;
	for (j = 0; phoneNumber[i + j]; j++) {
		if (!isdigit(phoneNumber[i + j]))
			return false;
	}

	/* Check country and local codes lenght */	
	return (i == 0 || (3 <= i && i <= 5)) && (7 <= j && j <= 12);
}
