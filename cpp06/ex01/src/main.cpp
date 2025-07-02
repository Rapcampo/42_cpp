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

struct Data {
	int			number;
	std::string string;
};

int main(){
	Data *data = new Data;
	data->number = 42;
	data->string = "Rapcampo";

	std::cout << "Struct data:\n" << "Number: " << data->number 
		<< "\nstr: " << data->string << "\n" << std::endl;
	uintptr_t intaddr = Serializer::serialize(data);
	std::cout << "Data Address: " << data << "\n" << std::endl;
	std::cout << "int Address: " << intaddr << "\n" << std::endl;
	Data *ddata = Serializer::deserialize(intaddr);
	std::cout << "Struct deserialized data:\n" << "Number: " << ddata->number 
		<< "\nstr: " << ddata->string << "\n" << std::endl;
	std::cout << "Deserialized Data Address: " << ddata << "\n" << std::endl;

	delete data;
}
