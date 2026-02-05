/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:10:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/15 13:05:43 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{

    private:
		  Brain *_brain;

    public:
        Cat( void );
        Cat(const Cat &o);
        Cat &operator=(const Cat &o);
        ~Cat();

        void makeSound( void ) const;
        Brain *getBrain( void ) const;
};

#endif