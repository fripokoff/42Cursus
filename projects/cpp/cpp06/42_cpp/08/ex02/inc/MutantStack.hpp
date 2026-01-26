/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:35:46 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <deque>
# include <stack>

template <typename Content, class Container = std::deque<Content> >
class MutantStack : public std::stack<Content, Container>
{
	public:
		/* >------ Cons/Destructors ------< */
		MutantStack() {}
		MutantStack(MutantStack const & other)
		: std::stack<Content, Container>(other) {}
		~MutantStack() {}
		
		/* >------ Overloads ------< */
		MutantStack&	operator=(MutantStack const & other) {
			this->std::stack<Content, Container>::operator=(other);
			return *this;
		}

		typedef typename Container::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

#endif