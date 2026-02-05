/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:40:01 by kpires            #+#    #+#             */
/*   Updated: 2025/08/11 20:18:57 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

/* std::ifstream Input file stream. Used to read data from files. */
/* std::ofstream Output file stream. Used to write data to files. */
/* ostringstream Output string stream. Used to write data into a string buffer (in memory), */
/* just like writing to a file or console, but the result is stored in a std::string. */

int main(int ac, char **av){

    if(ac != 4){
        std::cerr << "Usage <filename> s1 s2" << std::endl;
        return (1);
    }

    std::string filename = av[1];
    std::string str = av[2];
    std::string toreplace = av[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        return (std::cerr << "Error: Could not open file " << filename << std::endl, 1);

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        inputFile.close();
        return (std::cerr << "Error: Could not create file " << filename << ".replace" << std::endl, 1);
    }
    
    std::ostringstream buff;
    buff << inputFile.rdbuf();

    std::string content = buff.str();
    outputFile << cus_replace(content, str, toreplace);

    inputFile.close();
    outputFile.close();

    return (0);
}
