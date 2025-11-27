#include <sstream>
#include <iostream>
# define RST "\e[0m"
# define ULI "\e[4m"
# define BLN "\e[5m"
# define BLK "\e[1;30m"
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YLW "\e[1;33m"
# define BLU "\e[1;34m"
# define PRP "\e[1;35m"
# define CYN "\e[1;36m"
# define WHT "\e[1;37m"
# define CLR "\e[0;39m"

int main(int argc, char **argv){
	if (argc != 2)
		return std::cout << RED "Error invalid number of args" RST << std::endl, 1;
	std::string arg = argv[1];
	std::stringstream ss; 
	int n = 0;
	int prev = 0;
	if (arg == "Error")
		return	std::cout << arg << std::endl, 0;
	else{
		ss << arg;
		std::cout << arg << std::endl;
		while (!ss.eof()){
			ss >> n;
			if (n < prev)
				return std::cout << RED BLN "FAILED: not correctly in order" RST << std::endl, 1;
			prev = n;
		}
	}
	return std::cout << GRN BLN "PASSED: numbers were in order" RST << std::endl, 0;
}
