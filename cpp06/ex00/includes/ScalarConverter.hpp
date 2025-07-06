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

# define MANY_ARG "Error: too many arguments"

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
