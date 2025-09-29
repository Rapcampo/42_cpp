/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:16:10 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/20 17:06:09 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

class BitcoinExchange{
	private:
		std::map<std::string, double> dataset;
		void getExchangeRate(void);
		bool extractExchangeRate(const std::string &line, std::string &date, double &ammount);
		bool validDate(const std::string &date);
		double findNearestDate(const std::string &date);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void convert(const char *filename);
};
