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
		throw std::runtime_error(RED ERR_FILE RST);
	while (!infile.eof()){
		std::getline(infile, line);
		if (line.compare("date | value") == 0)
			continue;
		if (line == "" || !extractExchangeRate(line, date, ammount))
			continue;
		dataset.find(date) == dataset.end() 
			? worth = findNearestDate(date) : worth = dataset[date];
		std::cout << date << " => " 
			<< ammount << " = " << ammount * worth << std::endl;
	}
	infile.close();
}

void BitcoinExchange::getExchangeRate(){
	std::ifstream data_in;
	std::string key, value;
	data_in.open("data.csv", std::ios::in);
	if (data_in.fail())
		throw std::runtime_error(RED ERR_FILE RST);
	std::getline(data_in, key);
	while (!data_in.eof()){
		std::getline(data_in, key, ',');
		std::getline(data_in, value);
		dataset[key] = std::strtod(value.c_str(), NULL);
	}
	data_in.close();
}

void BitcoinExchange::printerr(const std::string &err, const std::string &line){
std::cout << RED << err << " " YLW << line << CLR << std::endl;
}

bool validInput(const std::string &line){
	if (line.find_first_not_of(VAL_IN) != line.npos 
		|| line.find_first_of('|') != line.find_last_of('|') 
		|| line.find_first_of('|') == line.npos
		|| line.find_first_of('.') != line.find_last_of('.'))
		return false;
	int dash = 0;
	for (int i  = 0; line[i] != '|'; i++){
		if (line[i] == '-')
			dash++;
	}
	if (dash == 2)
		return true;
	return false;
}
bool BitcoinExchange::extractExchangeRate(const std::string &line, std::string &date, double &ammount){
	std::istringstream stream(line);
	char delimiter;
	if (!validInput(line) || !(stream >> date >> delimiter >> ammount))
		return printerr(ERR_INPUT, line), false;
	if (!validDate(date))
		return printerr(ERR_DATE, line), false;
	return ammount < 0 ? (printerr(ERR_NEG, ""), false) 
		: (ammount > 1000 ? printerr(ERR_TOO_BIG, ""), false : true);
}

bool BitcoinExchange::validDate(const std::string &date){
	char dash;
	std::stringstream stream(date);
	struct tm old, normalized;
	std::memset(&old, 0, sizeof(old));
	std::memset(&normalized, 0, sizeof(normalized));
	if (date.size() != 10)	
		return false;
	if (!(stream >> old.tm_year >> dash >> old.tm_mon >> dash >> old.tm_mday))
		return false;
	old.tm_mon -= 1;
	old.tm_year -= 1900;
	normalized = old;
	std::mktime(&normalized);
	return (normalized.tm_year == old.tm_year
			&& normalized.tm_mon == old.tm_mon
			&& normalized.tm_mday == old.tm_mday);
}

double BitcoinExchange::findNearestDate(const std::string &date){
	std::map<std::string, double>::iterator cur;
	std::map<std::string, double>::iterator prev;
	if (date < dataset.begin()->first)
		return 0;
	if (date > dataset.rbegin()->first)
		return dataset.rbegin()->second;
	prev = dataset.begin();
	cur = dataset.begin();
	cur++;
	while (cur != dataset.end()){
		if (cur->first > date)
			return prev->second;
		prev = cur;
		++cur;
	}
	return 0;
}
