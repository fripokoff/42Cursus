/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
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

# define DATA_DEFAULT	"data.csv"
# define INPUT_DEFAULT	"input.txt"

# include <exception>
# include <string>
# include <map>

class Date
{
	public:
		/* >------ Cons/Destructors ------< */
		Date() : _year(0), _month(0), _day(0) {}
		Date(int year, int month, int day)
		: _year(year), _month(month), _day(day) {}
		Date(Date const & other)
		: _year(other._year), _month(other._month), _day(other._day) {}
		~Date() {}
		
		/* >------ Overloads ------< */
		Date&	operator=(Date const & other) {
			_year = other._year;
			_month = other._month;
			_day = other._day;

			return *this;
		}
		bool	operator<(Date const & other) const {
			if (_year < other._year
				|| (_year == other._year && _month < other._month)
				|| (_year == other._year && _month == other._month
					&& _day < other._day))
					return true;
			return false;
		}
		int operator--() {
			if (_day > 0)
				_day--;
			else if (_month > 0) {
				_day = 31;
				_month--;
			}
			else if (_year > 0) {
				_day = 31;
				_month = 12;
				_year--;
			}
			else
				return false;
			return true;
		}

		/* >------ Getters ------< */
		int	getYear() const { return _year; }
		int	getMonth() const { return _month; }
		int	getDay() const { return _day; }

	private:
		int	_year;
		int	_month;
		int	_day;
};

class BitcoinExchange
{
	public:
		/* >------ Cons/Destructors ------< */
		BitcoinExchange();
		BitcoinExchange(
			std::string const & coinTrackerFile,
			std::string const & belongingsTrackerFile);
		BitcoinExchange(BitcoinExchange const & other);
		~BitcoinExchange() {}
		
		/* >------ Overloads ------< */
		BitcoinExchange&	operator=(BitcoinExchange const & other);

		/* >------ Trackers ------< */
		void				trackCoin(std::string const & coinTrackerFile);
		void				trackBelongings(std::string const & belongingsTrackerFile);
		double				closestValue(Date it);

		/* >------ Exceptions ------< */
		class BitcoinException : public std::exception {
			public:
				BitcoinException(std::string const &type) throw() : _type(type), _message("[ERROR] " + type) {}
				~BitcoinException() throw() {}
				const char*	what() const throw() {
					return _message.c_str();
				}

			private:
				std::string	_type;
				std::string	_message;
		};

	private:
		std::map<Date, double>	_coinTracker;
		void build(	std::string const & coinTrackerFile,
					std::string const & belongingsTrackerFile);
};

#endif