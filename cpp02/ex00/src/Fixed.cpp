/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:24:36 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/03 20:36:07 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _fpnv(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy; //Operator overlaod
}

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}

//Operator 
Fixed &Fixed::operator =(const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src){
		this->_fpnv = src.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fpnv);
}

void Fixed::setRawBits(int const raw){ this->_fpnv = raw;}
