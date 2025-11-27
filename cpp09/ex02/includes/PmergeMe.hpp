/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:50:00 by rapcampo          #+#    #+#             */
/*   Updated: 2025/11/27 19:16:47 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <deque>
#include <deque>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <utility>
#include <sstream>
#include <cmath>

#define A 0
#define B 1
#define ODD -1
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
//clock_t needs to be divided by CLOCKS_PER_SEC
int	min(int a, int b);
int	max(int a, int b);

//debugging
template <typename C>
void check(const C& c, const char* name) {
	std::cout << name
		<< " size()=" << c.size()
		<< " distance=" << std::distance(c.begin(), c.end())
		<< "\n";
}

class PmergeMe{
	private:
		clock_t start;
		clock_t end;
		double elapsedTime;
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
		void	createPairs(const std::vector<int> &val, std::vector<std::vector<int> > &pairs);

		void	createPairs(const std::deque<int> &val, std::deque<std::deque<int> > &pairs);

		template <typename C>
			void	mergeSort(C &pairs){
				C left(pairs.begin(), pairs.begin() + pairs.size() / 2);
				C right(pairs.begin() + pairs.size() / 2, pairs.end());
				if (pairs.size() == 1)
					return ;
				mergeSort(left);
				mergeSort(right);
				merge(left, right, pairs);
			}

		template <typename T>
			void	merge(T &left, T &right, T &result){
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

		template <typename J>
			void	JacobsthalSequence(J &jacob){
				for (size_t i = 0; i < jacob.size(); i++)
					jacob[i] = (pow(2, i + 2) - pow(-1, i + 2)) / 3;
			}

		template <typename T>
			void	binarySearch(T &s, int number){
				int start, middle, end;

				start = 0;
				end = s.size() - 1;
				while (start <= end){
					middle = start + ((end - start) >> 1);
					if (number > s[middle])
						start = middle + 1;
					else if (number < s[middle])
						end = middle - 1;
				}
				s.insert(s.begin() + start, number);
			}

		template <typename C, typename P>
			void	insertionSort(C &s, size_t n, const P &pairs){
				std::deque<size_t> jacob(pairs.size());
				JacobsthalSequence(jacob);
				binarySearch(s, pairs[0][B]);
				if (pairs.size() > 1)
					binarySearch(s, pairs[1][B]);
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

};

#endif 
