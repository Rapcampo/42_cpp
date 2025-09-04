/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:25:26 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/03 11:25:52 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>

#define DIGITS "0123456789"
#define OPERATORS "*+-/"
#define SPACE " "
#define MINUS "-"

#define ERR_NEED_ARG "Error: no argument was given, please input your RPN value!"
#define ERR_WHY_EQUAL "Error: This is reverse polish notation, no equals are necessary!"
#define ERR_WRONG_SYNTAX "Error: This is not a valid RPN input!"
#define ERR_OP_TWO "Error: Operations require at least two digits"
#define ERR_REMAIN "Error: There are remainders in calculation"
//stack is LIFO (last in first out)
//classical stack example, popping stacks as evaluated

class RPN{
	private:
		RPN();
		~RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
	
	public:
		static long doOperation(std::stack<long> &stack, char op);
		static long calculate(const std::string &input);
};
