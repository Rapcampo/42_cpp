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

void Account::_displayTimestamp(void);

Account::Account(void){
	return;
}

Account::~Account(void){
	return;
}

void Account::makeDeposit(int deposit);

bool Account::makeWithdrawal(int withdrawal);

Account::Account(int initial_deposit);

void Account::displayAccountsInfos(void);

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

//note: need to figure out from logs still
void Account::displayStatus(void) const {
	return;
}
