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
#include <chrono>
#include <sstream>
#include <cmath>

#define A 0
#define B 1
#define ODD -1

int	min(int a, int b) {return a < b ? a : b;}
int	max(int a, int b) {return a > b ? a : b;}

PmergeMe::PmergeMe() : type("null"){}

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

void	PmergeMe::merge(std::vector<std::vector<int> > &left, std::vector<std::vector<int> > &right, std::vector<std::vector<int> > &result)
{
	result.clear();
	while (!left.empty() && !right.empty()){
		if (left[0][A] < right[0][A] || right[0][A] == ODD){
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty()){
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty()){
		result.push_back(right.front());
		right.erase(right.begin());
	}
}

void	PmergeMe::mergeSort(std::vector<std::vector<int> > &pairs){
	std::vector<std::vector<int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::vector<std::vector<int> > right(pairs.begin() + pairs.size() / 2, pairs.end());
	if (pairs.size() == 1)
		return ;
	mergeSort(left);
	mergeSort(right);
	merge(left, right, pairs);
}

void	PmergeMe::createPairs(const std::vector<int> &nums, std::vector<std::vector<int> > &pairs){
	size_t npairs = std::ceil(nums.size() / 2.0);

	pairs.resize(npairs);
	pairs.assign(npairs, std::vector<int>(2));
	for (size_t i = 0; i < pairs.size(); i++){
		if ((2 * i + 1) == nums.size()){
			pairs[i][A] = ODD;
			pairs[i][B] = nums[2 * i];
		}
		else{
			pairs[i][A] = min(nums[2 * i], nums[2 * i + 1]);
			pairs[i][B] = max(nums[2 * i], nums[2 * i + 1]);
		}
	}
}

void	PmergeMe::JacobsthalSequence(std::vector<size_t> &vec){
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] = (pow(2, i) - pow(-1, i)) / 3;
}

void	PmergeMe::binarySearch(std::vector<int> &s, int number){
	int start, middle, end;

	start = 0;
	end = s.size() - 1;
	while (start <= end){
		middle = start + (end - start) / 2;
		if (number > s[middle])
			start = middle + 1;
		else if (number < s[middle])
			end = middle - 1;
	}
	s.insert(s.begin() + start, number);
}

void	PmergeMe::insertionSort(std::vector<int> &s, size_t n, const std::vector<std::vector<int> > &pairs){
	std::vector<size_t> jacob(pairs.size());
	JacobsthalSequence(jacob);
	binarySearch(s, pairs[0][B]);
	for (size_t i = 1; i < jacob.size(); i++){
		for (size_t j = jacob[i]; j > jacob[i - 1]; j--){
			if (j >= pairs.size())
				continue;
			binarySearch(s, pairs[j][B]);
			if (s.size() == n)
				return ;
		}
	}
}

double PmergeMe::mergeInsertionSort(std::vector<int> &nums){
	std::vector<std::vector<int>> pairs;
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

//list part


void	PmergeMe::merge(std::deque<std::deque<int> > &left, std::deque<std::deque<int> > &right, std::deque<std::deque<int> > &result)
{
	result.clear();
	while (!left.empty() && !right.empty()){
		if (left[0][A] < right[0][A] || right[0][A] == ODD){
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty()){
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty()){
		result.push_back(right.front());
		right.erase(right.begin());
	}
}

void	PmergeMe::mergeSort(std::deque<std::deque<int> > &pairs){
	std::deque<std::deque<int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::deque<std::deque<int> > right(pairs.begin() + pairs.size() / 2, pairs.end());
	if (pairs.size() == 1)
		return ;
	mergeSort(left);
	mergeSort(right);
	merge(left, right, pairs);
}

void	PmergeMe::createPairs(const std::deque<int> &nums, std::deque<std::deque<int> > &pairs){
	size_t npairs = std::ceil(nums.size() / 2.0);

	pairs.resize(npairs);
	pairs.assign(npairs, std::deque<int>(2));
	for (size_t i = 0; i < pairs.size(); i++){
		if ((2 * i + 1) == nums.size()){
			pairs[i][A] = ODD;
			pairs[i][B] = nums[2 * i];
		}
		else{
			pairs[i][A] = min(nums[2 * i], nums[2 * i + 1]);
			pairs[i][B] = max(nums[2 * i], nums[2 * i + 1]);
		}
	}
}

void	PmergeMe::JacobsthalSequence(std::deque<size_t> &dec){
	for (size_t i = 0; i < dec.size(); i++)
		dec[i] = (std::pow(2, i) - pow(-1, i)) / 3;
}

void	PmergeMe::binarySearch(std::deque<int> &s, int number){
	int start, middle, end;

	start = 0;
	end = s.size() - 1;
	while (start <= end){
		middle = start + (end - start) / 2;
		if (number > s[middle])
			start = middle + 1;
		else if (number < s[middle])
			end = middle - 1;
	}
	s.insert(s.begin() + start, number);
}

void	PmergeMe::insertionSort(std::deque<int> &s, size_t n, const std::deque<std::deque<int> > &pairs){
	std::deque<size_t> jacob(pairs.size());
	JacobsthalSequence(jacob);
	binarySearch(s, pairs[0][B]);
	for (size_t i = 1; i < jacob.size(); i++){
		for (size_t j = jacob[i]; j > jacob[i - 1]; j--){
			if (j >= pairs.size())
				continue;
			binarySearch(s, pairs[j][B]);
			if (s.size() == n)
				return ;
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
