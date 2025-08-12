/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:02:58 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 09:57:58 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PhoneBook.class.hpp"

int main( int ac, char **av ) {
	std::string	cmd = "";
	PhoneBook	PB;
	bool		running = true;
	int FillTest = 7;

	//TEST PART
	if (ac > 1 && std::strcmp(av[1], "--test") == 0){

		if( ac == 3 ){

			FillTest = atoi(av[2]);
			if( FillTest > 8 )
				FillTest = 8;
			else if (FillTest < 0)
				FillTest = 1;
		}
		PB.FillWithTestData(FillTest);
		std::cout << "✅ [TEST]" << FillTest << " Contacts added." << std::endl;
	}

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