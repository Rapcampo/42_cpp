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
		Form(const std::string name, int signvalue, int valueexec);
		const int getSignGrade();
		const int getExecGrade();
		const std::string &getFormName();
		void	beSigned(const Bureaucrat &bur);
		void	isSigned();

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what()const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what()const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &obj);
