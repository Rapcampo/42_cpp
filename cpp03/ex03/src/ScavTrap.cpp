/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:19:26 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/16 15:10:51 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20){
	std::cout << "\e[1;32mScavTrap "<< this->getName() << " has been created!\e[0m" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "\e[1;33mScavTrap " << this->getName() << " has been destroyed!\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src){
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src){
	ClapTrap::operator=(src);
	std::cout << "ScavTrap Operator overload called!" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target){
	if (this->getEnergy() > 0 && this->getHealth() > 0){
		std::cout << "ScavTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getAttack() << " points of damage!" << std::endl;
		this->setEnergy(-1);
	}
	else if (this->getEnergy() <= 0){
		std::cout << "ScavTrap " << this->getName() << " has no energy left!" << std::endl;
	}
	else 
		std::cout << "ScavTrap " << this->getName() << " has no Health left!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap is now in Gate Keeper mode." << std::endl;
}
