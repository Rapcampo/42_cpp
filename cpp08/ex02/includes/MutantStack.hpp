/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:44:26 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/19 12:34:57 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <deque>
#include <list>
#include <vector>

//colour prints

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

template <typename T>

class MutantStack : public std::stack<T>{
	public:
		MutantStack(): std::stack<T>(){};
		~MutantStack() {};
		MutantStack(const MutantStack &src): std::stack<T>(src) {}

		MutantStack &operator=(const MutantStack &src){
			if (*this != src){
				std::stack<T>::operator=(src);
			}
			return *this;
		}

		typedef typename
			std::stack<T>::container_type::iterator iterator;
		typedef typename
			std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename
			std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename
			std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(void) {return this->c.begin();};
		iterator end(void) {return this->c.end();};

		const_iterator begin(void) const {return this->c.begin();};
		const_iterator end(void) const {return this->c.end();};

		reverse_iterator rbegin(void) {return this->c.rbegin();};
		reverse_iterator rend(void) {return this->c.rend();};

		const_reverse_iterator rbegin(void) const {return this->c.rbegin();};
		const_reverse_iterator rend(void) const {return this->c.rend();};

		void	push_back(const T &t){this->push(t);}

		T &back(){return this->top();}
		const T &back() const{return this->top();}

		void	pop_back(){this->pop();}
};
