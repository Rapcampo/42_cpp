/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:50:00 by rapcampo          #+#    #+#             */
/*   Updated: 2025/11/12 19:11:34 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <list>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <iterator>

//NOTE: merge insertion sort works using divide and conquer, binary search trees
//also uses sorted pairs, check if need std::utility pair(t n, t n);
//using list and vector are useful containers to allow showing sequential and random
//memory
//
//positive integer sequence "no negative allowed"
//"recommended avoiding generic templates"
//"Before: unsorted n seq \n after: sorted n seq \n Time to process a range of n elements with (container) : " 
//^ required format
//error management for duplicates is of own discretion
//error msgs always in stderr

class PmergeMe{
	private:
		std::chrono::high_resolution_clock::time_point start;
		std::chrono::high_resolution_clock::time_point end;
		const std::string type;
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &src);

		double mergeInsertionSort(std::vector<int> &val);
		double mergeInsertionSort(std::list<int> &val);
		bool parse(char **argv, std::vector<int> &vec, std::list<int> &lst);

	private:
		void	createPairs(const std::vector<int> &val, std::vector<std::vector<int>> &pairs);
		void	mergeSort(std::vector<std::vector<int>> &pairs);
		void	merge(std::vector<std::vector<int>> &left, std::vector<std::vector<int>> &right, std::vector<std::vector<int>> &result);
		void	JacobsthalSequence(std::vector<size_t> &vec);
		void	insertionSort(std::vector<int> &s, size_t n, const std::vector<std::vector<int>> &pairs);
		void	binarySearch(std::vector<int> &sorted, int num);
		
		//list overload

		void	createPairs(const std::list<int> &val, std::list<std::list<int>> &pairs);
		void	mergeSort(std::list<std::list<int>> &pairs);
		void	merge(std::list<std::list<int>> &left, std::list<std::list<int>> &right, std::list<std::list<int>> &result);
		void	JacobsthalSequence(std::list<size_t> &vec);
		void	insertionSort(std::list<int> &s, size_t n, const std::list<std::list<int>> &pairs);
		void	binarySearch(std::list<int> &sorted, int num);
};

#endif 
