/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:55:02 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "File.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Wrong arguments" << std::endl;
		std::cout << "Must be: [filename] [string_target] [string_replacement]" << std::endl;
	}
	else {
		std::string	source = argv[1];

		File sourceFile(source);
		sourceFile.File::load(sourceFile.getName());
		sourceFile.File::replace((std::string) argv[2], (std::string) argv[3]);
		sourceFile.File::stream(source + ".replace");
	}
}
