/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:49:41 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/02 20:08:58 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &src){
	(void)src;
}
Intern &Intern::operator=(const Intern &src){
	(void)src;
	return *this;
}

AForm *Intern::makeForm(const std::string &typeForm, const std::string &target) const{
	const char *forms[4] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
		NULL
	};
	AForm *result = NULL;
	int i = -1;
	while (forms[++i]){
		if (typeForm == forms[i]){
			switch (i){
				case 0:
					result = new ShrubberyCreationForm(target);
					break;
				case 1:
					result = new RobotomyRequestForm(target);
					break;
				case 2:
					result = new PresidentialPardonForm(target);
					break;
			}
			std::cout << "Intern creates " << typeForm << " form." << std::endl;
			break;
		}
	}
	if (!result)
		throw FormDoesNotExistException();
	return (result);
}

const char *Intern::FormDoesNotExistException::what() const throw() {
	return ("Form type not found!");
}
