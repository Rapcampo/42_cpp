/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:05:54 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/23 16:07:47 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat Default Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src){
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src){
	WrongAnimal::operator=(src);
	std::cout << "WrongAnimal Assignment Operator Called" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "Indeed this cat me... oh wait, is it barking???" << std::endl;
}

std::string WrongCat::getType() const {
	return (WrongAnimal::getType());	
}
