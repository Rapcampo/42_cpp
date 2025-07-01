/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:15:43 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/01 23:38:17 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <exception>

static void	testSuite(){

	std::cout << YLW "\nTest 1: incrementing too much\n" RST << std::endl;
	try{
		Bureaucrat highrank("BigBoss", 1);
		std::cout << highrank << std::endl;
		highrank.incGrade();
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << BLU "\nTest 2: decrementing too much\n" RST << std::endl;
	try{
		Bureaucrat lowrank("CannonFodder", 150);
		std::cout << lowrank << std::endl;
		lowrank.decGrade();
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << YLW "\nTest 3: constructing grade too high\n" RST << std::endl;
	try{
		Bureaucrat shareholder("shareholder", 0);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << BLU "\nTest 4: constructing grade too low\n" RST << std::endl;
	try{
		Bureaucrat commoner("commoner", 151);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << GRN "\nTest 5: valid use cases\n" RST << std::endl;
	try{
		Bureaucrat goodboy("Hardworker", 75);
		std::cout << goodboy << std::endl;
		goodboy.decGrade();
		std::cout << "after first decrement" << std::endl;
		std::cout << goodboy << std::endl;
		goodboy.incGrade();
		goodboy.incGrade();
		std::cout << "after two increments" << std::endl;
		std::cout << goodboy << std::endl;
		while (goodboy.getGrade() < MIN_GRADE)
			goodboy.decGrade();
		std::cout << "after min grade loop" << std::endl;
		std::cout << goodboy << std::endl;
		while (goodboy.getGrade() > MAX_GRADE)
			goodboy.incGrade();
		std::cout << "after max grade loop" << std::endl;
		std::cout << goodboy << std::endl;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

int main(){
	testSuite();
}
