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
#include <stdexcept>

//calculate should check for fist operator in the stack, pop the 2 first numbers
//making calculations and push the result to the stack again
//returns the final calculated value

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &src){}

RPN &RPN::operator=(const RPN &src){
	*this = src;
	return *this;
}

long RPN::do_op(std::stack<long> stack, char op){
	long a;
	long b;

	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
	if (op == '*')
		return a * b;
	else if (op == '-')
		return a - b;
	else if(op == '/')
		return a / b;
	else
		return a + b;
}

long RPN::calculate(std::string &input){
	long	result;
	char	ope;
	std::stack<long> stack;
	std::string token;
	std::istringstream expression(input);

	while (expression >> token){
		if (token.find_first_of(DIGITS) != token.npos)
			stack.push(token[0] - '0');
		if (token.find_first_of(OPERATORS) != token.npos){
			ope = token[0];
			if (stack.size() < 2)
				std::runtime_error("ERR_OP_TWO");
			result = RPN::do_op(stack, ope);
			stack.push(result);
		}
	}
	return result;
}
