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

template <typename T>

class Array{
	private:
		T *arr;
		unsigned int n;
	
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array &src);
		Array &operator=(const Array &src);
		Array &operator[](unsigned int index);

		unsigned int size() const;
};
