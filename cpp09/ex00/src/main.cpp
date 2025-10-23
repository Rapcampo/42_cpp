/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:53:54 by rapcampo          #+#    #+#             */
/*   Updated: 2025/10/23 19:40:06 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << YLW ERR_ARGS RST << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.convert(argv[1]);
}
