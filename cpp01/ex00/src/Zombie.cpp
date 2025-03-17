/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:38:53 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/17 19:55:21 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <iostream>

Zombie::Zombie(){
	std::string _name = "";
	return;
}

Zombie::~Zombie(){
	std::cout << "Zombie: " << Zombie::_name << " was destroyed!" << std::endl;
}

Zombie::Zombie(std::string name){
	this->_name = name;
}

void	Zombie::annouce(void){
	std::cout << Zombie::_name << ": " << CALL << std::endl;
}

void	Zombie::randomChump(std::string name){
}
