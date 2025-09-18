/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:41:53 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/18 22:30:18 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <algorithm>
#include <iomanip>
#include <limits>
#include <stdexcept>

Span::Span(): N(0){};

Span::Span(unsigned int N): N(N){};

Span::Span(const Span &src){
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &src){
	if (this != &src){
		this->N = src.N;
		this->data = src.data;
	}
	return *this;
}

unsigned int Span::getCapacity() const{
	return this->N;
}

std::vector<int> Span::getData() const{
	return this->data;
}

void	Span::addNumber(int nb){
	if (this->data.size() == N)
		throw std::runtime_error("Dataset is full!");
	this->data.push_back(nb);
}

int Span::shortestSpan(){
	if (this->data.size() < 2)
		throw std::runtime_error("Too few numbers for Span instruction.");
	std::sort(this->data.begin(), this->data.end());
	std::vector<int>::const_iterator it = this->data.begin();
	int dist = it[1] - it[0];
	int check;
	for (; it != this->data.end(); ++it){
		check = *it - *(it - 1);
		if (check < dist)
			dist = check;
		else if (dist == 0)
			break;
	}
	return dist;
}

int Span::longestSpan(){
	if (this->data.size() < 2)
		throw std::runtime_error("Too few numbers for Span instruction.");
	std::vector<int>::iterator min = std::min_element(this->data.begin(), this->data.end());
	std::vector<int>::iterator max = std::max_element(this->data.begin(), this->data.end());
	return *max - *min;
}

int randomGen(){
	return std::rand() % std::numeric_limits<int>::max();
}

void Span::randomFill(void){
	std::srand(std::time(0));
	this->data.resize(N);
	std::generate(this->data.begin(), this->data.end(), &randomGen);
}

std::ostream &operator<<(std::ostream &out, const Span &span){
	std::vector<int> vec = span.getData();
	unsigned int i = 0;
	for (; i < vec.size(); i++){
		out << "Slot [" << i << "] = " << vec[i] << "\n";
	}
	out << std::endl;
	return out;
}
