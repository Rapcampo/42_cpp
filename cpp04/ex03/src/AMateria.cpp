/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:08:29 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/02 23:20:27 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/main.hpp"

AMateria::AMateria(std::string const &type) : _type(type){
	MSG(GRN "AMateria constructor called" RST);
}

AMateria::AMateria(const AMateria &src){
	MSG(GRN "AMateria copy const called" RST);
	this->_type = src._type;
}

AMateria &AMateria::operator=(const AMateria &src){
	if (this !=  &src){
		this->_type = src._type;
	}
	return (*this);
}

AMateria::~AMateria(){
	MSG(YLW "AMateria destructor called" RST);
}

const std::string &AMateria::getType() const{
	return (this->_type);
}

void AMateria::use(ICharacter &target){
	(void)target;
}
