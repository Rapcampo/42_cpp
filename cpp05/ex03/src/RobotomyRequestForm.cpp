/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:05:10 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/02 17:22:31 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), _target(src._target){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src){
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

const std::string &RobotomyRequestForm::getTarget() const {
	return (_target);
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const {
	std::string print;

	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		print = GRN + this->_target + " has been robotomized successfully!" RST;
	else
		print = RED "The robotomy on " + this->_target + " has failed!" RST;
	std::cout << print << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &frm){
	out << BLU "Form: " CLR<< frm.getFormName() << "\n"
		<< YLW "Status: " CLR << (frm.isSigned() ? GRN"Signed" CLR : RED "Unsigned" CLR) << "\n"
		<< PRP "Required grade to sign: " CLR<< frm.getSignGrade() << "\n"
		<< CYN "Required grade to execute: " RST<< frm.getExecGrade();
	return (out);
}
