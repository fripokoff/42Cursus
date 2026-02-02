/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:08:45 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename Type> class Array
{
	public:
		/* >------ Cons/Destructors ------< */
		Array() : _array(new Type[0]()), _size(0) {}
		Array(int size) : _array(new Type[size]()), _size(size) {}
		Array(Array const & other)
		: _array(new Type[other._size]), _size(other._size) {
			for (int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		~Array() { delete[] _array; }

		/* >------ Overloads ------< */
		Array&	operator=(Array const & other) {
			delete[] _array;
			_size = other._size;
			_array = new Type[_size];

			for (int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}

		/* >------ Getters ------< */
		int		getSize() const { return _size; }
		Type& operator[](int i) const {
			if (i >= _size)
				throw std::exception();
			return _array[i];
		}

	private:
		Type*	_array;
		int		_size;		
};

#endif