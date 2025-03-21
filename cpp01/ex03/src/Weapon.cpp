/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:05:42 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/20 23:10:34 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon() : _type(""){
	return ;
}

Weapon::~Weapon(){
	return ;
}

Weapon::Weapon(std::string type) : _type(type){
	return ;
}

std::string Weapon::getType(void) const{
	return _type;
}

void	Weapon::setType(std::string type){
	this->_type = type;
}
