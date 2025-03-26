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

Harl::Harl(void){};

Harl::~Harl(void){};

void	Harl::debug(void){
	std::cout << GRN D_MSG RST << std::endl;
}

void	Harl::info(void){
	std::cout << GRN I_MSG RST << std::endl;
}

void	Harl::warning(void){
	std::cout << GRN W_MSG RST << std::endl;
}

void	Harl::error(void){
	std::cout << GRN E_MSG RST << std::endl;
}

int		Harl::levelDecoder(std::string level){
	int l = 0;
	std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", NULL};
	while (l < 4 && levels[l].compare(level) != 0){
		l++;
	}
	if (l > 3){
		return (0);
	}
	return (l);
}

void	Harl::complain(std::string level){
	int lCode = levelDecoder(level);

	if (lCode != 0){
		funcList(lCode);
	}
	else
		return;
}
