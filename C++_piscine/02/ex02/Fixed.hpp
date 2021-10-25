/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:40:25 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/27 16:02:37 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_H
# define _FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &cl);
	Fixed(const int n);
	Fixed(const float n);

	int getRawBits( void ) const;
	void setRawBits( const int raw );
	void setRawBits( const float raw );

	Fixed & operator=( Fixed const &cl );
	bool operator>( const Fixed &cl ) const;
	bool operator<( const Fixed &cl ) const;
	bool operator>=( const Fixed &cl ) const;
	bool operator<=( const Fixed &cl ) const;
	bool operator==( const Fixed &cl ) const;
	bool operator!=( const Fixed &cl ) const;
	Fixed operator+( const Fixed &cl );
	Fixed operator-( const Fixed &cl );
	Fixed operator*( const Fixed &cl );
	Fixed operator/( const Fixed &cl );
	Fixed & operator++(); //Prefix increment
	Fixed operator++(int); //Postfix increment

	static Fixed & min(Fixed &a, Fixed &b);
	static Fixed const & min(Fixed const &a, Fixed const &b);
	static Fixed & max(Fixed &a, Fixed &b);
	static Fixed const & max(Fixed const &a, Fixed const &b);
	
	int toInt(void) const;
	float toFloat() const;

	private:
	int fixed_point_value;
	static const int fractional_bits = 8;
};

std::ostream & operator<<( std::ostream &o, Fixed const &cl );

# endif
