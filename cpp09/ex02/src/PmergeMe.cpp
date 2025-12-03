/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:56:58 by rapcampo          #+#    #+#             */
/*   Updated: 2025/11/18 20:58:49 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	min(int a, int b) {return a < b ? a : b;}
int	max(int a, int b) {return a > b ? a : b;}

PmergeMe::PmergeMe() : type("none"){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &src) : type(src.type){
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src){
	if (this != &src){
		this->start = src.start;
		this->end = src.end;
		this->elapsedTime = src.elapsedTime;
	}
	return *this;
}

bool PmergeMe::parse(char **argv, std::vector<int> &vec, std::deque<int> &deq){
	int number;
	std::stringstream stream;
	std::string total;

	total = std::string(argv[0]);
	for (int i = 1; argv[i]; i++)
		total += " " + std::string(argv[i]);
	stream << total;
	while (!stream.eof()){
		if (!(stream >> number))
			return false;
		if (number < 0)
			return false;
		if (std::find(vec.begin(), vec.end(), number) != vec.end())
			return false;
		vec.push_back(number);
		deq.push_back(number);
	}
	return true;
}

void	PmergeMe::createPairs(const std::vector<int> &nums, std::vector<std::vector<int> > &pairs){
	size_t npairs = std::ceil(nums.size() / 2.0);

	pairs.assign(npairs, std::vector<int>(2));
	for (size_t i = 0; i < pairs.size(); i++){
		if ((2 * i + 1) == nums.size()){
			pairs[i][A] = ODD;
			pairs[i][B] = nums[2 * i];
		}
		else{
			pairs[i][A] = max(nums[2 * i], nums[2 * i + 1]);
			pairs[i][B] = min(nums[2 * i], nums[2 * i + 1]);
		}
	}
}

double PmergeMe::mergeInsertionSort(std::vector<int> &nums){
	std::vector<std::vector<int> > pairs;
	std::vector<int> s;

	start = std::clock();
	createPairs(nums, pairs);
	mergeSort(pairs);
	for (size_t i = 0; i < pairs.size() && pairs[i][A] != ODD; i++){
		s.push_back(pairs[i][A]);
	}
	insertionSort(s, nums.size(), pairs);
	end = std::clock();
	elapsedTime = double(end - start);
	nums = s;
	return (elapsedTime);
}

//deque part

void	PmergeMe::createPairs(const std::deque<int> &nums, std::deque<std::deque<int> > &pairs){
	size_t npairs = std::ceil(nums.size() / 2.0);

	pairs.assign(npairs, std::deque<int>(2));
	for (size_t i = 0; i < pairs.size(); i++){
		if ((2 * i + 1) == nums.size()){
			pairs[i][A] = ODD;
			pairs[i][B] = nums[2 * i];
		}
		else{
			pairs[i][A] = max(nums[2 * i], nums[2 * i + 1]);
			pairs[i][B] = min(nums[2 * i], nums[2 * i + 1]);
		}
	}
}

double PmergeMe::mergeInsertionSort(std::deque<int> &nums){
	std::deque<std::deque<int> > pairs;
	std::deque<int> s;

	start = std::clock();
	createPairs(nums, pairs);
	mergeSort(pairs);
	for (size_t i = 0; i < pairs.size() && pairs[i][A] != ODD; i++){
		s.push_back(pairs[i][A]);
	}
	insertionSort(s, nums.size(), pairs);
	end = std::clock();
	elapsedTime = double(end - start);
	nums = s;
	return (elapsedTime);
}
