/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:32:28 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/16 17:53:11 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

template< typename T >
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template< typename T >
T const max(T const &a, T const &b)
{
	if (a >= b)
		return a;
	return b;
}

template< typename T >
T const min(T const &a, T const &b)
{
	if (a <= b)
		return a;
	return b;
}

#endif