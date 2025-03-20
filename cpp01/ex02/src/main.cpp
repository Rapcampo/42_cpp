/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:27:47 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/20 21:37:36 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void){
	std::string str = "HI THIS IS BRAIN";
	std::string* strPTR = &str;
	std::string& strREF = str;

	std::cout << "Address of \e[1;34mstring\e[0m: "<< &str  << "\n";
	std::cout << "Address of \e[1;35mstringPTR\e[0m: "<< &strPTR << "\n";
	std::cout << "Address of \e[1;36mstringREF\e[0m: "<< &strREF << "\n";

	std::cout << "value of \e[1;34mstring\e[0m: "<< str << "\n";
	std::cout << "value of \e[1;35mstringPTR\e[0m: "<< strPTR << "\n";
	std::cout << "value of \e[1;36mstringREF\e[0m: "<< strREF << std::endl;
}
