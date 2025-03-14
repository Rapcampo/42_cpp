/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:24:08 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/13 21:48:03 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

//todo:: make prototypes for all the functions to be implemented
//to get a foothold of the problem at hand;
//

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void){
	std::time_t t = std::time(NULL);
	std::tm *tm = std::localtime(&t);
	std::cout << "[" << std::setfill('0') << std::setw(4) << (tm->tm_year + 1900)
		<< std::setfill('0') << std::setw(2) << (tm->tm_mon + 1) << std::setfill('0')
		<< std::setw(2) << tm->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << tm->tm_hour <<std::setfill('0')
		<< std::setw(2) << tm->tm_sec << std::setfill('0') << std::setw(2)
		<< tm->tm_sec << "] ";
}

Account::Account(void){
	return;
}

//needs print time, index, amount from initial dep and "created"
Account::Account(int initial_deposit);

//needs to print time, index number and amount in account, followed by status "closed"
Account::~Account(void){
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" << "amount:"
		<< Account::_amount << ";" << "closed";
	return;
}

//prints index, previous amount, amound deposited, current and global deposit
void Account::makeDeposit(int deposit);

//should return boolean if amount in account is enough for withdrawal??
//prints index of previous amount, amount w, current amount and global nb of with
bool Account::makeWithdrawal(int withdrawal);

//prints time, index, current balance, nb deposits, nb with;
void Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	for (i < Account::getNbAccounts();
}

int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

//note: need to figure out from logs still, likely used by display accounts info
//likely prints both deposits and with
void Account::displayStatus(void) const {
	return;
}
