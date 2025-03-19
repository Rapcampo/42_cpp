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
	int	hordeSize = 200;
	Zombie* hording = zombieHorde(hordeSize, "zombini");
	for (int i = 0; i < hordeSize; i++){
		std::cout << i + 1 << ". ";
		hording[i].annouce();
	}
	delete [] hording;
}
