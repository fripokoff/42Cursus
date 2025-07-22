/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:47:15 by kpires            #+#    #+#             */
/*   Updated: 2025/07/13 14:46:46 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( int ac, char **av)
{
    int j;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < ac ; i++){
        j = 0;
        while(av[i][j]){
            std::cout << (char)std::toupper(av[i][j]);
            j++;
        }
    }
    std::cout << std::endl;
    return (0);
}
