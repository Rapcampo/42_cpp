/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:30:00 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/03 13:08:30 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <exception>
#include <stdexcept>
#include <cstdlib>

//calculate should check for fist operator in the stack, pop the 2 first numbers
//making calculations and push the result to the stack again
//returns the final calculated value

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &src){*this = src;}

RPN &RPN::operator=(const RPN &src){
	*this = src;
	return *this;
}

long RPN::doOperation(std::stack<long> &stack, char op){
	long a;
	long b;

	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
	if (op == '*')
		return b * a;
	else if (op == '-')
		return b - a;
	else if(op == '/'){
		if (a == 0)
			throw std::runtime_error("Error: Division by 0!");
		return b / a;
	}
	else
		return b + a;
}

long RPN::calculate(const std::string &input){
	long	result = 0;
	char	ope = 0;
	std::stack<long> stack;
	std::string token;
	std::istringstream expression(input);

	while (expression >> token){
		if ((token.find_first_of(DIGITS) != token.npos 
				&& token.find_last_not_of(DIGITS MINUS) != token.npos) ||
			token.find_first_of(OPERATORS) != token.find_last_of(OPERATORS))
			throw std::runtime_error(ERR_WRONG_SYNTAX);
		if (token.find_first_of(DIGITS) != token.npos)
			stack.push(std::strtol(token.c_str() , NULL, 10));
		else if (token.find_first_of(OPERATORS) != token.npos){
			ope = token[0];
			if (stack.size() < 2)
				throw std::runtime_error(ERR_OP_TWO);
			result = RPN::doOperation(stack, ope);
			stack.push(result);
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error(ERR_REMAIN);
	return stack.top();
}
