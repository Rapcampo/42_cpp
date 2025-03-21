/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:36:07 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/20 23:36:26 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::~HumanB(){
	return ;
}

HumanB::HumanB(std::string name): _name(name){
	this->_wpn = NULL;
	return ;
}

void	HumanB::attack(){
	if (this->_wpn == NULL){
		std::cout << this->_name << " attacked with their bare hands!" << std::endl;
		return ;
	}
	else
		std::cout << this->_name << " attacked with " << _wpn->getType() << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon &wpn){
	this->_wpn = &wpn;
}
