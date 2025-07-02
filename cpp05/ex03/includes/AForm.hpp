/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:10 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/02 00:46:44 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		AForm(const std::string &name, int signGrade, int execGrade);
		int getSignGrade() const;
		int getExecGrade() const;
		const std::string &getFormName() const;
		bool isSigned() const;
		void	beSigned(const Bureaucrat &bur);
		virtual void execute(const Bureaucrat & executor) const = 0;

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class FormAlreadySignedException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &frm);
