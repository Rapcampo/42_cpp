/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:49:38 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/17 15:50:44 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"


FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30){
	std::cout << "\e[1;35mFragTrap"<< this->getName() << " has been created!\e[0m" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "\e[1;36mFragTrap" << this->getName() << " has been destroyed!\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src){
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src){
	ClapTrap::operator=(src);
	std::cout << "FragTrap Operator overload called!" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target){
	if (this->getEnergy() > 0 && this->getHealth() > 0){
		std::cout << "FragTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getAttack() << " points of damage!" << std::endl;
		this->setEnergy(-1);
	}
	else if (this->getEnergy() == 0){
		std::cout << "FragTrap " << this->getName() << " has no energy left!" << std::endl;
	}
	else 
		std::cout << "FragTrap " << this->getName() << " has no Health left!" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap is requesting high fives." << std::endl;
}
