/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:59:03 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 13:08:09 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &o);
        WrongAnimal &operator=(const WrongAnimal &o);
        virtual ~WrongAnimal();

        void announce(std::string msg) const;
        virtual void makeSound() const;
        std::string getType() const;
        void setType(std::string newType);
};

#endif