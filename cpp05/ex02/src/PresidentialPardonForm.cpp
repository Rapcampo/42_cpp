/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:08:44 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/02 18:09:08 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {
		MSG(YLW "PresidentPardon default constructor called" RST)
}

PresidentialPardonForm::~PresidentialPardonForm() {
	MSG(PRP "PresidentPardon destructor called" RST);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
		MSG(YLW "PresidentPardon parameter constructor called" RST)
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src), _target(src._target){
	MSG("PresidentPardon copy constructor called");
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src){
	MSG("PresidentPardon operator assignment called");
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

const std::string &PresidentialPardonForm::getTarget() const {
	return (_target);
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const {

	try{
		if (!this->isSigned())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getExecGrade())
			throw AForm::GradeTooLowException();
		std::cout 
			<< GRN + this->_target + " has been pardoned by Zaphod Beeblebrox!" RST 
			<< std::endl;
	}catch (std::exception &e){
		std::cout << RED + this->_target + " could not be pardoned\n" RST 
			+ YLW "Reason: " + e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &frm){
	out << BLU "Form: " CLR<< frm.getFormName() << "\n"
		<< YLW "Status: " CLR << (frm.isSigned() ? GRN"Signed" CLR : RED "Unsigned" CLR) << "\n"
		<< PRP "Required grade to sign: " CLR<< frm.getSignGrade() << "\n"
		<< CYN "Required grade to execute: " RST<< frm.getExecGrade();
	return (out);
}
