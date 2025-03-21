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

HumanB::HumanB(std::string name, Weapon &wpn): _name(name), _wpn(wpn){
	return ;
}

void	HumanB::attack(){
	std::cout << this->_name << " attacked with " << _wpn.getType() << std::endl;
}
