/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:37:51 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/26 16:38:50 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << RED << "usage: Harl [DEBUG/INFO/WARNING/ERROR]" << RST
			<< std::endl;
		return 1;
	}
	Harl hBot;
	std::string cmd = argv[1];
	hBot.complain(cmd);
}
