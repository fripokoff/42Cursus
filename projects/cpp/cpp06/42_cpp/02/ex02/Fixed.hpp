/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:02:11 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	fractionalBitsNb = 8;

	public:
		/* OCCF */
		Fixed();
		~Fixed();
		Fixed(Fixed const &operand);


		Fixed(int const value);
		Fixed(float const value);

		/* Others */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const; 

		static Fixed		&min(Fixed &it1, Fixed &it2);
		static const Fixed	&min(Fixed const &it1, Fixed const &it2);
		static Fixed		&max(Fixed &it1, Fixed &it2);
		static const Fixed	&max(Fixed const &it1, Fixed const &it2);


		/* Overloads */
		Fixed	&operator=(Fixed const &operand);

		Fixed	operator+(Fixed const &operand);
		Fixed	operator-(Fixed const &operand);
		Fixed	operator*(Fixed const &operand);
		Fixed	operator/(Fixed const &operand);

		bool	operator<(Fixed const &operand);
		bool	operator<=(Fixed const &operand);
		bool	operator>(Fixed const &operand);
		bool	operator>=(Fixed const &operand);
		bool	operator==(Fixed const &operand);
		bool	operator!=(Fixed const &operand);

		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
};

std::ostream	&operator<<(std::ostream &outputStream, const Fixed& fixed);


#endif