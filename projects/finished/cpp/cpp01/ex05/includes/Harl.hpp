/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:40:01 by kpires            #+#    #+#             */
/*   Updated: 2025/07/23 18:42:42 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl{

    public:
        Harl();
        void complain(std::string level);
        ~Harl();
    
    private:
        void debug ( void );
        void info ( void );
        void warning ( void );
        void error( void );
        std::string levels[4];
        void (Harl::*complaints[4])(void);
};