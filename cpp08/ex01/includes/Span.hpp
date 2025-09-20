/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:50:49 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/18 14:10:25 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <stdexcept>

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

class Span{
	private:
		unsigned int N;
		std::vector<int>	data;
	
	public:
		Span();
		~Span();
		Span(const Span &src);
		Span &operator=(const Span &src);
		Span(unsigned int N);

		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();

		void	randomFill();

		unsigned int getCapacity() const;
		std::vector<int> getData() const;
};

std::ostream &operator<<(std::ostream &out, const Span &span);
