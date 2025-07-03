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

typedef struct s_dataTypes{
	bool isType;
	bool **funcList(std::string &);
} t_dataTypes;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src){*this = src;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){
	return (*this);
}

void	ScalarConverter::convert(const std::string &strLiteral){
	t_dataTypes types;

	types.funcList = (bool(*[])(std::string &)){ScalarConverter::isInt, ScalarConverter::isChar};
	for (int i = 0; types.funcList[i]; i++);
	//parsing things
	//convert function
	//non standard type message
}
