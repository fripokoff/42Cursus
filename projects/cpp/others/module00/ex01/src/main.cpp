/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:02:58 by kpires            #+#    #+#             */
/*   Updated: 2025/07/13 14:57:52 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/PhoneBook.class.hpp"

int main(void) {
	std::string	cmd = "";
	PhoneBook	PB;
	bool		running = true;

	std::cout << "➡️  Enter a command: ADD, SEARCH, EXIT" << std::endl << ">";
	while (running && std::getline(std::cin, cmd)) {
		if (std::cin.eof()) {
			std::cout << "👋 You Pressed ^D. Exiting phonebook now." << std::endl;
			exit(0);
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "⚠️  Invalid input. Please try again." << std::endl;
			continue;
		}
		if (cmd == "ADD")
			PB.AddContact();
		else if (cmd == "SEARCH")
			PB.Search();
		else if (cmd == "EXIT")
			running = false;
		std::cout << "➡️  Enter a command: ADD, SEARCH, EXIT" << std::endl << ">";
	}
	if (running) {
		std::cout << "👋 You Pressed ^D. Exiting phonebook now." << std::endl;
	}
	return (0);
}