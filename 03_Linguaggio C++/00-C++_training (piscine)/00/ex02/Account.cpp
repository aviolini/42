/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:15:04 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/18 09:29:36 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount<< ";";
	std::cout << "created" << std::endl;
}
Account::Account()
{
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}
Account::~Account(void)
{
   _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
      _displayTimestamp();
      std::cout << "accounts:" << Account::_nbAccounts << ";";
      std::cout << "total:" << Account::_totalAmount << ";";
      std::cout << "deposits:" << Account::_totalNbDeposits << ";";
      std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
      std::cout << std::endl;
}
void	Account::makeDeposit( int deposit )
{
   _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
   std::cout << "deposit:" << deposit << ";"; 
   this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
   std::cout << "nb_deposits:" << ++this->_nbDeposits <<";";
   _totalNbDeposits++;
   _totalAmount += deposit;
   std::cout << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
   _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
   std::cout << "withdrawal:";
   if (withdrawal > this->_amount)
   {
      std::cout << "refused";
      std::cout << std::endl;
      return (false);
   }
   std::cout << withdrawal << ";";
   this->_amount -= withdrawal; 
	std::cout << "amount:" << this->_amount << ";";
   std::cout << "nb_withdrawal:" << ++this->_nbWithdrawals <<";";
   _totalNbWithdrawals++;
   _totalAmount -= withdrawal;
   std::cout << std::endl;
	return (true);	
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
   std::cout << std::endl;
}

void Account::_displayTimestamp( void )
{
   time_t now = time(0);
   tm *ltm = localtime(&now);
   
   std::cout << "[";
   std::cout << 1900 + ltm->tm_year;
   std::cout << 1 + ltm->tm_mon;
   std::cout << ltm->tm_mday;
   std::cout << "_";
   std::cout << ltm->tm_hour;
   std::cout << ltm->tm_min;
   std::cout << ltm->tm_sec;
   std::cout << "] ";
}
