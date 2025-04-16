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

ScavTrap::Scavtrap(const std::string name) : ClapTrap(name) : _name(name), _hp(100), _energy(25), _attack(20){
	std::cout << "ScavTrap " << this->_name << " has been created!" << std::endl;
}

