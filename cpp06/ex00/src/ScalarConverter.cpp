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
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src){*this = src;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){
	(void)src;
	return (*this);
}

typedef bool (*funcs[5])(const std::string &lt);

static bool overflow(const std::string &lt, int typePos);
static bool isPseudo(const std::string &lt);
static bool isChar(const std::string &lt);
static bool isInt(const std::string &lt);
static bool isFloat(const std::string &lt);
static bool isDouble(const std::string &lt);
static void checkString(const std::string &lt);

static bool isChar(const std::string &lt){
	if (lt.length() == 1 && !std::isdigit(lt[0]))
		return true;
	if (lt.length() == 3 && lt[0] == '\'' && lt[2] == '\'')
		return true;
	return false;
}

static bool isInt(const std::string &lt){
	int i = -1;
	while (std::isspace(lt[++i]));
	if (lt[i] == '+' || lt[i] == '-')
		i++;
	if (lt.find_first_not_of(DIGITS, i) != lt.npos)
		return false;
	return true;
}

static bool isFloat(const std::string &lt){
	size_t dot = lt.find_first_of('.');
	size_t fpos = lt.find_first_of('f');
	if (fpos == lt.npos || lt.find_first_of(DIGITS) == lt.npos || dot == lt.npos)
		return false;
	if (fpos < dot)
		return false;
	return true;
}

static bool isDouble(const std::string &lt){
	if (lt.find_first_of('f') != lt.npos)
		return false;
	if (lt.find_first_of('.') == lt.npos)
		return false;
	if (lt.find_first_of(DIGITS) != lt.npos)
		return true;
	return false;
}

static void checkString(const std::string &lt){
	int i = -1;
	while (std::isspace(lt[++i]));
	if (isChar(lt))
		return;
	if (lt.find_first_not_of(VALID, i) != lt.npos)
		throw std::exception();
	if (lt.find_first_of('.') != lt.find_last_of('.') ||
			lt.find_first_of('f') != lt.find_last_of('f') ||
			lt.find_first_of('-') != lt.find_last_of('-') ||
			lt.find_first_of('+') != lt.find_last_of('+'))
		throw std::exception();
}

static bool isPseudo(const std::string &lt){
	int i = -1;
	while (std::isspace(lt[++i]));
	return (((lt.compare(i, lt.npos, "-inf")) == 0)
			|| ((lt.compare(i, lt.npos, "+inf")) == 0)
			|| ((lt.compare(i, lt.npos, "-inff")) == 0)
			|| ((lt.compare(i, lt.npos, "+inff")) == 0)
			|| ((lt.compare(i, lt.npos, "nan")) == 0)
			|| ((lt.compare(i, lt.npos, "nanf")) == 0));
}

void	ScalarConverter::convert(const std::string &lt){
	bool foundType = false;
	int typePos = -1;
	funcs f = {isChar, isInt, isFloat, isDouble, NULL};
	if (isPseudo(lt)){
		std::cout << BLU ULI "Received string type: Pseudo Number" << std::endl;
		toPseudo(lt);
		return;
	}
	try{
		checkString(lt);
	}catch(...){
		std::cout << RED << lt << " is is not a valid type :(" RST<< std::endl;
		return;
	}
	while (foundType != true && ++typePos < 4)
		foundType = f[typePos](lt);
	switch (typePos){
		case 0:
			std::cout << BLU ULI "Received string type: Char" << std::endl;
			typeConverter(lt, lt[0]);
			break;
		case 1:
			std::cout << BLU ULI "Received string type: Int" << std::endl;
			typeConverter(lt, std::atoi(lt.c_str()));
			break;
		case 2:
			std::cout << BLU ULI "Received string type: Float" << std::endl;
			typeConverter(lt, std::strtof(lt.c_str(), 0));
			break;
		case 3:
			std::cout << BLU ULI "Received string type: Double" << std::endl;
			typeConverter(lt, std::strtod(lt.c_str(), 0));
			break;
		case 4:
			std::cout << RED <<  "Cannot Assert type " 
				<< lt <<" to convert" RST<< std::endl;
			break;
	}
}

void ScalarConverter::typeConverter(const std::string &lt, long double nb){
	toChar(lt, static_cast<char>(nb));
	toInt(lt, static_cast<int>(nb));
	toFloat(lt, static_cast<float>(nb));
	toDouble(lt, static_cast<double>(nb));
}

void	ScalarConverter::toPseudo(const std::string &lt){
	std::cout << GRN "char: impossible\n" CLR;
	std::cout << PRP "int: impossible\n" CLR;
	if (lt.find("nan") != lt.npos){
		std::cout << YLW "float: nanf\n" CLR;
		std::cout << CYN "double: nan" RST<< std::endl;
	}else{
		std::cout << YLW "float: " << lt[lt.find_first_of("+-")]
			<< "inff\n" CLR;
		std::cout << CYN "double: " << lt[lt.find_first_of("+-")]
			<< "inf" RST << std::endl;
	}
}

void	ScalarConverter::toChar(const std::string &lt, char c){
	if (overflow(lt, 0))
		std::cout << GRN "char: impossible" RST << std::endl;
	else
		std::isprint(c) ? std::cout << GRN "char: '" << c <<"'" RST << std::endl
			: std::cout << GRN "char: Non displayable" RST<< std::endl;
}

void	ScalarConverter::toInt(const std::string &lt, int i){
	if (overflow(lt, 1))
		std::cout << PRP "int: impossible" RST << std::endl;
	else
		std::cout << PRP "int: " << i << RST << std::endl;
}

void	ScalarConverter::toFloat(const std::string &lt, float f){
	if (overflow(lt, 2))
		lt.find_first_of('-') == lt.npos ? 
			std::cout << YLW "Float: +inff" RST << std::endl
			: std::cout << YLW "Float: -inff" RST << std::endl;
	else if (std::isnan(f))
		std::cout << YLW "float: nanf" RST << std::endl;
	else
		f == floor(f) ? std::cout << YLW "float: " 
			<< f << ".0f" RST << std::endl :
			std::cout << YLW "float: " << f << "f" RST << std::endl;
}

void	ScalarConverter::toDouble(const std::string &lt, double d){
	if (overflow(lt, 3))
		lt.find_first_of('-') == lt.npos ? 
			std::cout << CYN "double: +inf" RST << std::endl
			: std::cout << CYN "double: -inf" RST << std::endl;
	else if (std::isnan(d))
		std::cout << CYN "double: nan" RST<< std::endl;
	else
		d == floor(d) ? std::cout << CYN "double: " 
			<< d << ".0" RST << std::endl :
			std::cout << CYN "double: " << d << RST << std::endl;
}

static bool overflow(const std::string &lt, int typePos){
	long double nb = std::strtod(lt.c_str(), 0);
	switch (typePos){
		case 0:
			return (nb < std::numeric_limits<char>::min() ||
					nb > std::numeric_limits<char>::max());
		case 1:
			return (nb < std::numeric_limits<int>::min() ||
					nb > std::numeric_limits<int>::max());
		case 2:
			return (nb < -std::numeric_limits<float>::max() ||
					nb > std::numeric_limits<float>::max());
		case 3:
			return (nb < -std::numeric_limits<double>::max() ||
					nb > std::numeric_limits<double>::max());
		default:
			return false;
	}
}
