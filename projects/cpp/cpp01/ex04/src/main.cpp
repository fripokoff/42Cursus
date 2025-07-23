/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:40:01 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 11:44:38 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int ac, char **av){

    if(ac != 4){
        std::cerr << "Usage <filename> s1 s2" << std::endl;
        return (1);
    }

    std::string filename = av[1];
    std::string str = av[2];
    std::string toreplace = av[3];

    //c_str convert to string
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        return (std::cerr << "Error: Could not open file " << filename << std::endl, 1);

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open())
        return (std::cerr << "Error: Could not create file " << filename << ".replace" << std::endl, 1);
    
    std::ostringstream buff;
    buff << inputFile.rdbuf();
    std::string content = buff.str();
    outputFile << cus_replace(content, str, toreplace);
    return (0);
}