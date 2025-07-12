/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:07 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/12 14:53:29 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <cmath>
#include <exception>

template <typename T>

void	iter(T *array, size_t len, void(*f)(T&)){
	for (size_t i = 0; i < len; i++)
		(*f)(array[i]);
}

template <typename T>

void	iter(T *array, size_t len, void(*f)(const T&)){
	for (size_t i = 0; i < len; i++)
		(*f)(array[i]);
}

template <typename T>

void	print(T &p){
	std::cout << p << std::endl;
}

void	square(int &number){
	number *=number;
}

void	removeLastLetter(std::string &str){
	str.erase(str.length() - 1);
}

void	truncate(float &f){
	f = trunc(f);
}

void	testInt(){
	std::cout << "\n\tInt tests\n" << std::endl;

	Array<int> array(6);
	int ex[6] = {1, 2, 5, 125, 4, 34};
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = ex[i];
	size_t len = array.size();

	std::cout << "Values in array:\n";
	iter(array.data(), len, print<const int>);

	iter(array.data(), len, square);
	std::cout << "\nNew Values in array: \n";
	iter(array.data(), len, print<int>);
	std::cout << std::endl;
}

void	testFloat(){
	std::cout << "\n\tFloat tests\n" << std::endl;

	Array<float> array(6);
	float ex[6] = {1.2, 2.3, 5.4, 125.001, 4.1, 34.2};
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = ex[i];
	size_t len = array.size();

	std::cout << "Values in array:\n";
	iter(array.data(), len, print<const float>);

	iter(array.data(), len, truncate);
	std::cout << "\nNew Values in array: \n";
	iter(array.data(), len, print<const float>);
	std::cout << std::endl;
}

void	testString(){
	std::cout << "\n\tString tests\n" << std::endl;

	Array<std::string> array(6); 
	std::string ex[6] = {"this", "that", "here", "there", "42Porto", "example"};
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = ex[i];
	size_t len = array.size();

	std::cout << "Values in array:\n";
	iter(&array[0], len, print<const std::string>);

	iter(&array[0], len, removeLastLetter);
	std::cout << "\nNew Values in array: \n";
	iter(&array[0], len, print<const std::string>);
	std::cout << std::endl;
}

int	main(void){
	Array<double>empty;
	std::cout << &empty << std::endl;
	Array<short>overflow(2);
	unsigned int i = 3;
	try{
		overflow[i];
	}catch(std::exception &e){
		std::cout << e.what() <<std::endl;
	}
	
	testInt();
	testFloat();
	testString();
}
