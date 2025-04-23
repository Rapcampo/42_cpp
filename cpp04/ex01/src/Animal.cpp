/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:51:33 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/22 19:05:19 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : type("Void"){
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal Default Destructor called" << std::endl;
}

Animal::Animal(const Animal &src){
	this->type = src.type;
	std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &src){
	if (this != &src){
		this->type = src.type;
	}
	std::cout << "Animal Assignment Operator Called" << std::endl;
	return (*this);
}

void Animal::makeSound() const{
	std::cout << "You hear the deafening sound of silence..." << std::endl;
}

std::string Animal::getType() const{
	return (this->type);
}

void Animal::setType(const std::string type){
	this->type = type;
}
