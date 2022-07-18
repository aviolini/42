/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:40:25 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/25 18:45:37 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_H
# define _FIXED_H

#include <iostream>

class Fixed
{
	public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &a);
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed & operator=(Fixed const &a);
	
	private:
	int fixed_point_value;
	static const int fractional_bits = 8;
};

# endif
