/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:55:02 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

#include "File.hpp"

/* Constructor-Destructor */
File::File(std::string &name) : name(name) {}
File::~File() {}

/* Getters */
std::string	&File::getName() const
{
	return name;
}

/* Others */
void	File::replace(std::string const target, std::string const replacement)
{
	std::string	newContent;

	for (size_t i = 0; i < content.length();) {
		if (content.std::string::compare(i, target.length(), target) == 0) {
			newContent.std::string::append(replacement);
			i += target.std::string::length();
		}
		else {
			newContent.std::string::push_back(content[i]);
			i++;
		}
	}

	content = newContent;
}
bool	File::load(std::string const sourceFileName)
{
	std::ifstream	stream(sourceFileName.c_str(), std::iostream::in);

	if (!stream.std::ifstream::is_open()) {
		std::cout << "An error occured during " << sourceFileName << " opening" << std::endl;
		return FAILURE;
	}

	std::string content((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

	this->content = content;
	return SUCCESS;
}
bool	File::stream(std::string const &destinationFileName) const
{
	std::ofstream	stream(destinationFileName.c_str(), std::iostream::out);

	if (!stream.std::ofstream::is_open()) {
		std::cout << "An error occured during " << destinationFileName << " opening" << std::endl;
		return FAILURE;
	}

	stream.std::ostream::write(content.c_str(), content.length());
	return SUCCESS;
}
