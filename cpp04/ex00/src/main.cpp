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
	std::cout << "\n\n\n \e[1;32m OTHER TESTS!\e[0m\n\n\n";
	const Animal* meta2 = new Animal(*meta);
	const Animal* dog2 = new Dog(dog);
	const Animal* cat2 = new Cat(cat);
	dog2 = meta;
	std::cout << dog2->getType() << " " << std::endl;
	delete dog;
	delete cat;
	delete meta;
	delete wani;
	delete wcat;
}
