/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:43 by kpires            #+#    #+#             */
/*   Updated: 2026/01/29 12:04:20 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <unistd.h>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ctime>

int main()
{

    srand(time(0));

    std::cout << "=== TEST 1: Invalid Bureaucrat Creation ===" << std::endl;
    try
    {
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat invalid("Invalid", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 2: Valid Bureaucrats ===" << std::endl;

    Bureaucrat  grade_1("Grade 1", 1);
    std::cout << grade_1 << std::endl;

    Bureaucrat  grade_20("Grade 20", 20);
    std::cout << grade_20 << std::endl;

    Bureaucrat  grade_80("Grade 80", 80);
    std::cout << grade_80 << std::endl;

    Bureaucrat  grade_150("Grade 150", 150);
    std::cout << grade_150 << std::endl << std::endl;


    PresidentialPardonForm    pardonForm("Bob");
    RobotomyRequestForm       robotomyForm("Snow");
    ShrubberyCreationForm     shrubberyForm("Angel");


    std::cout << "=== TEST 3: Execute UNSIGNED form ===" << std::endl;
    try
    {
        grade_1.executeForm(pardonForm);
    } catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 4: Signing Forms ===" << std::endl;
    try
    {
        grade_150.signForm(pardonForm);
        grade_80.signForm(pardonForm);
        grade_20.signForm(pardonForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try{
        grade_150.signForm(shrubberyForm);
        grade_80.signForm(shrubberyForm);
        grade_20.signForm(shrubberyForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try{
        grade_150.signForm(robotomyForm);
        grade_80.signForm(robotomyForm);
        grade_20.signForm(robotomyForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 5: Execute with insufficient grade ===" << std::endl;
    try
    {
        grade_150.executeForm(pardonForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        grade_80.executeForm(pardonForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 6: Successful Executions ===" << std::endl;
    try
    {
        grade_1.executeForm(pardonForm);
        std::cout << std::endl;
        grade_20.executeForm(robotomyForm);
        std::cout << std::endl;
        grade_80.executeForm(shrubberyForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 7: Multiple robotomyForm attempts ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        try
        {
            grade_1.executeForm(robotomyForm);
        }
        catch (std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << std::endl;
        usleep(500000);
    }
    std::cout << std::endl;

    std::cout << "=== TEST 8: Execute UNSIGNED form (REAL EXCEPTION) ===" << std::endl;
    try
    {
        PresidentialPardonForm unsignedForm("Alice");
        grade_1.executeForm(unsignedForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}
