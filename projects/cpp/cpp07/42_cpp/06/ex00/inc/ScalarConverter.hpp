/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:32:58 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <exception>
# include <string>

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	FLOAT_EXCEPTION,
	DOUBLE_EXCEPTION,
	NONE
}	t_type;

typedef enum e_overflows {
	NO_OVERFLOW = 0,
	CHAR_OF = (1 << 0),
	INT_OF = (1 << 1),
	FLOAT_OF = (1 << 2),
	DOUBLE_OF = (1 << 3)
}	t_overflows;

typedef struct s_scalar {
	char	c;
	int		i;
	float	f;
	double	d;
	int		status;
}	t_scalar;

class ScalarConverter
{
	public:
		static void	convert(std::string &literal);

		class Type : public std::exception {};
		class Overflow : public std::exception {
			public:
				Overflow(std::string const &type) throw() : _type(type) {}
				~Overflow() throw() {}
				const char*	what() const throw() { return _type.c_str(); }

			private:
				std::string _type;
		};
};

#endif