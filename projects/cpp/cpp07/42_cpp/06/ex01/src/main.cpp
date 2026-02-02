/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:08:05 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

void print(Data *it) {
	std::cout << "Char: " << it->letter << std::endl;
	std::cout << "Int: " << it->number << std::endl;
	std::cout << "Fractional: " << it->fractional << std::endl;
}

int main() {
	Data number = {
		'a',
		static_cast<int>('a'),
		static_cast<float>('a')
	};

	print(&number);
	Data* numberPtr = Serializer::deserialize(Serializer::serialize(&number));
	print(numberPtr);
}
