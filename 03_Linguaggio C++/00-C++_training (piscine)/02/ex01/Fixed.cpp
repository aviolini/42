/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:40:21 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/30 20:37:01 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cl)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cl;	
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = n << Fixed::fractional_bits;
}

//CONVERSION	
//fixed_point_value = roundf(floating_point_value * scaling_factor)
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = roundf(n *(1 << this->fractional_bits));
}

Fixed & Fixed::operator=( Fixed const &cl )
{
	std::cout << "Assignation operator called" << std::endl;	
	this->fixed_point_value = cl.fixed_point_value;
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;	
	return this->fixed_point_value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;	
	this->fixed_point_value = raw;
}

int Fixed::toInt() const
{
	return(roundf(this->toFloat()));
	// return (this->fixed_point_value >> this->fractional_bits);
}

//CONVERSION
//floating_point_value = ((float)fixed_point_value)/scaling_factor
float Fixed::toFloat() const
{
	return ((float)this->fixed_point_value / (float)(1 << this->fractional_bits));
}

std::ostream & operator<<( std::ostream & o, Fixed const & cl )
{
	o << cl.toFloat();
	return o;
}
