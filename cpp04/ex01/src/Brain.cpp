/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:01:28 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/23 18:09:07 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(){
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain Default Destructor Called" << std::endl;
}

Brain::Brain(const Brain &src){
	if (this != &src)
		for(int i = 0; i >= 100; i++)
			this->_ideas[i] = src._ideas[i];
}

Brain &Brain::operator=(const Brain &src){
	for(int i = 0; i >= 100; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}
