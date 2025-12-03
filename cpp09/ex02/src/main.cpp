/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:52:31 by rapcampo          #+#    #+#             */
/*   Updated: 2025/11/19 21:52:43 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iomanip>

template <typename T>
void print(T &cont){
	typename T::iterator it;

	for (it = cont.begin(); it != cont.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(int ac, char **av){
	std::vector<int> vec;
	std::deque<int> dec;

	PmergeMe sort;

	if (ac < 2)
		return -1;
	if (!sort.parse(av + 1, vec, dec))
		return std::cout << "Error\n", 1;
#ifndef DEBUG
	std::cout << "Before: ";
	print(vec);
	double vecDeltaT = sort.mergeInsertionSort(vec);
	double decDeltaT = sort.mergeInsertionSort(dec);

	std::cout << "After: ";
	print(vec);

	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector: "
		<< vecDeltaT / CLOCKS_PER_SEC << " sec | "
		<< vecDeltaT * 1e3 / CLOCKS_PER_SEC << " ms | "
		<< vecDeltaT * 1e6 / CLOCKS_PER_SEC  << " µs \n";
	std::cout << "Time to process a range of " << dec.size()
		<< " elements with std::deque: "
		<< decDeltaT / CLOCKS_PER_SEC << " sec | "
		<< decDeltaT * 1e3 / CLOCKS_PER_SEC << " ms | "
		<< decDeltaT * 1e6 / CLOCKS_PER_SEC << " µs \n";
#elif DEBUG
	sort.mergeInsertionSort(vec);
	sort.mergeInsertionSort(dec);
	print(vec);
	//print(dec);
#endif
}
