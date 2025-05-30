/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:05:28 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/22 19:11:41 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal(){
	this->setType("Cat");
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat Default Destructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src){
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &src){
	Animal::operator=(src);
	std::cout << "Cat Assignment Operator Called" << std::endl;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "The cat indeed meows..." << std::endl;
}

std::string Cat::getType() const{
	return (Animal::getType());
}
