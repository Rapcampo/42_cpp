/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:00:00 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/07 13:02:56 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

//note to self, XOR swap is not valid with templates :'c

template <typename T>

void	swap(T &a, T &b){
	T t = a;
	a = b;
	b = t;
}

template <typename T>

T max(T a, T b){
	return (a > b ? a : b);
}

template <typename T>

T min(T a, T b){
	return (a < b ? a : b);
}
