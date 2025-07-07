/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:30:13 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/07 13:34:23 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <class T>

void	iter(T *array, size_t len, void(*f)(T&)){
	for (size_t i = 0; i < len; i++)
		(*f)(array[i]);
}

template <class T>

void	iter(T *array, size_t len, void(*f)(const T&)){
	for (size_t i = 0; i < len; i++)
		(*f)(array[i]);
}
