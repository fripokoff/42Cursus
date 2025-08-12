/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:09:41 by kpires            #+#    #+#             */
/*   Updated: 2025/08/12 13:11:26 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

    protected:
        std::string type;
    
    public:
        WrongCat();
        WrongCat(const WrongCat &o);
        WrongCat &operator=(const WrongCat &o);
        ~WrongCat();

        void makeSound() const;
};

#endif