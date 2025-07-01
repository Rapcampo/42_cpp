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

#define MAX_GRADE 1
#define MIN_GRADE 150

# ifdef DEBUG
#	define MSG(str) std::cout << str << std::endl;
# else
#	define MSG(str)
# endif

class Bureaucrat{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		Bureaucrat(const std::string name, int grade);
		const std::string &getName() const;
		unsigned int getGrade() const;
		void incGrade();
		void decGrade();
		class GradeTooHighExeception : public std::exception{
			public:
				virtual const char *what()const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what()const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);
