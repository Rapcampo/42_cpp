/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:56:25 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/01 17:59:54 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

//colour prints

# define RST "\e[0m"
# define ULI "\e[4m"
# define BLN "\e[5m"
# define BLK "\e[1;30m"
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YLW "\e[1;33m"
# define BLU "\e[1;34m"
# define PRP "\e[1;35m"
# define CYN "\e[1;36m"
# define WHT "\e[1;37m"
# define CLR "\e[0;39m"

class Form;

class Bureaucrat{
	private:
		const std::string	_name;
		int					_grade;
		void	sanitizeGrade(int grade);
	
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		Bureaucrat(const std::string name, int grade);
		const std::string &getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		void signForm(AForm &form);
		void executeForm(const AForm &form) const;

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what()const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what()const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);
