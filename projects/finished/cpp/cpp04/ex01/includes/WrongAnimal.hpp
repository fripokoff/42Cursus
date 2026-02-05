/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:59:03 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 13:14:02 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

    protected:
        std::string _type;
    
    public:
        WrongAnimal( void );
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &o);
        WrongAnimal &operator=(const WrongAnimal &o);
        virtual ~WrongAnimal();

        void announce(std::string msg) const;
        void makeSound( void ) const;
        const std::string &getType( void ) const;
};

#endif