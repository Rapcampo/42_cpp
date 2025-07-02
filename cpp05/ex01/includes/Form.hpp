/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

class Form{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	
	public:
		Form();
		~Form();
		Form(const Form &src);
		Form &operator=(const Form &src);
		Form(const std::string &name, int signGrade, int execGrade);
		const int getSignGrade() const;
		const int getExecGrade() const;
		const std::string &getFormName() const;
		const bool isSigned() const;
		void	beSigned(const Bureaucrat &bur);

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
};

std::ostream &operator<<(std::ostream &out, const Form &frm);
