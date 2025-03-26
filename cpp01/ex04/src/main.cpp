/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:46:53 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/25 22:30:23 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

void	stringReplace(const std::string &filename, std::string &strR, std::string &strN){
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open()){
		std::cout << RED ERR_CANT_OP RST << std::endl;
		return;
	}
	std::string buffer;
	std::string line;
	while (std::getline(inFile, line)){
		buffer += line + "\n";
	}
	inFile.close();
	line.clear();
	std::ofstream outFile((std::string(filename) + ".replace").c_str());
	if (!outFile.is_open()){
		std::cerr << RED ERR_OP_OUT RST << std::endl;
		return;
	}
	std::istringstream bufferStream(buffer);
	while (std::getline(bufferStream, line)){
		size_t i = 0;
		while ((i = line.find(strR, i)) != std::string::npos){
			line.erase(i, strR.length());
			line.insert(i, strN);
			i += strN.length();
		}
		outFile << line;
	}
	outFile.close();
	return;
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
	std::string filename = argv[1];
	std::string strR = argv[2];
	std::string strN = argv[3];
	stringReplace(filename, strR, strN);
	return(0);
}
