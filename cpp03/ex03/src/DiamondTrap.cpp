/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:52:36 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/17 17:41:05 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
	std::cout << "\e[1;35mDiamondTrap"<< this->_name << " has been created!\e[0m" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "\e[1;36mDiamondTrap" << this->_name << " has been destroyed!\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) 
	: ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name){
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src){
	if (this != &src){
		ClapTrap::operator=(src);
		FragTrap::operator=(src);
		ScavTrap::operator=(src);
		this->_name = src._name;
		std::cout << "Diamond Trap Operator overload called!" << std::endl;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(){
	std::cout <<"Diamond name: " << this->_name << " | ClapTrap name: "
		<< ScavTrap::getName() << std::endl;; 
}
