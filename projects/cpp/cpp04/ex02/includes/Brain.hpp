/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:10:34 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 21:05:36 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{

    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain &o);
        Brain &operator=(const Brain &o);
        ~Brain();

        const std::string &getIdea(int index) const;
        void setIdea(int index, std::string idea);
};

#endif