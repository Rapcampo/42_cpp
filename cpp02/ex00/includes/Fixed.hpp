/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:19:04 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/03 20:27:18 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

class Fixed{
	private:
		int	_fpnv;
		static const int _fracb = 8; //definition of fractional precision points

	public:
		Fixed(); //default constructor
		~Fixed(); //default destructor
		Fixed(const Fixed &cp); //copy constructor
		Fixed &operator=(const Fixed &src); //Assigment Operator
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
