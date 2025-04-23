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
#include "../includes/Brain.hpp"

Cat::Cat() : Animal(){
	this->setType("Cat");
	this->brain = new Brain();
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat Default Destructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src){
	this->brain = new Brain(*src.brain);
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &src){
	Animal::operator=(src);
	this->brain = new Brain(*src.brain);
	std::cout << "Cat Assignment Operator Called" << std::endl;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "The cat indeed meows..." << std::endl;
}

std::string Cat::getType() const{
	return (Animal::getType());
}

void Cat::getBrain() const{
	std::cout << this->brain << std::endl;
}
