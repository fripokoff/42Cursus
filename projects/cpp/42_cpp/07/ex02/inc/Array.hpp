/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:08:45 by kpires            #+#    #+#             */
/*   Updated: 2026/02/04 15:01:41 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T>
class Array {
	public:
		/* Constructors/Destructor */
		Array() : _array(new T[0]), _size(0) {}
		
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		
		Array(Array const & other) 
		: _array(new T[other._size]), _size(other._size) {
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		
		~Array() { delete[] _array; }

		/* Assignment operator */
		Array& operator=(Array const & other) {
			if (this != &other) {
				delete[] _array;
				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return *this;
		}

		/* Accessors */
		unsigned int size() const { return _size; }
		
		T& operator[](unsigned int i) {
			if (i >= _size)
				throw OutOfBoundsException();
			return _array[i];
		}
		
		T const& operator[](unsigned int i) const {
			if (i >= _size)
				throw OutOfBoundsException();
			return _array[i];
		}

		/* Exception class */
		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Index out of bounds";
				}
		};

	private:
		T* _array;
		unsigned int _size;
};

template <typename T>
std::ostream& operator<<(std::ostream& o, Array<T> const& rhs) {
	for (unsigned int i = 0; i < rhs.size(); i++)
		o << rhs[i] << " ";
	return o;
}

#endif