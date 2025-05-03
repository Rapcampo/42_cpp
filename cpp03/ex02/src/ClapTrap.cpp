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

ClapTrap::ClapTrap(): _name(""), _hp(10), _energy(10), _attack(0){
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hp(10), _energy(10), _attack(0){
	std::cout << "\e[1;32m" << this->_name << " has been created!\e[0m" << std::endl;
}

ClapTrap::~ClapTrap(){
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

ClapTrap::ClapTrap(const std::string name, unsigned int hp,	
		unsigned int energy, unsigned int attack)
	:_name(name), _hp(hp), _energy(energy), _attack(attack){
		std::cout << "\e[1;34mClapTrap " << this->_name << " has been created!\e[0m" << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap &src)
	: _name(src._name), _hp(src._hp), _energy(src._energy), _attack(src._attack){
	std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (this->_energy > 0 && this->_hp > 0){
		std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy--;
	}
	else if (this->getEnergy() <= 0){
		std::cout << "ClapTrap " << this->getName() << " has no energy left!" << std::endl;
	}
	else 
		std::cout << "ClapTrap " << this->getName() << " has no Health left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hp == 0)
		std::cout << this->_name << " has no hit points left!" << std::endl;
	else if (amount >= this->_hp){
		this->_hp = 0;
		std::cout << this->_name << " has taken " << amount
			<< " points of damage" << " it has now 0 hit points left!" << std::endl;
	}
	else{
		this->_hp -= amount;
		std::cout << this->_name << " has taken " << amount
			<< " points of damage" << " it has now " 
			<< this->_hp << " hit points left!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energy == 0)
		std::cout << this->_name << " has no energy left!" << std::endl;
	else if (this->_hp == 100)
		std::cout << this->_name << " has full health, repair had not effect" << std::endl;
	else if ((this->_hp + amount) >= 100){
		this->_hp = 100;
		std::cout << this->_name <<
			" was repaired by " << amount << " points, it has regained full health!" << std::endl;
		this->_energy--;
		}
	else {
		this->_hp += amount;
		std::cout << this->_name <<
			" was repaired by " << amount << " points, it has now " 
			<< this->_hp << " hit points!" << std::endl;
		this->_energy--;
	}
}

std::string ClapTrap::getName() const {return this->_name;}

unsigned int ClapTrap::getEnergy() const {return this->_energy;}

unsigned int ClapTrap::getHealth() const {return this->_hp;}

unsigned int ClapTrap::getAttack() const {return this->_attack;}

void ClapTrap::setEnergy(int amount){
	if (amount < 0)
		this->_energy--;
	else
		this->_energy++;
}
