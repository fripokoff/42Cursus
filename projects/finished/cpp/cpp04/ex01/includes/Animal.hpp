/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:10:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 13:13:51 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{

    protected:
        std::string _type;

    public:
        Animal( void );
        Animal(std::string type);
        Animal(const Animal &o);
        Animal &operator=(const Animal &o);
        virtual ~Animal();

        void announce(std::string msg) const;
        virtual void makeSound( void )const;
        const std::string &getType( void ) const;
};

#endif