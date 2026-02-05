/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:40:01 by kpires            #+#    #+#             */
/*   Updated: 2025/07/24 12:29:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl{

    public:
        Harl();
        void complain(std::string level);
        void switchCase(int id);
        ~Harl();
    
    private:
        void debug ( void );
        void info ( void );
        void warning ( void );
        void error( void );
        std::string levels[4];
};