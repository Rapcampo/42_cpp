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
#include "../includes/Form.hpp"

/*static void	testSuiteBur(){

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
		std::cout << goodboy << std::endl;
		goodboy.incGrade();
		goodboy.incGrade();
		std::cout << goodboy << std::endl;
		while (goodboy.getGrade() < MIN_GRADE)
			goodboy.decGrade();
		std::cout << goodboy << std::endl;
		while (goodboy.getGrade() > MAX_GRADE)
			goodboy.incGrade();
		std::cout << goodboy << std::endl;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}*/

static void testSuiteForm(){

	std::cout << YLW "\nTest 1: Form grade too high\n" RST << std::endl;
	try{
		Form high("invalidHigh", 0, 10);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << YLW"\nTest 2: Form grade too high\n" RST << std::endl;
	try{
		Form low("invalidLow", 151, 10);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << GRN"\nTest 3: Valid Form\n" RST << std::endl;
	try{
		Form valid("valid", 20, 50);
		std::cout << valid << std::endl;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << BLU"\nTest 4: Form sign Bur grade lower than required\n" RST << std::endl;
	try{
		Bureaucrat lowb("nobody", 120);
		Form _2b1a("2b1a", 20, 50);
		std::cout << lowb << std::endl;
		std::cout << _2b1a << std::endl;
		_2b1a.beSigned(lowb);
		std::cout << _2b1a << std::endl;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"\nTest 5: Form sign Bur grade equal than required\n" RST << std::endl;
	try{
		Bureaucrat hib("somebody", 20);
		Form _2b1b("2b1b", 20, 50);
		std::cout << hib<< std::endl;
		std::cout << _2b1b << std::endl;
		_2b1b.beSigned(hib);
		std::cout << _2b1b << std::endl;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << PRP"\nTest 6: Form sign Bur grade higher than required\n" RST << std::endl;
	try{
		Bureaucrat h2b("vicepres", 2);
		Form _2b1c("2b1c", 10, 2);
		std::cout << h2b<< std::endl;
		std::cout << _2b1c << std::endl;
		_2b1c.beSigned(h2b);
		std::cout << _2b1c << std::endl;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << BLU"\nTest 7: Form signed more than once\n" RST << std::endl;
	try{
		Bureaucrat h2c("vicepres", 2);
		Form _2b1d("2b1a", 10, 2);
		std::cout << h2c<< std::endl;
		std::cout << _2b1d << std::endl;
		_2b1d.beSigned(h2c);
		std::cout << _2b1d << std::endl;
		_2b1d.beSigned(h2c);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

int main(){
//	testSuiteBur();
	testSuiteForm();
}
