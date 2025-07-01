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
	MSG("Bureacrat default constructor called");
}

Bureaucrat::~Bureaucrat(){
	MSG("Bureaucrat default destructor called");
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
	MSG("Bureaucrat parameter constructor called");
}
