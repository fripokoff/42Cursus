/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:10 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <exception>
# include <string>
# include <stack>

class RPN
{
	public:
		/* >------ Cons/Destructors ------< */
		RPN() {}
		RPN(RPN const & other) {
			*this = other;
		}
		~RPN() {}
		
		/* >------ Overloads ------< */
		RPN&	operator=(RPN const & other) {
			_numbers = other._numbers;
			return *this;
		}

		int		getSize() { return _numbers.size(); }

		/* >------ Operations ------< */
		void	addNumber(double number);
		void	operate(char it);
		double	getResult();

		/* >------ Exceptions ------< */
		class Exception : public std::exception {
			public:
				Exception(std::string const &type) throw() : _type(type) {}
				~Exception() throw() {}
				const char*	what() const throw() {
					return _type.c_str();
				}

			private:
				std::string	_type;
		};


	private:
		std::stack<double> _numbers;
};

#endif