/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:25:08 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/20 23:35:39 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::~HumanA(){
	return ;
}

HumanA::HumanA(std::string name, Weapon &wpn): _name(name), _wpn(wpn){
	return ;
}

void	HumanA::attack(){
	std::cout << this->_name << " attacked with " << _wpn.getType() << std::endl;
}
