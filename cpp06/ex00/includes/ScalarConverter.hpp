/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:23:21 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/03 11:57:55 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ScalarConverter{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

		bool isChar(std::string &lt);
		bool isInt(std::string &lt);
		bool isFloat(std::string &lt);
		bool isDouble(std::string &lt);
		bool isPseudo(std::string &lt);

	public:
		static void convert(const std::string &strLiteral);
};
