/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:24:36 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/06 16:00:39 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fpnv(0){
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _fpnv(val * (1 << _fracb)){
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fval) : _fpnv(roundf(fval * (1 << _fracb))) {
//	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
//	std::cout << "Copy constructor called" << std::endl;
	*this = copy; //Operator overlaod
}

Fixed::~Fixed(void){/*std::cout << "Destructor called" << std::endl;*/}

//Operator overload
Fixed &Fixed::operator =(const Fixed& src){
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src){
		this->_fpnv = src.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits() const {
//	std::cout << "getRawBits member function called" << std::endl;
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

//comparison booleans

bool Fixed::operator > (const Fixed &src) const {
	return this->_fpnv > src.getRawBits();
}

bool Fixed::operator < (const Fixed &src) const {
	return this->_fpnv < src.getRawBits();
}

bool Fixed::operator >= (const Fixed &src) const {
	return this->_fpnv >= src.getRawBits();
}

bool Fixed::operator <= (const Fixed &src) const {
	return this->_fpnv <= src.getRawBits();
}

bool Fixed::operator == (const Fixed &src) const {
	return this->_fpnv == src.getRawBits();
}

bool Fixed::operator != (const Fixed &src) const {
	return this->_fpnv != src.getRawBits();
}

//increment and decrement

Fixed &Fixed::operator ++ (){return (this->_fpnv++, *this);}

Fixed &Fixed::operator -- (){return (this->_fpnv--, *this);}

Fixed Fixed::operator ++ (int){
	Fixed	org(*this);
	return (this->_fpnv++, org);
}

Fixed Fixed::operator -- (int){
	Fixed org(*this);
	return (this->_fpnv--, org);
}

//Arithmatic operations

Fixed Fixed::operator + (const Fixed &src) const{
	Fixed product;
	product._fpnv = this->_fpnv + src.getRawBits();
	return product;
}

Fixed Fixed::operator - (const Fixed &src) const{
	Fixed product;
	product._fpnv = this->_fpnv - src.getRawBits();
	return product;
}

Fixed Fixed::operator * (const Fixed &src) const{
	Fixed product;
	product._fpnv  = (this->_fpnv * src.getRawBits()) >> _fracb;
	return product;
}
 
Fixed Fixed::operator / (const Fixed &src) const{
	Fixed product;
	product._fpnv  = (this->_fpnv << _fracb) / src.getRawBits();
	return product;
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2){return n1 > n2 ? n1 : n2;}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2){
	return n1 > n2 ? n1:n2;
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2){return n1 < n2 ? n1 : n2;}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2){
	return n1 < n2 ? n1 : n2;
}
