/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:40:25 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/27 12:41:50 by arrigo           ###   ########.fr       */
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
	void setRawBits( int const raw );
	Fixed & operator=(Fixed const &cl);
	int toInt(void) const;
	float toFloat() const;

	private:
	int fixed_point_value;
	static const int fractional_bits = 8;
};

std::ostream & operator<<( std::ostream &o, Fixed const &cl );

# endif
