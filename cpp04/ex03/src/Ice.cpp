/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:59:04 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/02 23:59:52 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/main.hpp"

Ice::Ice() : AMateria("ice"){
	MSG(BLU "Ice constructor called" RST);
}

Ice::~Ice(){
	MSG(YLW "Ice Destructor called" RST);
}

Ice::Ice(const Ice &src) : AMateria(src){
	MSG(BLU "Ice copy constructor called" RST);
}

Ice &Ice::operator=(const Ice &src){
	if (this != &src){
		MSG(BLU "Ice Assignment operator called" RST);
		this->_type = src._type;
	}
	return (*this);
}

AMateria *Ice::clone()const{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " 
		<< target.getName() << " *" << std::endl;
}
