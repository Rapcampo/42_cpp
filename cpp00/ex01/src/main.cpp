/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:33:40 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/11 16:11:11 by rapcampo         ###   ########.fr       */
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
	if (nbr[1])
		return (-1);
	if (nbr[0] >= '0' && nbr[0] <= '8')
		n = nbr[0] - '0';
	else
		return (-1);
	return (n);
}

std::string InputGetter(std::string prompt)
{
	std::string input = "";
	while (input.length() == 0)
	{
		std::cout << prompt;
		if (!(std::getline(std::cin, input)) || std::cin.eof())
		{
			std::cerr << RED IN_ERR RST << std::endl;
			exit(1);
		}
	}
	return (input);
}

//note this function needs prompt validation and also edge case of no value to be displayed
void	DisplaySearchPrompt(PhoneBook *book)
{
	std::string index;
	int indexer = 0;
	book->getInfo();
	while (1){
	index = InputGetter("Choose contact index, 0 to go back: ");
	if (index == "0") 
		return ;
	if ((indexer = sToi(index) - 1) == -2){
		std::cout << "Specified contact index does not exist" << std::endl;
		return ;
	}
	else
		book->contact[indexer].showContact();
	}
}

void	AddContact(PhoneBook &book)
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
	book.addContact(fn,ln,nn,pn,ds);
}

int main(void)
{
	PhoneBook book;
	std::string cmd_in;

	std::cout << "This is \e[1;35mPhonetron 2000\e[0m, with this advanced piece of software you can ADD and SEARCH for your favourite contacts! Just don't forget to EXIT when you are done!" << std::endl;
	
	while (1)
	{
		std::cout << "\e[1;36mPlease enter your command:\e[0m ";
		if (!(std::getline(std::cin, cmd_in)) || std::cin.eof())
			break ;
		if (cmd_in == "ADD"){
			AddContact(book);
		}
		else if (cmd_in == "SEARCH"){
			DisplaySearchPrompt(&book);
		}
		else if (cmd_in == "EXIT")
			break;
		else
			std::cout << "\e[1;35mPhoneTron 2000\e[0m does not support this command, please input a \e[1;32mvalid command!\e[0m" << std::endl;
	}
	std::cout << "\nThank you for using \e[1;35mPhoneTron 2000\e[0m, until next time!" << std::endl;
	return (0);
}
