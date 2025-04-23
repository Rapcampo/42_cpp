/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:15:46 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/22 19:19:25 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"

int main(){
	std::cout << "\n\n\n \e[1;31m STANDARD TESTS!\e[0m\n\n\n";
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wani = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();
	wani->makeSound();
	wcat->makeSound();
	delete dog;
	delete cat;
	delete meta;
	delete wani;
	delete wcat;
	std::cout << "\n\n\n \e[1;32m ex00 TESTS!\e[0m\n\n\n";
	Dog Dogcp;
	Cat Catcp;
	Dogcp.getBrain();
	Catcp.getBrain();
	Dog dog2 = Dog(Dogcp);
	Cat cat2 = Cat(Catcp);
	dog2.getBrain();
	cat2.getBrain();
	std::cout << dog2.getType() << " " << std::endl;
	std::cout << cat2.getType() << " " << std::endl;
	std::cout << "\n\n\n \e[1;33m Brain TESTS!\e[0m\n\n\n";
	const Animal** kingdom = new const Animal*[20];
	for(int i = 0; i < 20; i++){
		if (i % 2 == 0)
			kingdom[i] = new Cat();
		else
			kingdom[i] = new Dog();
		kingdom[i]->makeSound();
	}
	for (int j = 0; j < 20; j++)
		delete kingdom[j];
	delete[] kingdom;
}
