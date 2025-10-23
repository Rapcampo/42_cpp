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
#include <cstdlib>
#include <ctime>
#include <cstring>

//colour prints

# define RST "\e[0m"
# define ULI "\e[4m"
# define BLN "\e[5m"
# define BLK "\e[1;30m"
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YLW "\e[1;33m"
# define BLU "\e[1;34m"
# define PRP "\e[1;35m"
# define CYN "\e[1;36m"
# define WHT "\e[1;37m"
# define CLR "\e[0;39m"

# define ERR_INPUT "Error: bad input =>"
# define ERR_DATE "Error: bad date =>"
# define ERR_NAN "Error: not a number."
# define ERR_NEG "Error: not a positive number."
# define ERR_TOO_BIG "Error: too large a number."
# define ERR_FILE "Error: could not open file."
# define ERR_ARGS "Error: missing file\nUsage: ./btc [filename]"

class BitcoinExchange{
	private:
		std::map<std::string, double> dataset;
		void getExchangeRate(void);//done
		bool extractExchangeRate(const std::string &line, std::string &date, double &ammount);
		bool validDate(const std::string &date);
		double findNearestDate(const std::string &date);
		void printerr(const std::string &err, const std::string &line);

	public:
		BitcoinExchange();//done
		~BitcoinExchange();//done
		BitcoinExchange(const BitcoinExchange &src);//done
		BitcoinExchange &operator=(const BitcoinExchange &src);//done

		void convert(const char *filename);//done
};
