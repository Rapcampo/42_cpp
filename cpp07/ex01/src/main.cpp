/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:34:38 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/07 13:34:48 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <iostream>
#include <cmath>

template <class T>

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

	int array[] = {1, 2, 5, 125, 4, 34};
	size_t len = sizeof(array) / sizeof(int);

	std::cout << "Values in array:\n";
	iter(array, len, print);

	iter(array, len, square);
	std::cout << "\nNew Values in array: \n";
	iter(array, len, print);
	std::cout << std::endl;
}

void	testFloat(){
	std::cout << "\n\tFloat tests\n" << std::endl;

	float array[] = {1.2, 2.3, 5.4, 125.001, 4.1, 34.2};
	size_t len = sizeof(array) / sizeof(float);

	std::cout << "Values in array:\n";
	iter(array, len, print);

	iter(array, len, truncate);
	std::cout << "\nNew Values in array: \n";
	iter(array, len, print);
	std::cout << std::endl;
}

void	testString(){
	std::cout << "\n\tString tests\n" << std::endl;

	std::string array[] = {"this", "that", "here", "there", "42Porto", "example"};
	size_t len = sizeof(array) / sizeof(std::string);

	std::cout << "Values in array:\n";
	iter(array, len, print);

	iter(array, len, removeLastLetter);
	std::cout << "\nNew Values in array: \n";
	iter(array, len, print);
	std::cout << std::endl;
}

int	main(void){
	testInt();
	testFloat();
	testString();
}
