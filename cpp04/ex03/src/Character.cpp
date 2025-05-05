/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:20:51 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/05 22:32:48 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/main.hpp"

Character::Character() : _name("voiderino"), _invSlots(0){
	MSG("Character default constructor called");
	for(int i = 0; i < SLOTS; i++){
		this->_equip[i] = NULL;
		this->_unequip[i] = NULL;
	}
}

Character::Character(const std::string name) : _name(name), _invSlots(0){
	MSG("Character parameter constructor called");
	for(int i = 0; i < SLOTS; i++){
		this->_equip[i] = NULL;
		this->_unequip[i] = NULL;
	}
}

Character::Character(const Character &src){
	MSG("Character copy constructor called");
	*this = src;
}


