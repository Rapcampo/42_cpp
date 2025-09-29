/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:39:44 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/29 19:13:36 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <stdexcept>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src){
	if (this != &src){
		this->dataset = src.dataset;
	}
	return *this;
}

void BitcoinExchange::convert(const char *filename){
	std::ifstream infile;
	std::string line, date;
	double ammount, worth;

	try{
		this->getExchangeRate();
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
		return; 
	}
	infile.open(filename, std::ios::in);
	if (infile.fail())
		throw std::runtime_error("Error: could not open pointed file!");
	std::getline(infile, date);
	while (!infile.eof()){
		std::getline(infile, line);
		if (line == "" || !extractExchangeRate(line, date, ammount))
			continue;
		if (dataset.find(date) == dataset.end())
			worth = findNearestDate(date);
		else
			worth = dataset[date];
		std::cout << date << " => " << ammount << " = " << ammount * worth << std::endl;
	}
	infile.close();
}

void BitcoinExchange::getExchangeRate(){
	std::ifstream data_in;
	std::string key, value;
	data_in.open("data.csv", std::ios::in);
	if (data_in.fail())
		throw std::runtime_error("Error: could not open data file!");
	std::getline(data_in, key);
	while (!data_in.eof()){
		std::getline(data_in, key, ',');
		std::getline(data_in, value);
		dataset[key] = std::strtod(value.c_str(), NULL);
	}
	data_in.close();
}


