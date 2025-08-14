/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:29 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 10:59:49 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

    private:
        const int _val;
        static const int _fractBits = 8;

    public:
        /*Canonical*/
        Fixed();
        Fixed( const Fixed & o );
        Fixed & operator=(const Fixed & o);
        ~Fixed();

        /*Accessors*/
        int getRawBits( void ) const;
        void setRawBits (int const raw);
};

#endif