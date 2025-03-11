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

PhoneBook::PhoneBook(){
	Contact contact[MAX_CONTACTS];
	this->entries = 0;
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
}

void	PhoneBook::getInfo() const {
//	int	i = 0;
	std::cout << "\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[0m\n";
	std::cout << "\e[1;35m|\e[1;36m     index\e[1;35m|\e[1;36mFirst Name\e[1;35m|\e[1;36m Last Name\e[1;35m|\e[1;36m  Nickname\e[1;35m|\e[0m\n";
	std::cout << "\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[1;32m----------\e[1;35m+\e[0m\n";
//	while (entries > i){
//		std::cout << i;
//	}
}
