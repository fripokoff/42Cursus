/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:20:26 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

/* Static Member Variables */
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


/* Static Member Functions: */
int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();

	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}
void	Account::_displayTimestamp( void )
{
	/* Get the current time (secs), fill the localTime struct with it */
    std::time_t	now = std::time(NULL);
    std::tm		*localTime = std::localtime(&now);

	/* Fill the buffer with localTime variables in right format */
 	char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", localTime);
	std::cout << buffer;
}


/* Constructor-Destructor */
Account::Account( int initial_deposit )
{
	_displayTimestamp();

	/* Set account's variables */
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	/* Update static member variables */
	_nbAccounts += 1;
	_totalAmount += _amount;

	/* Announce construction */
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}
Account::Account( void )
{
	_displayTimestamp();

	/* Set account's variables */
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	/* Update static member variables */
	_nbAccounts += 1;
	_totalAmount += _amount;

	/* Announce construction */
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}
Account::~Account( void )
{
	_displayTimestamp();

	/* Announce destruction */
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;

	/* Update static member variables */
	_nbAccounts -= 1;
	_totalAmount -= _amount;
}


/* Setters */
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();

	/* Update account's variables */
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;

	/* Announce deposit */
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount - deposit << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();

	/* Update account's variables */
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;

	int	withdrawalAccepted = this->checkAmount();
	if (!withdrawalAccepted) {
		this->_amount += withdrawal;
		_totalAmount += withdrawal;
		this->_nbWithdrawals -= 1;
		_totalNbWithdrawals -= 1;
	}

	/* Announce deposit */
	std::cout << "index:" << _accountIndex << ";";
	if (!withdrawalAccepted) {
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
	}
	else {
		std::cout << "p_amount:" << _amount + withdrawal << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return withdrawalAccepted;
}
int		Account::checkAmount( void ) const
{
	return (_amount >= 0) ? true : false;
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
