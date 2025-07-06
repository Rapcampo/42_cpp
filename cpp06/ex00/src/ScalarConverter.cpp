/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:58:18 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/03 12:02:41 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src){*this = src;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){
	(void)src;
	return (*this);
}

typedef bool (*funcs[5])(const std::string &lt);

static bool isPseudo(const std::string &lt);
static bool isChar(const std::string &lt);
static bool isInt(const std::string &lt);
static bool isFloat(const std::string &lt);
static bool isDouble(const std::string &lt);
static void checkString(const std::string &lt);

static void checkString(const std::string &lt){
	int i = -i;
	while (std::isspace(lt[++i]));
	if (lt.find_first_not_of(VALID, i) != lt.npos)
		throw std::exception();
	if (lt.find_first_of('.') != lt.find_last_of('.') ||
			lt.find_first_of('f') != lt.find_last_of('f') ||
			lt.find_last_of('-') != lt.find_last_of('-') ||
			lt.find_last_of('+') != lt.find_last_of('+'))
		throw std::exception();
}

static bool isPseudo(const std::string &lt){
	return (lt == "-inf" || lt == "+inf" || lt == "+inff" ||
			lt == "-inff" || lt == "nan" || lt == "nanf");
}

void	ScalarConverter::convert(const std::string &lt){
	bool foundType = false;
	int typePos = -1;
	funcs f = {isChar, isInt, isFloat, isDouble, NULL};
	if (isPseudo(lt)){
		toPseudo(lt);
		return;
	}
	try{
		checkString(lt);
	}catch(...){
		std::cout << "this is not a valid type :(" << std::endl;
		return;
	}
	while (foundType != true && ++typePos < 4)
		foundType = f[typePos](lt);
	switch (typePos){
		case 0:
			toChar(lt, static_cast<char>(std::atoi(lt.c_str())));
			break;
		case 1:
			toInt(lt, static_cast<int>(std::atoi(lt.c_str())));
			break;
		case 2:
			toFloat(lt, static_cast<float>(std::strtof(lt.c_str(), 0)));
			break;
		case 3:
			toDouble(lt, static_cast<double>(std::strtod(lt.c_str(), 0)));
			break;
		case 4:
			std::cout << "Cannot Assert type to convert" << std::endl;
			break;
	}
}

void	ScalarConverter::toPseudo(const std::string &lt){
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (lt.find("nan") != lt.npos){
		std::cout << "float: nanf\n";
		std::cout << "double: nan" << std::endl;
	}else{
		std::cout << "float: " << lt.find_first_of("+-") << "inff\n";
		std::cout << "float: " << lt.find_first_of("+-") << "inf" << std::endl;
	}
}

void	ScalarConverter::toChar(const std::string &lt, char c){
	if (!(lt.size() <= 1 && std::isprint(lt[0]) && !std::isdigit(lt[0])))
		std::cout << "char: impossible" << std::endl;
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

void	ScalarConverter::toInt(const std::string &lt, int i){

}
