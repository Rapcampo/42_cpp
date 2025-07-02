/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:12 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/02 00:10:23 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _name("template"), _signed(false), _signGrade(150), _execGrade(150){
	MSG(GRN "AForm Default constructor called" RST);
}

AForm::~AForm(){
	MSG(YLW "AForm Destructor called" RST);
}

AForm::AForm(const AForm &src)	: _name(src._name), _signed(src._signed),
	_signGrade(src._signGrade), _execGrade(src._execGrade){
	MSG("AForm Copy Constructor called")
}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){
		if (signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
		if (signGrade > 150 || execGrade > 150)
			throw GradeTooLowException();
	MSG(GRN "parameter constructor called" RST);
}

AForm &AForm::operator=(const AForm &src){
	MSG("AForm assigment operator called");
	if (this != &src){
		_signed = src._signed;
	}
	return (*this);
}

int AForm::getSignGrade() const {return _signGrade;}

int AForm::getExecGrade() const {return _execGrade;}

const std::string &AForm::getFormName() const {return _name;}

bool AForm::isSigned() const {return _signed;}

void	AForm::beSigned(const Bureaucrat &bur){
	MSG("beSigned funciton called");
	if (bur.getGrade() > _signGrade)
		throw GradeTooLowException();
	else if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("grade is too low");
}

const char *AForm::GradeTooHighException::what() const throw(){
	return ("grade is too high");
}

const char *AForm::FormAlreadySignedException::what() const throw(){
	return ("has already been signed");
}

const char *AForm::FormNotSignedException::what() const throw(){
	return ("has not been signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &frm){
	out << BLU "Form: " CLR<< frm.getFormName() << "\n"
		<< YLW "Status: " CLR << (frm.isSigned() ? GRN"Signed" CLR : RED "Unsigned" CLR) << "\n"
		<< PRP "Required grade to sign: " CLR<< frm.getSignGrade() << "\n"
		<< CYN "Required grade to execute: " RST<< frm.getExecGrade();
	return (out);
}
