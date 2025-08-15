/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:09:41 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 13:06:51 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

    protected:
        std::string type;
    
    public:
        WrongCat( void );
        WrongCat(const WrongCat &o);
        WrongCat &operator=(const WrongCat &o);
        ~WrongCat();

        void makeSound( void ) const;
};

#endif