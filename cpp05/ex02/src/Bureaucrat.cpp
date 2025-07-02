/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:08:28 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/01 19:10:46 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("defaulterino"), _grade(150){
	MSG(GRN "Bureacrat default constructor called" RST);
}

Bureaucrat::~Bureaucrat(){
	MSG(YLW "Bureaucrat default destructor called" RST);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
	sanitizeGrade(grade);
	MSG(GRN "Bureaucrat parameter constructor called" RST);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade){
	MSG("Bureaucrat copy constructor called");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src){
	if (this != &src)
		this->_grade = src._grade;
	MSG("Bureaucrat assignment operator called");
	return *this;
}

const std::string &Bureaucrat::getName() const {
	MSG("getName function called");
	return _name;
}

int Bureaucrat::getGrade() const {
	MSG("getName function called");
	return _grade;
}

void	Bureaucrat::incGrade(){
	MSG("incGrade function called");
	sanitizeGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decGrade(){
	MSG("decGrade function called");
	sanitizeGrade(_grade + 1);
	_grade++;
}

void	Bureaucrat::sanitizeGrade(int grade){
	MSG(YLW BLN"Grade sanitizer called" RST);
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what() const throw(){
	return (RED BLN "That grade is too damn high!" RST);
}

const char	*Bureaucrat::GradeTooLowException::what() const throw(){
	return (PRP BLN "That grade is too damn low!" RST);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj){
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return out;
}

void	Bureaucrat::signForm(AForm &form){
	try{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getFormName() << std::endl;
	}catch(const AForm::GradeTooLowException &e){
		std::cout << _name << " couldn't sign " << form.getFormName()
			<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const{
	try{
		form.execute(*this);
		std::cout << _name << " executed " << form.getFormName() << std::endl;
	}catch (const AForm::GradeTooLowException &e){
		std::cout << _name << " could not sign " << form.getFormName()
			<< " because " << e.what() << std::endl;
	}
}
