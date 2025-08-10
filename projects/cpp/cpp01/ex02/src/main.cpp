/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:40:01 by kpires            #+#    #+#             */
/*   Updated: 2025/08/10 20:35:29 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){

    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "MEMORY ADDRESS :" << std::endl;
    std::cout << "str : " << &str << std::endl;
    std::cout <<  "stringPTR : " << stringPTR << std::endl;
    std::cout << "stringREF : " << &stringREF << std::endl;

    std::cout << "---------------" << std::endl;
    std::cout << "Values :" << std::endl;
    std::cout << "str : " << str << std::endl;
    std::cout <<  "stringPTR : " << *stringPTR << std::endl;
    std::cout << "stringREF : " << stringREF << std::endl;

    std::cout << "---------------" << std::endl;
    std::cout << "REF MODIFIED :" << std::endl;
    stringREF = "Modified";
    std::cout << "stringREF : " << stringREF << std::endl;
    std::cout <<  "stringPTR : " << *stringPTR << std::endl;
    std::cout << "str : " << str << std::endl;
    return (0);
}