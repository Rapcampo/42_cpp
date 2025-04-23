/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:00:49 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/23 16:05:28 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongVoid"){
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Default Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
	this->type = src.getType();
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src){
	if (this != &src)
		this->type = src.getType();
	std::cout << "WrongAnimal Assignment Operator Called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "you hear the wrong type of silence..." << std::endl;
}

std::string WrongAnimal::getType() const{
	return (this->type);
}
