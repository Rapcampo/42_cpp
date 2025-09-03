/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:06:00 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/03 13:06:35 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

//should treat quotes or not?
//
static bool inputValidation(char *input){
	std::string raw;	

	raw = input;
	if (raw.find_first_not_of(OPERATORS DIGITS) != raw.npos ||
			raw.find_first_of(OPERATORS) == raw.npos ||
				raw.find_first_of(DIGITS) == raw.npos)
		return false;
	return true;
}

//allocate new stack with the elemtns in the string
static std::stack<long> stackfy(char *nbstr);

int	main(int argc, char **argv){
	long res;
	if (argc < 2){
		std::cout << ERR_NEED_ARG << std::endl;
		return 1;
	}
	if(!inputValidation(argv[1])){
		std::cout << ERR_WRONG_SYNTAX << std::endl;
		return 2;
	}
	res = RPN::calculate(stackfy(argv[1]));
	std::cout << "the result is: " << res << std::endl;
}
