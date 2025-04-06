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
		Fixed();
		~Fixed();
		Fixed(const int val);
		Fixed(const float fval);
		Fixed(const Fixed &cp);

		//arithmatic operators
		Fixed &operator = (const Fixed &src);
		Fixed operator + (const Fixed &src) const;
		Fixed operator - (const Fixed &src) const;
		Fixed operator / (const Fixed &src) const;
		Fixed operator * (const Fixed &src) const;

		//Comparison booleans
		bool operator > (const Fixed &src) const;
		bool operator < (const Fixed &src) const;
		bool operator >= (const Fixed &src) const;
		bool operator <= (const Fixed &src) const;
		bool operator == (const Fixed &src) const;
		bool operator != (const Fixed &src) const;

		//Increment and decrement
		Fixed &operator ++();
		Fixed operator ++(int);
		Fixed &operator --();
		Fixed operator --(int);

		//static methods
		static Fixed &min(Fixed &n1, Fixed &n2);
		static const Fixed &min(const Fixed &n1, const Fixed &n2);
		static Fixed &max(Fixed &n1, Fixed &n2);
		static const Fixed &max(const Fixed &n1, const Fixed &n2);

		//nb converters
		float toFloat(void) const;
		int toInt(void) const;

		//getter and setter
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream&out, const Fixed &fixed);

