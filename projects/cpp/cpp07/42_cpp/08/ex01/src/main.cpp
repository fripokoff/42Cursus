/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:16 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>

#include "Span.hpp"

// int main() {

// 	std::cout << "\n----------------" << std::endl;
// 	/* Create Span */
// 	Span mySpan(15000);


// 	std::cout << "\n----------------" << std::endl;
// 	/* Try to find the shortestSpan and the longestSpan */
// 	try {
// 		int shortest = mySpan.shortestSpan();
// 		std::cout << "Shortest: " << shortest << std::endl;
// 		int longest = mySpan.longestSpan();
// 		std::cout << "Longest: " << longest << std::endl;
// 	}
// 	catch (...) {
// 		std::cout << "Couldn't find the short/longest" << std::endl;
// 	}


// 	std::cout << "\n----------------" << std::endl;
// 	/* Try to add numbers from -20000 to 20000 included */
// 	int i = 0;
// 	try {
// 		for (i = -20000; i <= 20000; ++i) {
// 			if (i % 2 == 0)
// 				mySpan.addNumber(i);
// 		}
// 	}
// 	catch (std::exception) {
// 		std::cout << "Couldn't add the value " << i << std::endl;
// 	}


// 	std::cout << "\n----------------" << std::endl;
// 	/* Try to find the shortestSpan and the longestSpan */
// 	try {
// 		int shortest = mySpan.shortestSpan();
// 		std::cout << "Shortest: " << shortest << std::endl;
// 		int longest = mySpan.longestSpan();
// 		std::cout << "Longest: " << longest << std::endl;
// 	}
// 	catch (...) {
// 		std::cout << "Couldn't find the short/longest" << std::endl;
// 	}


// 	std::cout << "\n----------------" << std::endl;
// 	return 0;
// }


int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}