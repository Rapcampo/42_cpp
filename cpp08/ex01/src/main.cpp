/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:31:28 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/18 22:33:02 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
//#include <unistd.h>

int main()
{
	std::srand(std::time(0));
	Span sp = Span(5);
	std::cout << "\n" BLU << "=== [subject test] ===" << "\n" << RST << std::endl;
	try{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(14);
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	Span rd = Span(1000);
	std::cout << "\n" RED << "=== [1000 numbers test] ===" << "\n" << RST << std::endl;
	try{
		rd.randomFill();
		std::cout <<  rd.shortestSpan() << RST << std::endl;
		std::cout <<  rd.longestSpan() << RST << std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
//	sleep(3);
//	std::cout << rd;

	Span rt = Span(10000);
	std::cout << "\n" PRP<< "=== [10000 numbers test] ===" << "\n" << RST << std::endl;
	try{
		rt.randomFill();
		std::cout << rt.shortestSpan() << std::endl;
		std::cout << rt.longestSpan() << std::endl;

	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
//	sleep(3);
//	std::cout << rt;

	Span empty;
	std::cout << "\n" GRN << "=== [empty test] ===" << "\n" << RST << std::endl;
	try{
		empty.addNumber(1);
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	Span lonelynb(1);
	std::cout << "\n" CYN << "=== [1 nb span test] ===" << "\n" << RST << std::endl;
	try{
		lonelynb.addNumber(1);
		lonelynb.shortestSpan();
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
