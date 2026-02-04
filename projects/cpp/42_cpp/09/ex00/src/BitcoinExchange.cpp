/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:04 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LEFT_NAME				"date"
#define COIN_RIGHT_NAME			"exchange_rate"
#define BELONGINGS_RIGHT_NAME	"value"

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#include "BitcoinExchange.hpp"

/* >----------- Parsing -----------< */
static std::map<int, std::string> fileToMap(std::string const & file) {
	std::map<int, std::string> fileContent;

	std::ifstream fileStream;
	fileStream.open(file.c_str(), std::ifstream::in);

	if (fileStream.is_open() == false)
		throw std::exception();

	std::string	line;
	int			key = 0;
	while (getline(fileStream, line))
		fileContent[key++] = std::string(line);

	fileStream.close();
	return fileContent;
}

static std::string getSeparator(std::string const & source,
								std::string const & leftColumn,
								std::string const & rightColumn) {

	std::size_t	leftIndex = source.find(leftColumn);
	std::size_t	rightIndex = source.find(rightColumn);

	if (leftIndex == std::string::npos || rightIndex == std::string::npos
		|| leftIndex + leftColumn.length() >= rightIndex)
		throw BitcoinExchange::BitcoinException(source + " : header is incorrect");

	return source.substr(leftIndex + leftColumn.length(), 
						rightIndex - leftColumn.length());
}

static Date strToKey(std::string const & str) {
	if (str.length() != 10 || str[4] != '-' || str[7] != '-')
		throw BitcoinExchange::BitcoinException(str + " : not \"XXXX-XX-XX\" format");

	std::string::const_iterator it;
	for (it = str.begin(); it != str.end(); ++it) {
		if (it - str.begin() != 4 && (it - str.begin() != 7) && !isdigit(*it))
			throw BitcoinExchange::BitcoinException(str + " : invalid/unrealistic date");
	}

	long year = strtod(str.c_str(), NULL);
	long month = strtod(&str[5], NULL);
	long day = strtod(&str[8], NULL);

	if (year <= 0 || month <= 0 || day <= 0)
		throw std::exception();
	if (month > 12 || day > 31)
		throw BitcoinExchange::BitcoinException(str + " : invalid/unrealistic date");

	return Date(year, month, day);
}

static double strToValue(std::string const & str, int isInput) {
	char *strPtr;
	double value = strtod(str.c_str(), &strPtr);
	if (*strPtr != '\0')
		throw BitcoinExchange::BitcoinException(str + " : bad input");

	if (value < 0)
		throw BitcoinExchange::BitcoinException(str + " : not a positive number");

	if (isInput && value > 1000.0)
		throw BitcoinExchange::BitcoinException(str + " : too large number");

	return value;
}

std::string formatDate(Date it) {
    std::ostringstream oss;

    // Set padding for the year (4 digits)
    oss << std::setw(4) << std::setfill('0') << it.getYear() << '-';

    // Set padding for the month (2 digits)
    oss << std::setw(2) << std::setfill('0') << it.getMonth() << '-';

    // Set padding for the day (2 digits)
    oss << std::setw(2) << std::setfill('0') << it.getDay();

    return oss.str();
}
/* <----------------------------> */


/* >----------- Cons/Destructors -----------< */
BitcoinExchange::BitcoinExchange() {
	this->build(DATA_DEFAULT, INPUT_DEFAULT);
}

BitcoinExchange::BitcoinExchange(
	std::string const & coinTrackerFile,
	std::string const & belongingsTrackerFile) {
	this->build(coinTrackerFile, belongingsTrackerFile);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other) {
	*this = other;
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other) {
	_coinTracker = other._coinTracker;
	return *this;
}
/* <----------------------------> */


/* >----------- Trackers -----------< */
void BitcoinExchange::trackCoin(std::string const & coinTrackerFile) {
	std::map<int, std:: string>	content = fileToMap(coinTrackerFile);

	std::string leftColumn = LEFT_NAME, rightColumn = COIN_RIGHT_NAME;
	std::string separator = getSeparator(content[0], leftColumn, rightColumn);

	content.erase(0);

	std::map<int, std::string>::const_iterator it;
	for (it = content.begin(); it != content.end(); ++it) {
		if (it->second.find(separator) == std::string::npos
			|| it->second.find(separator) != it->second.rfind(separator))
			throw BitcoinException(it->second + " : bad input");

		std::string	left = it->second.substr(0, it->second.find(separator));
		std::string	right = it->second.substr(it->second.find(separator) + separator.length(),
			it->second.length() - it->second.find(separator) + separator.length());

		Date	key = strToKey(left);
		double	value = strToValue(right, false);

		_coinTracker.insert(std::make_pair(key, value));
	}
}

void BitcoinExchange::trackBelongings(std::string const & belongingsTrackerFile) {
	std::map<int, std:: string>	content = fileToMap(belongingsTrackerFile);
	std::string separator = getSeparator(content[0], LEFT_NAME, BELONGINGS_RIGHT_NAME);

	content.erase(0);

	std::map<int, std::string>::const_iterator it;
	for (it = content.begin(); it != content.end(); ++it) {
		try {
			if (it->second.find(separator) == std::string::npos
				|| it->second.find(separator) != it->second.rfind(separator))
				throw BitcoinException(it->second + " : bad input");

			std::string	left = it->second.substr(0, it->second.find(separator));
			std::string	right = it->second.substr(it->second.find(separator) + separator.length(),
				it->second.length() - it->second.find(separator) + separator.length());

			Date	key = strToKey(left);
			double	value = strToValue(right, true);
			double	exchangeRate = closestValue(key);

			if (exchangeRate * value > std::numeric_limits<double>::max())
				throw BitcoinException(it->second + " : \"value * exchangeRate\" is a too big number");

			/* print "YEAR-MONTH-DAY => belongingsQuantity = belongingsValue "*/
			double result = exchangeRate * value;
			if (result == static_cast<double>(static_cast<int>(result))) {
				std::cout << formatDate(key) << " => " << value << " = " << static_cast<int>(result) << std::endl;
			} else {
				std::cout << formatDate(key) << " => " << value << " = " << result << std::endl;
			}
		}
		catch (BitcoinException const & e) {
			std::cout << e.what() << std::endl;
		}
	}
}

double BitcoinExchange::closestValue(Date it) {
	try {
		if (_coinTracker[it])
			return _coinTracker[it]; 
	} catch (...) {}

	while (--it == true) {
		try {
			if (_coinTracker[it])
				return _coinTracker[it]; 
		} catch (...) {}
	}
	return _coinTracker.begin()->second;
}
/* <----------------------------> */


/* >----------- Private -----------< */
void	BitcoinExchange::build(
	std::string const & coinTrackerFile,
	std::string const & belongingsTrackerFile) {

	try {
		trackCoin(coinTrackerFile);
		trackBelongings(belongingsTrackerFile);
	}
	catch (BitcoinException const & e) {
		std::cout << e.what() << std::endl;
	}
}
/* <----------------------------> */
