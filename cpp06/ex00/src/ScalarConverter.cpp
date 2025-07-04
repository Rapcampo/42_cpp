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

void	ScalarConverter::convert(const std::string &lt){
	toChar(lt, static_cast<char>(std::atoi(lt.c_str())));
	toInt(lt, static_cast<int>(std::atoi(lt.c_str())));
	toFloat(lt, static_cast<float>(std::strtof(lt.c_str(), 0)));
	toChar(lt, static_cast<double>(std::strtod(lt.c_str(), 0)));
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
