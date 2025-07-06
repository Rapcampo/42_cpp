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

# define VALID "+-0123456789.f"
# define DIGITS "0123456789"

class ScalarConverter{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

		static void toChar(const std::string &lt, char c);
		static void toInt(const std::string &lt, int i);
		static void toFloat(const std::string &lt, float f);
		static void toDouble(const std::string &lt, double d);
		static void toPseudo(const std::string &lt);
		static void typeConverter(const std::string &lt, long double nb);

	public:
		static void convert(const std::string &lt);
};
