/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:56:57 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/17 20:10:00 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int	main(void){
	Zombie* heap_zomb;
	heap_zomb = newZombie("Heap Zombini");
	randomChump("stack Zomboid");
	delete(heap_zomb);
	return (0);
}
