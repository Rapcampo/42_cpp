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

Character::Character(std::string name) : _name(name), _invSlots(0){
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

Character::~Character(){
	MSG("Character destructor called");
	for(int i = 0; i < SLOTS; i++){
		if (this->_equip[i])
			delete this->_equip[i];
		if (this->_unequip[i])
			delete this->_unequip[i];
	}
}

Character &Character::operator=(const Character &src){
	if (this != &src){
		this->_name = src._name;	
		this->_invSlots = src._invSlots;
		for (int i = 0; i < SLOTS; i++){
			if (this->_equip[i])
				delete this->_equip[i];
			if (this->_unequip[i])
				delete this->_unequip[i];
			this->_equip[i] = src._equip[i];
			this->_unequip[i] = src._unequip[i];
		}
	}
	return (*this);
}

void Character::equip(AMateria *m){
	if (_invSlots >= SLOTS){
		delete m;
		return ;
	}
	MSG(this->getName() + " equipped the materia: " + m->getType());
	this->_equip[_invSlots++] = m;
}

void Character::unequip(int idx){
	if (idx < 0 || idx > 3)
		return ;
	if (!this->_equip[idx] || this->_unequip[idx])
		return ;
	MSG("\e[1;35m" + this->getName() + " dropped " + this->_equip[idx]->getType() + " on the floor!\e[0m");
	this->_unequip[idx] = this->_equip[idx];
	this->_equip[idx] = 0;
}

void Character::use(int idx, ICharacter &target){
	if (idx < 0 || idx > 3 || !this->_equip[idx]){
		std::cout << "Materia does not exist" << std::endl;
		return ;
	}
	this->_equip[idx]->use(target);
}

std::string const &Character::getName() const{
	return (this->_name);
}
