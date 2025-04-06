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

Fixed::Fixed(void) : _fpnv(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _fpnv(val * (1 << _fracb)){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fval) : _fpnv(int(fval * (1 << _fracb) + 0.5)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy; //Operator overlaod
}

Fixed::~Fixed(void){std::cout << "Destructor called" << std::endl;}

//Operator overload
Fixed &Fixed::operator =(const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src){
		this->_fpnv = src._fpnv;
	}
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fpnv);
}

void Fixed::setRawBits(int const raw) {this->_fpnv = raw;}

float Fixed::toFloat(void) const{
	int characteristic;
	int mantissa;
	float fpointnb;

	characteristic = this->_fpnv >> this->_fracb;
	mantissa = this->_fpnv & ((1 << this->_fracb) - 1);
	fpointnb = mantissa / float(1 << this->_fracb);

	return (float(characteristic) + fpointnb);
}

int	Fixed::toInt(void) const {
	return this->_fpnv >> _fracb;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
	out << fixed.toFloat();
	return (out);
}

