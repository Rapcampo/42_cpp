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

#define DIGITS "0123456789"
#define OPERATORS "*+-/"

#define ERR_NEED_ARG "Error: no argument was given, please input your RPN value!"
#define ERR_WHY_EQUAL "Error: This is reverse polish notation, no equals are necessary!"
#define ERR_WRONG_SYNTAX "Error: This is not a valid RPN input!"
//stack is LIFO (last in first out)
//classical stack example, popping stacks as evaluated

class RPN{
	private:
		RPN();
		~RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
	
	public:
		static long calculate(std::stack<long> nb);
};
