/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:53:52 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/03 00:23:32 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Identifier.hpp"

Base *generate(void){
	std::srand(std::time(0));
	int random = std::rand() % 3;
	switch (random){
		case 0: return (new A);
		case 1: return (new B);
		case 2: return (new C);
	}
	return (NULL);
}

void identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
}

void identify(Base &p){
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
	}catch(...){}
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "Class B" << std::endl;
	}catch(...){}
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "Class C" << std::endl;
	}catch(...){}
}

int main(){
	Base *random = generate();
	if (!random){
		std::cout << "Could not generate a random class" << std::endl;
		return (1);
	}
	identify(random);
	identify(*random);
	delete random;
}
