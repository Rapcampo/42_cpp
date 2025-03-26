/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:12:23 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/26 17:13:39 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include "../includes/main.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void){
	std::cout << GRN D_MSG RST << std::endl;
}

void	Harl::info(void){
	std::cout << PRP I_MSG RST << std::endl;
}

void	Harl::warning(void){
	std::cout << YLW W_MSG RST << std::endl;
}

void	Harl::error(void){
	std::cout << RED E_MSG RST << std::endl;
}

int		Harl::levelDecoder(std::string level){
	int l = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (l < 4 && levels[l] != level){
		l++;
	}
	if (l > 3){
		return (-1);
	}
	return (l);
}

void	Harl::complain(std::string level){
	int lCode = levelDecoder(level);
	void	(Harl::*funcList[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	if (lCode != -1){
		(this->*funcList[lCode])();
	}
	else
		return;
}
