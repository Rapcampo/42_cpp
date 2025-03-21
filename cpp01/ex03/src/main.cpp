/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:52:57 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/20 23:01:01 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

int main(void){
	{
	Weapon club = Weapon("crude spiked club");

	HumanA bob("bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}

	{
	Weapon club = Weapon("crude spike club");

	HumanB jim("jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
}
