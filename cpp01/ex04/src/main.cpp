/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:46:53 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/21 12:52:55 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"
#include <fstream>

void	stringReplace(const std::string &filename, std::string &strR, std::string &strN){
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open()){
		std::cout << RED ERR_CANT_OP RST << std::endl;
		return;
	}
	std::string buffer;
	std::string line;
	while (std::getline(inFile, line)){
		buffer += line + '\n';
	}
	inFile.close();
}

int	main(int argc, char **argv){
	if (argc != 4){
		if (argc < 4){
			std::cout << GRN USAGE RST << std::endl;
			return (1);
		}
		else{
			std::cout << RED ERR_MANY RST << std::endl;
			return (1);
		}
	}
	stringReplace(argv[1], argv[2], argv[3]);
	return(0);
}
