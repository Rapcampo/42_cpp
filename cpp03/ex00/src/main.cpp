/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:46:17 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/15 20:50:53 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <iostream>

int main(void){
	ClapTrap ct1("jorginho");
	ct1.beRepaired(1);
	ct1.takeDamage(2);
	ct1.beRepaired(1);
	ct1.beRepaired(1);
	for (int i = 10; i > 0; i--)
		ct1.attack("Leonildo");
	ct1.takeDamage(10);
}
