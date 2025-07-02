/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:12 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/02 00:10:23 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : _name("template"), _signed(false), _signGrade(150), _execGrade(150){
	MSG(GRN "Form Default constructor called" RST);
}

Form::~Form(){
	MSG(YLW "Form Destructor called" RST);
}

Form::Form(const Form &src)	: _name(src._name), _signed(src._signed),
	_signGrade(src._signGrade), _execGrade(src._execGrade){
	MSG("Form Copy Constructor called")
}

Form::Form(const std::string &name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){
		if (signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
		if (signGrade > 150 || execGrade > 150)
			throw GradeTooLowException();
	MSG(GRN "parameter constructor called" RST);
}

Form &Form::operator=(const Form &src){
	MSG("Form assigment operator called");
	if (this != &src){
		_signed = src._signed;
	}
	return (*this);
}

int Form::getSignGrade() const {return _signGrade;}

int Form::getExecGrade() const {return _execGrade;}

const std::string &Form::getFormName() const {return _name;}

bool Form::isSigned() const {return _signed;}

void	Form::beSigned(const Bureaucrat &bur){
	MSG("beSigned funciton called");
	if (bur.getGrade() > _signGrade)
		throw GradeTooLowException();
	else if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

const char *Form::GradeTooLowException::what() const throw(){
	return ("Form grade is too low");
}

const char *Form::GradeTooHighException::what() const throw(){
	return ("Form grade is too high");
}

const char *Form::FormAlreadySignedException::what() const throw(){
	return ("Form has already been signed");
}

std::ostream &operator<<(std::ostream &out, const Form &frm){
	out << BLU "Form: " CLR<< frm.getFormName() << "\n"
		<< YLW "Status: " CLR << (frm.isSigned() ? GRN"Signed" CLR : RED "Unsigned" CLR) << "\n"
		<< PRP "Required grade to sign: " CLR<< frm.getSignGrade() << "\n"
		<< CYN "Required grade to execute: " RST<< frm.getExecGrade();
	return (out);
}
