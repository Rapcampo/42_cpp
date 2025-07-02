/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:10:27 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/02 15:10:49 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {
		MSG(YLW "ShrubberyCreation default constructor called" RST)
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	MSG(PRP "ShrubberyCreation destructor called" RST);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
		MSG(YLW "ShrubberyCreation parameter constructor called" RST)
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target){
	MSG("ShrubberyCreation copy constructor called");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src){
	MSG("ShrubberyCreation operator assignment called");
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return (_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const{
	try{
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
		throw CannotOpenFileException();
	file << "                                              .    " << "\n";
	file << "                                   .         ;     " << "\n";
	file << "      .              .              ;%     ;;      " << "\n";
	file << "        ,           ,                :;%  %;       " << "\n";
	file << "         :         ;                   :;%;'     .," << "\n";
	file << ",.        %;     %;            ;        %;'    ,;  " << "\n";
	file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'   " << "\n";
	file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'    " << "\n";
	file << "    ;%;      %;        ;%;        % ;%;  ,%;'      " << "\n";
	file << "     `%;.     ;%;     %;'         `;%%;.%;'        " << "\n";
	file << "      `:;%.    ;%%. %@;        %; ;@%;%'           " << "\n";
	file << "         `:%;.  :;bd%;          %;@%;'             " << "\n";
	file << "           `@%:.  :;%.         ;@@%;'              " << "\n";
	file << "             `@%.  `;@%.      ;@@%;                " << "\n";
	file << "               `@%%. `@%%    ;@@%;                 " << "\n";
	file << "                 ;@%. :@%%  %@@%;                  " << "\n";
	file << "                   %@bd%%%bd%%:;                   " << "\n";
	file << "                     #@%%%%%:;;                    " << "\n";
	file << "                     %@@%%%::;                     " << "\n";
	file << "                     %@@@%(o);  . '                " << "\n";
	file << "                     %@@@o%;:(.,'                  " << "\n";
	file << "                 `.. %@@@o%::;                     " << "\n";
	file << "                    `)@@@o%::;                     " << "\n";
	file << "                     %@@(o)::;                     " << "\n";
	file << "                    .%@@@@%::;                     " << "\n";
	file << "                    ;%@@@@%::;.                    " << "\n";
	file << "                   ;%@@@@%%:;;;.                   " << "\n";
	file << "               ...;%@@@@@%%:;;;;,..                " << "\n";
	file.close();
	}catch(std::exception &e){
		std::cout << "Could not excute Shrubbery form."
			<< "Reason: " << e.what() << std::endl;
	}
}

const char *ShrubberyCreationForm::CannotOpenFileException::what() const throw(){
	return ("ofstream could not open the requested file.");
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &frm){
	out << BLU "Form: " CLR<< frm.getFormName() << "\n"
		<< YLW "Status: " CLR << (frm.isSigned() ? GRN"Signed" CLR : RED "Unsigned" CLR) << "\n"
		<< PRP "Required grade to sign: " CLR<< frm.getSignGrade() << "\n"
		<< CYN "Required grade to execute: " RST<< frm.getExecGrade();
	return (out);
}
