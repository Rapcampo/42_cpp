/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:43:45 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/02 23:58:36 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/main.hpp"

Cure::Cure() : AMateria("cure"){
	MSG(PRP "Cure constructor called" RST);
}

Cure::~Cure(){
	MSG(YLW "Cure Destructor called" RST);
}

Cure::Cure(const Cure &src) : AMateria(src){
	MSG(PRP "Cure copy constructor called" RST);
}

Cure &Cure::operator=(const Cure &src){
	if (this != &src){
		MSG(PRP "Cure Assignment operator called" RST);
		this->_type = src._type;
	}
	return (*this);
}

AMateria *Cure::clone()const{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target){
	std::cout << "* heals "	<< target.getName() << "'s wounds *" << std::endl;
}
