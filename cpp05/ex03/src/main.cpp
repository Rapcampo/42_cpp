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
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

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
	Intern poorSoul;
	AForm *form;

	std::cout << BLU"\nTest 1: Shrubbery Form\n" RST << std::endl;
	try{
		Bureaucrat lowb("nobody", 120);
		form = poorSoul.makeForm("shrubbery creation", "home");
		std::cout << *form << std::endl;
		lowb.signForm(*form);
		lowb.executeForm(*form);
		delete form;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"\nTest 2: Robotomy Form\n" RST << std::endl;
	try{
		Bureaucrat midb("Fry", 40);
		form = poorSoul.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		midb.signForm(*form);
		midb.executeForm(*form);
		delete form;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << PRP"\nTest 3: Presidential Form\n" RST << std::endl;
	try{
		Bureaucrat highb("Queen", 1);
		form = poorSoul.makeForm("presidential pardon", "Jack Sparrow");
		std::cout << *form << std::endl;
		highb.signForm(*form);
		highb.executeForm(*form);
		delete form;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << YLW"\nTest 4: Unexistant Form\n" RST << std::endl;
	try{
		Bureaucrat bb("Queen", 1);
		form = poorSoul.makeForm("resignment letter", "Intern");
		std::cout << *form << std::endl;
		bb.signForm(*form);
		bb.executeForm(*form);
		delete form;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

int main(){
//	testSuiteBur();
	testSuiteForm();
}
