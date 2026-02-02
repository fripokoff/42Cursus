/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:43 by kpires            #+#    #+#             */
/*   Updated: 2026/01/28 12:40:38 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int main()
{
	Bureaucrat  b1("Jean", 20);
    Bureaucrat  b2("Edward", 5);


    Form        form1("Form1", 30, 1);
    Form        form2("Form2", 10, 1);

	std::cout << std::endl << form1 << std::endl << form2 << std::endl;

    //invalid high grade
    try
    {
        Bureaucrat  invalidGrade("Jack", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to create bureaucrat because " << e.what() << std::endl;
    }

    //invalid low grade
    try
    {
        Bureaucrat  invalidGrade("Jack", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to create bureaucrat because " << e.what() << std::endl << std::endl;
    }

    //invalid high exec grade
    try
    {
        Form        invalid1("Form3", 149, 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to create Form3 because " << e.what() << std::endl;

        //invalid low exec grade
        try
        {
            Form        invalid2("Form4", 149, 151);
        }
        catch (std::exception& e)
        {
            std::cout << "Unable to create Form4 because " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;

    try
    {
        b2.signForm(form1);
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to sign form because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        b1.signForm(form1);
        b1.signForm(form2);
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to sign form because " << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    try
    {
        b2.signForm(form2);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

   

	std::cout << std::endl << form1 << std::endl << form2 << std::endl;

	return 0;
}