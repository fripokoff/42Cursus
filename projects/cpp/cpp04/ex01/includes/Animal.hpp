/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:10:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 13:10:45 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{

    protected:
        std::string type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &o);
        Animal &operator=(const Animal &o);
        virtual ~Animal();

        void announce(std::string msg) const;
        virtual void makeSound()const;
        std::string getType() const;
        void setType(std::string newType);
};

#endif