/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:14:06 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/17 21:17:47 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void){
	Zombie* hording = zombieHorde(10, "zombini");
	for (int i = 0; i < 10; i++){
		hording[i].annouce();
	}
	delete [] hording;
}
