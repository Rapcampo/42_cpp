/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:05:40 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/02 23:26:23 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

int main(){
	Data *data = new Data;
	data->name = "Rapcampo";
	data->health = 42;
	data->mana = 100;
	data->has_finished_cpp06 = false;
	data->is_taking_emotional_damage = true;

	std::cout << "Struct data:\n" 
		<< "Name: " << data->name << "\n"
		<< "Health: " << data->health << "\n"
		<< "mana: " << data->mana << "\n"
		<< "cpp06 finished status: " << data->has_finished_cpp06<< "\n"
		<< "emotional damage: " << data->is_taking_emotional_damage<< "\n"
		<< "\n" << std::endl;

	uintptr_t intaddr = Serializer::serialize(data);

	std::cout << "Data Address: " << data << "\n" << std::endl;
	std::cout << "int Address: " << intaddr << "\n" << std::endl;

	Data *ddata = Serializer::deserialize(intaddr);
	std::cout << "Struct data:\n" 
		<< "Name: " << ddata->name << "\n"
		<< "Health: " << ddata->health << "\n"
		<< "mana: " << ddata->mana << "\n"
		<< "cpp06 finished status: " << ddata->has_finished_cpp06<< "\n"
		<< "emotional damage: " << ddata->is_taking_emotional_damage<< "\n"
		<< "\n" << std::endl;
	std::cout << "DData Address: " << ddata << "\n" << std::endl;

	delete data;
}
