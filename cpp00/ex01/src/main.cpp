/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:33:40 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/06 15:34:05 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

//NOTE: needs to initialize phonebook class;
//NOTE: needs add contact function, search function, exit function
//NOTE: getters and setters functions, private classes and public classes;
//NOTE: User needs to be prompted to make an input

//if ADD needs function that calls different times for cin for contact data; Empty fields not allowed
//if SEARCH needs to display 4 columns: index, first name, last name, nickname;
//for SEARCH each column must be 10 char wide with a | separating items, if name bigger than 10 chars, display 9 chars and put . in the end...
//Display prompt for adicional info (needs number index, must be in range, if out of range we choose behaviour), if correct display info one line per field.

//if input is exit call destructors and exit program;


int	sToi(std::string nbr){

	int n;
	if (!nbr[0])
		return (-1);
	else if (nbr[0] < '0' && nbr[0] > '9')
		return (-1);
	else if (nbr[1])
		return (-1);
	n = nbr[0] - '0';
	return (n);
}

std::string InputGetter(std::string prompt)
{
	std::string input = "";
	while (input.length() == 0)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
	}
	return (input);
}

/*void	DisplayContactInfo(PhoneBook *bookake)
{
}*/

void	DisplaySearchPrompt(PhoneBook *bookake)
{
	std::string index;
	bookake->getInfo();
	index = InputGetter("Choose contact index: ");
//	else 
		std::cout << "Specified contact index does not exist" << std::endl;
//	DisplayContactInfo(bookake, index);
}

void	AddContact(PhoneBook &bookake)
{
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;
	fn = InputGetter("Enter First Name: ");
	ln = InputGetter("Enter Last Name: ");
	nn = InputGetter("Enter Nickname: ");
	pn = InputGetter("Enter Phone Number: ");
	ds = InputGetter("Enter Darkest Secret: ");
	bookake.addContact(fn,ln,nn,pn,ds);
}

int main(void)
{
	PhoneBook bookake;
	Contact contact;
	std::string cmd_in;

	//give user a small help message with usability and so on;
	std::cout << "This is \e[1;39mPhonetron 2000\e[0m, with this advanced piece of software you can ADD and SEARCH for your favourite contacts! Just don't forget to EXIT when you are done!" << std::endl;
	
	while (1)
	{
	//	std::cout << "This is \e[1;39mPhonetron 2000\e[0m, with this advanced piece of software you can ADD and SEARCH for your favourite contacts! Just don't forget to EXIT when you are done!" << std::endl;
		std::cout << "Please enter your command: ";
		if (!(std::getline(std::cin, cmd_in)) || std::cin.eof())
			return (1);
		if (cmd_in == "ADD")
			AddContact(bookake);
		if (cmd_in == "SEARCH")
			DisplaySearchPrompt(&bookake);
		if (cmd_in == "EXIT")
			break;
		else
			std::cout << "\e[1;39mPhoneTron 2000\e[0m does not support this command, please input a valid command!" << std::endl;
	}
	std::cout << "Thank you for using \e[1;39mPhoneTron 2000\e[0m, until next time!" << std::endl;
	return (0);
}
