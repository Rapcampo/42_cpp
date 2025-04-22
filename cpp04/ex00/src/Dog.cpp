/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:11:56 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/22 19:14:43 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Dog.hpp"

Dog::Dog() : Animal(){
	this->setType("Dog");
}

Dog::~Dog(){}

Dog::Dog(const Dog &src){
	this->type = src.type;
}

Dog &Dog::operator=(const Dog &src){
	Animal::operator=(src);
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "The Dog indeed barks..." << std::endl;
}

std::string Dog::getType() const{
	return (Animal::getType());
}
