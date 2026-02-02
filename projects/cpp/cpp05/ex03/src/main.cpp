/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:43 by kpires            #+#    #+#             */
/*   Updated: 2026/01/28 14:36:44 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>

int main()
{
    srand(time(0));
    
    Intern intern;
    Bureaucrat bigBoss("BigBoss", 1);
    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;
    AForm* form4 = NULL;



    std::cout << std::endl << "=== TEST 1: Create valid forms ===" << std::endl << std::endl;
    try
    {
        form1 = intern.makeForm("shrubbery creation", "Tree");
    }
    
    catch (std::exception& e)
    {
        std::cout << "Exception throw " << e.what() << std::endl << std::endl;
    }

    try
    {
        form2 = intern.makeForm("robotomy request", "Android");
    }
    catch (std::exception& e)
    {
        std::cout << "Exception throw " << e.what() << std::endl << std::endl;
    }

    try
    {
        form3 = intern.makeForm("presidential pardon", "ZigBee");

    }
    catch (std::exception& e)
    {
        std::cout << "Exception throw " << e.what() << std::endl << std::endl;
    }

    std::cout << std::endl << "=== TEST 2: Create unknown form ===" << std::endl;
    try
    {
        form4 = intern.makeForm("coffee request", "GoodGuy");
    }
    catch (std::exception& e)
    {
        std::cout << "Exception throw " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== TEST 3: Use created forms ===" << std::endl << std::endl;

    AForm* forms[4] = {form1, form2, form4, form3};

    for(int i =0; i < 4; i++)
    {
        if(forms[i])
        {
            std::cout << "Form " << *forms[i] << std::endl;
            bigBoss.signForm(*forms[i]);
            bigBoss.executeForm(*forms[i]);
            std::cout << std::endl << "Form " << *forms[i] << std::endl;
            std::cout << "========================" << std::endl << std::endl;
        }
    }

    delete form1;
    delete form2;
    delete form3;
    delete form4;
    return 0;
}
