/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 22:06:51 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/06 22:09:18 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << RED BLN MANY_ARG RST << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
}
