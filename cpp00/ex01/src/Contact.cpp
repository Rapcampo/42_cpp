/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:37:14 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/08 15:42:15 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(){
	std::string fn = "";
	std::string ln = "";
	std::string nn = "";
	std::string pn = "";
	std::string ds = "";
}

Contact::~Contact(){
	return;
}

Contact::Contact(std::string fn, std::string ln, std::string nn,
		std::string pn,std::string ds){
	this->fn = fn;
	this->ln = ln;
	this->nn = nn;
	this->pn = pn;
	this->ds = ds;
}

void	Contact::setContact(std::string fn, std::string ln, std::string nn,
		std::string pn,std::string ds){
	this->fn = fn;
	this->ln = ln;
	this->nn = nn;
	this->pn = pn;
	this->ds = ds;
}

void	Contact::showContact() const {
	std::cout << "First Name: " << fn << std::endl;
	std::cout << "Last Name: " << ln << std::endl;
	std::cout << "Nickname: " << nn << std::endl;
	std::cout << "Phone Number: " << pn << std::endl;
	std::cout << "Darkest Secret: " << ds << std::endl;
}

std::string Contact::getFirstName() const{
	return (fn);	
}
std::string Contact::getLastName() const{
	return (ln);
}
std::string Contact::getNickName() const{
	return (nn);
}
