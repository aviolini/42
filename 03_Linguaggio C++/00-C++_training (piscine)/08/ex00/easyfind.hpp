/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:35:36 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/20 13:06:02 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <vector>
#include <list>
#include <iostream>

template<typename C>
typename C::iterator easyfind(C & t, int i)
{
	typename C::iterator it;
	for(it = t.begin(); it != t.end(); it++)
		if (*it == i)
			return it;
	throw std::invalid_argument("NOT FOUND");
}

#endif