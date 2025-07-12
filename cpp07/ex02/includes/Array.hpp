/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:33:14 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/12 14:47:14 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template <typename T>

class Array{
	private:
		T *arr;
		unsigned int n;
	
	public:
		Array<T>() : n(0){ this->arr = new T[0];} 
		~Array<T>() {delete [] arr;}
		Array<T>(unsigned int n) : n(n){
			this->arr = new T[this->n];
			for (int i; i < this->n; i++)
				this->arr[i] = new T();
		}

		Array<T>(const Array &src) : n(src.n){
			this->arr = new T[n];
			for (int i = 0; i < this->n; i++)
				this->arr[i] = src.arr[i];
		}

		Array<T> &operator=(const Array &src){
			if (this != &src){
				delete [] this->arr;
				this->n = src.n;
				this->arr = new T[this->n];
				for (int i = 0; i < this->n; i++)
					this->arr[i] = src.arr[i];
			}
			return (*this);
		}

		T &operator[](unsigned int index){
			if (index < 0 || index >= n)
				throw IndexArrayOverflowException();
			return (arr[index]);
		}

		unsigned int size() const {return this->n;}

		class IndexArrayOverflowException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Index passed is bigger than array size";
				}
		};
};
