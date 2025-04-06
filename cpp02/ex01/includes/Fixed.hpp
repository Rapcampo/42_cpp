/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:19:04 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/05 18:19:36 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

class Fixed{
	private:
		int	_fpnv;
		static const int _fracb = 8;

	public:
		Fixed(); //default constructor
		~Fixed(); //default destructor
		Fixed(const int val);
		Fixed(const float fval);
		Fixed(const Fixed &cp); //copy constructor
		Fixed &operator = (const Fixed &src); //Assigment Operator
	//	Fixed &operator << (const Fixed &src); //Insertion overload
	
		float toFloat(void) const; //converter int to float
		int toInt(void) const; //converter float to int
		
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream&out, const Fixed &fixed);
