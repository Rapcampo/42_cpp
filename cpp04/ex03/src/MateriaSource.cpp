/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:35:12 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/05 23:12:08 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/main.hpp"

MateriaSource::MateriaSource() : _held(0){
	MSG("MateriaSource default Constructor called");
	for(int i = 0; i < 4; i++){
		this->_slots[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src){
	MSG("MateriaSource Copy constructor called");
	*this = src;
}

MateriaSource::~MateriaSource(){
	MSG("MateriaSource Destructor called");
	for (int i = 0; i < this->_held; i++)
		delete _slots[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src){
	MSG("MateriaSource Assignment operator called");
	if (this != &src){
		for(int i = 0; i < this->_held; i++){
			delete _slots[i];
		}
		this->_held = src._held;
		for(int j = 0; j < src._held; j++)
			this->_slots[j] = src._slots[j]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia){
	if (_held >= 4)
		return ;
	MSG("MateriaSource learned " + materia->getType());
	this->_slots[this->_held++] = materia;
}

AMateria *MateriaSource::createMateria(const std::string &type){
	for(int i = 0; i < this->_held; i++)
		if (this->_slots[i]->getType() == type)
			return (this->_slots[i]->clone());
	return (0);
}
