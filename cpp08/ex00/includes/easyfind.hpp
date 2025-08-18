/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:52:24 by rapcampo          #+#    #+#             */
/*   Updated: 2025/08/16 18:31:34 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <exception>

template <typename T>

typename T::iterator	easyfind(T& container, int nb)
{
	typename T::iterator res;

	res = (std::find(container.begin(), container.end(), nb));
		if (res == container.end())
			throw std::exception();
	return res;
}
