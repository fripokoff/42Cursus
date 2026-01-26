/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:19:42 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_HPP
# define USER_INTERFACE_HPP

# include <string>

# define TRANSITION		"\033[33m*********************************************\033[0m"
# define COLUMN_NAMES	"\033[4m|Index     |Firstname |Lastname  |Nickname  |\033[0m"
# define FIELD_SIZE 10

void 		printField(std::string field);
void		printLine(char const *fieldName, char const *line);
void		printInvalid(int trialNumber, char const *invalidType);
std::string	readLine(char const *prompt);

/* Parsing (ADD command) */
bool		isValidName(std::string const &name);
bool		isNotEmptyString(std::string const &name);
bool		isValidPhoneNumber(std::string const &phoneNumber);

#endif