/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:40:21 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/30 18:46:02 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixed_point_value(0)
{}

Fixed::~Fixed()
{}
Fixed::Fixed(const Fixed &cl)
{
	*this = cl;	
}

Fixed::Fixed(const int n)
{
	this->fixed_point_value = n << Fixed::fractional_bits;
}

//CONVERSION	
//fixed_point_value = roundf(floating_point_value * scaling_factor)
Fixed::Fixed(const float n)
{
	this->fixed_point_value = roundf(n *(1 << this->fractional_bits));
}

int Fixed::getRawBits( void ) const
{
	return this->fixed_point_value;
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_point_value = raw;
}

int Fixed::toInt() const
{
	return(roundf(this->toFloat()));
}

//CONVERSION
//floating_point_value = ((float)fixed_point_value)/scaling_factor
float Fixed::toFloat() const
{
	return ((float)this->fixed_point_value / (float)(1 << this->fractional_bits));
}

/*OPERATOR*/

std::ostream & operator<<( std::ostream & o, Fixed const & cl )
{
	o << cl.toFloat();
	return o;
}

Fixed & Fixed::operator=( const Fixed &cl )
{
	this->fixed_point_value = cl.fixed_point_value;
	return *this;
}

bool Fixed::operator>( const Fixed &cl ) const
{
	if (this->fixed_point_value > cl.fixed_point_value)
		return true;
	return false;
}

bool Fixed::operator<( const Fixed &cl ) const
{
	if (this->fixed_point_value < cl.fixed_point_value)
		return true;
	return false;
}

bool Fixed::operator>=( const Fixed &cl ) const
{
	if (this->fixed_point_value >= cl.fixed_point_value)
		return true;
	return false;
}

bool Fixed::operator<=( const Fixed &cl ) const
{
	if (this->fixed_point_value <= cl.fixed_point_value)
		return true;
	return false;
}

bool Fixed::operator==( const Fixed &cl ) const
{
	if (this->fixed_point_value == cl.fixed_point_value)
		return true;
	return false;
}

bool Fixed::operator!=( const Fixed &cl ) const
{
	if (this->fixed_point_value != cl.fixed_point_value)
		return true;
	return false;
}

Fixed Fixed::operator+( const Fixed &cl ) const
{
	Fixed new_cl;
	new_cl.fixed_point_value = this->fixed_point_value + cl.fixed_point_value;
	return new_cl;
}

Fixed Fixed::operator-( const Fixed &cl ) const
{
	Fixed new_cl;
	new_cl.fixed_point_value = this->fixed_point_value - cl.fixed_point_value;
	return new_cl;
}

Fixed Fixed::operator*( const Fixed &cl ) const
{
	Fixed new_cl;
	new_cl.fixed_point_value = (this->fixed_point_value * cl.fixed_point_value)/ (1 << this->fractional_bits);
	return new_cl;
}

Fixed Fixed::operator/( const Fixed &cl ) const
{
	Fixed new_cl;
	new_cl.fixed_point_value = (this->fixed_point_value * (1 << this->fractional_bits)) / cl.fixed_point_value;
	return new_cl;
}

Fixed & Fixed::operator++()		//Prefix increment 
{
	this->fixed_point_value++;
	return *this;
}

Fixed Fixed::operator++(int)	//Postfix increment 
{
	Fixed new_cl = *this;
	++*this;
	return new_cl;
}

/* MAX E MIN */

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed const & Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	else 
		return b;		
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;		
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	else
		return b;		
}

