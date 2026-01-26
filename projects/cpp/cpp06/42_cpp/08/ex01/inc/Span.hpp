/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:59:40 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP

# define DEFAULT_MAX_SIZE 10

# include <vector>

class Span
{
	public:
		/* >------ Cons/Destructors ------< */
		Span();
		Span(unsigned int N);
		Span(Span const & other);
		~Span();
		
		/* >------ Other ------< */
		Span	&operator=(Span const & other);
		int		shortestSpan() const;
		int		longestSpan() const;

		/* Set/Getters */
		void	addNumber(int value);
		int		getMaxSize() const;

	private:
		std::vector<int>	_storage;
		unsigned int		_maxSize;
};

#endif