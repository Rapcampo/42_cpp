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
#include <unistd.h>

int main()
{
	Span sp = Span(5);
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
	try{
		rd.randomFill();
		std::cout << RED << rd.shortestSpan() << RST << std::endl;
		std::cout << CYN <<  rd.longestSpan() << RST << std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	sleep(3);
	std::cout << rd;

	Span rt = Span(100000);
	try{
		rt.randomFill();
		std::cout << rt.shortestSpan() << std::endl;
		std::cout << rt.longestSpan() << std::endl;

	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	sleep(3);
	std::cout << rt;

	Span empty;
	try{
		empty.addNumber(1);
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	Span lonelynb(1);
	try{
		lonelynb.addNumber(1);
		lonelynb.shortestSpan();
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
