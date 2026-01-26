/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:43 by kpires            #+#    #+#             */
/*   Updated: 2026/01/12 15:27:06 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat  b1("Jean", 5);
    Bureaucrat  b2("Edward", 147);


    std::cout << std::endl << "=== First try -> Incrementing the grade ===" << std::endl;
    try
    {
        while (true)
        {
            std::cout << b1 << std::endl;
            b1.upGrade();
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to increment grade: " << e.what() << std::endl;
    }


    std::cout << std::endl << "=== Second try -> Decrementing the grade ===" << std::endl;
    try
    {
        while (true)
        {
            std::cout << b2 << std::endl;
            b2.downGrade();
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to increment grade: " << e.what() << std::endl;
    }
    std::cout << std::endl;

	return 0;
}