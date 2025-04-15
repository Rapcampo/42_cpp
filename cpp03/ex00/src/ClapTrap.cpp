/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:37:13 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/15 20:45:59 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _attack(0){
	std::cout << "\e[1;32m" << this->_name << " has been created!\e[0m" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "\e[1;31m" << this->_name << " has been destroyed!\e[0m" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src){
	if (this != &src){
		this->_hp = src._hp;
		this->_name= src._name;
		this->_energy= src._energy;
		this->_attack= src._attack;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target){
	if (this->_energy > 0){
		std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy--;
	}
	else {
		std::cout << "ClapTrap " << this->_name << " has no energy left!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hp == 0)
		std::cout << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
	else if (amount >= this->_hp){
		this->_hp = 0;
		std::cout << "ClapTrap " << this->_name << " has taken " << amount
			<< " points of damage" << " it has now 0 hit points left!" << std::endl;
	}
	else{
		this->_hp -= amount;
		std::cout << "ClapTrap " << this->_name << " has taken " << amount
			<< " points of damage" << "it has now " 
			<< this->_hp << " hit points left!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energy == 0)
		std::cout << "ClapTrap " << this->_name << " has no energy left!" << std::endl;
	else if (this->_hp == 10)
		std::cout << "ClapTrap " << this->_name << " has full health, repair had not effect" << std::endl;
	else if ((this->_hp + amount) >= 10){
		this->_hp = 10;
		std::cout << "ClapTrap " << this->_name <<
			" was repaired by " << amount << " points, it has regained full health!" << std::endl;
		this->_energy--;
		}
	else {
		this->_hp += amount;
		std::cout << "ClapTrap " << this->_name <<
			" was repaired by " << amount << " points, it has now " 
			<< this->_hp << " hit points!" << std::endl;
		this->_energy--;
	}
}
