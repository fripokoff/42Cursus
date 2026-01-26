/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:31:43 by kpires            #+#    #+#             */
/*   Updated: 2026/01/20 17:53:01 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    srand(time(0));
    
    Intern intern;
    Bureaucrat bigBoss("BigBoss", 1);
    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;
    AForm* form4 = NULL;

    (void)form4;

    std::cout << std::endl << "=== TEST 1: Create valid forms ===" << std::endl << std::endl;
    try
    {
        form1 = intern.makeForm("shrubbery creation", "Tree");
        std::cout << std::endl;
        form2 = intern.makeForm("robotomy request", "Android");
        std::cout << std::endl;
        form3 = intern.makeForm("presidential pardon", "ZigBee");
        std::cout << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "❌[MAIN]❌ Exception: " << e.what() << std::endl;
    }

    std::cout << "=== TEST 2: Create unknown form ===" << std::endl;
    try
    {
        form4 = intern.makeForm("coffee request", "GoodGuy");
    }
    catch (std::exception& e)
    {
        std::cout << "❌[MAIN]❌ Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 3: Use created forms ===" << std::endl;
    if (form1)
    {
        std::cout << "Form1: " << std::endl;
        bigBoss.signForm(*form1);
        bigBoss.executeForm(*form1);
        std::cout << std::endl;
    }
    if (form2)
    {
        std::cout << "Form2: " << std::endl;
        bigBoss.signForm(*form2);
        bigBoss.executeForm(*form2);
        std::cout << std::endl;
    }
    if (form3)
    {
        std::cout << "Form3: " << std::endl;
        bigBoss.signForm(*form3);
        bigBoss.executeForm(*form3);
    }
    std::cout << std::endl;
    delete form1;
    delete form2;
    delete form3;
    return 0;
}
