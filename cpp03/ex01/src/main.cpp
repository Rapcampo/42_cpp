/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:46:17 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/15 21:34:16 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include <iostream>

int main(void){
	ClapTrap ct1("jorginho");
	ClapTrap ct2j(ct1);
	ct1.beRepaired(1);
	ct1.takeDamage(2);
	ct1.beRepaired(1);
	ct1.beRepaired(1);
	for (int i = 10; i > 0; i--)
		ct1.attack("Leonildo");
	ct1.takeDamage(10);

	std::cout << "\n\n\n============== ScavTrap Part ==============\n\n\n";

	ScavTrap st1("Reginaldo");
	st1.attack("Ermenegildo");
	st1.takeDamage(30);
	st1.beRepaired(20);
	st1.beRepaired(20);
	ScavTrap st2;
	st2 = st1;
	st1.guardGate();
/*	for(int i = 200; i > 0; i--){
		st1.attack("blu");
		st1.beRepaired(10);
	}*/
}
