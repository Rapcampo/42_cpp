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
#include <deque>
#include <deque>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <iterator>

//NOTE: merge insertion sort works using divide and conquer, binary search trees
//also uses sorted pairs, check if need std::utility pair(t n, t n);
//using deque and vector are useful containers to allow showing sequential and random
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
		std::chrono::duration<double> elapsedTime;
		const std::string type;
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &src);

		double mergeInsertionSort(std::vector<int> &val);
		double mergeInsertionSort(std::deque<int> &val);
		bool parse(char **argv, std::vector<int> &vec, std::deque<int> &lst);

	private:
		void	createPairs(const std::vector<int> &val, std::vector<std::vector<int>> &pairs);
		void	mergeSort(std::vector<std::vector<int>> &pairs);
		void	merge(std::vector<std::vector<int>> &left, std::vector<std::vector<int>> &right, std::vector<std::vector<int>> &result);
		void	JacobsthalSequence(std::vector<size_t> &vec);
		void	insertionSort(std::vector<int> &s, size_t n, const std::vector<std::vector<int>> &pairs);
		void	binarySearch(std::vector<int> &sorted, int num);
		
		//deque overload

		void	createPairs(const std::deque<int> &val, std::deque<std::deque<int>> &pairs);
		void	mergeSort(std::deque<std::deque<int>> &pairs);
		void	merge(std::deque<std::deque<int>> &left, std::deque<std::deque<int>> &right, std::deque<std::deque<int>> &result);
		void	JacobsthalSequence(std::deque<size_t> &vec);
		void	insertionSort(std::deque<int> &s, size_t n, const std::deque<std::deque<int>> &pairs);
		void	binarySearch(std::deque<int> &sorted, int num);
};

#endif 
