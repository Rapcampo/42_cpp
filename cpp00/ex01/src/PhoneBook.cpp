/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:56:53 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/08 15:13:51 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"
#include <iomanip>

PhoneBook::PhoneBook(){
	Contact contact[MAX_CONTACTS];
	this->entries = 0;
	this->contactSize = 0;
}

PhoneBook::~PhoneBook(){
	return;
}

void	PhoneBook::addContact(std::string fn, std::string ln, std::string nn,
				std::string pn, std::string ds){
	if (entries < MAX_CONTACTS)
	{
		contact[entries] = Contact(fn, ln, nn, pn, ds);
		entries++;
	}
	else {
		contact[0] = Contact(fn, ln, nn, pn, ds);
		entries = 1;
	}
	if (contactSize < MAX_CONTACTS)
		contactSize++;
}

int		PhoneBook::getSize() const {
	return this->contactSize;
}

void	PhoneBook::getInfo() const {
	int	i = 0;
	std::cout << "\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[0m\n";
	std::cout << "\e[1;35m|\e[1;33m     \e[4mindex\e[0;39m\e[1;35m|\e[1;4;33mFirst Name\e[0;39m\e[1;35m|\e[1;33m \e[4mLast Name\e[0;39m\e[1;35m|\e[1;33m  \e[4mNickname\e[0m\e[1;35m|\e[0m\n";
	std::cout << "\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[0m\n";
	while (contactSize > i){
		std::cout << "\e[1;35m|\e[0m" << std::setw(10);
		std::cout << i + 1;
		std::cout << "\e[1;35m|\e[0m";
		if (contact[i].getFirstName().length() > 10)
			std::cout << std::setw(9) << contact[i].getFirstName().substr(0,9) << ".";
		else
			std::cout << std::setw(10) << contact[i].getFirstName();
		std::cout << "\e[1;35m|\e[0m";
		if (contact[i].getLastName().length() > 10)
			std::cout << std::setw (9) << contact[i].getLastName().substr(0,9) << ".";
		else
			std::cout << std::setw(10) << contact[i].getLastName();
		std::cout << "\e[1;35m|\e[0m";
		if (contact[i].getNickName().length() > 10){
			std::cout << std::setw(9) << contact[i].getNickName().substr(0,9) << ".";
			std::cout << "\e[1;35m|\e[0m" << std::endl;
		}
		else
			std::cout << std::setw(10) << contact[i].getNickName() << "\e[1;35m|\e[0m" << std::endl;
		std::cout << "\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[0m\n";
		i++;
	}
}
