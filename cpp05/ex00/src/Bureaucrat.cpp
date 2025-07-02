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
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
	sanitizeGrade(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade){
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src){
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incGrade(){
	sanitizeGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decGrade(){
	sanitizeGrade(_grade + 1);
	_grade++;
}

void	Bureaucrat::sanitizeGrade(int grade){
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
