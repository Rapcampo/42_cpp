/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:01:53 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/17 21:13:47 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++){
		horde[i].nameZombie(name);
	}
	return (horde);
}
