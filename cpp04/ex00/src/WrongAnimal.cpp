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

WrongAnimal::WrongAnimal() : type(""){}

WrongAnimal::~WrongAnimal(){}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
	this->type = src.getType();
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src){
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "you hear the wrong type of silence..." << std::endl;
}

std::string WrongAnimal::getType() const{
	return (this->type);
}
