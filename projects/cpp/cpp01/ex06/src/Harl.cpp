/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:23:14 by kpires            #+#    #+#             */
/*   Updated: 2025/07/24 12:29:30 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";
}

Harl::~Harl() {}

void Harl::switchCase(int id){
    switch (id) {
        case 1:
            Harl::debug();
        case 2:
            Harl::info();
        case 3:
            Harl::warning();
        case 4:
            Harl::error();
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return ;
}

void Harl::complain(std::string level){

    bool found = false;
    for(int i = 0; i < 4; i++){
        if (level == this->levels[i] || found){
            switchCase(i + 1);
            found = true;
            return ;
        }
    }
    switchCase(0);
    return ;
}

void Harl::debug ( void ){
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void) {
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) {
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}