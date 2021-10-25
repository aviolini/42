/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:07:22 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/24 19:01:38 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_C	
#define MUTANTSTACK_C	

#include "mutantstack.hpp"

template < typename T, typename C > 
MutantStack< T, C >::MutantStack()
{}

template < typename T, typename C >
MutantStack< T, C >::MutantStack(MutantStack< T, C > const & obj) : std::stack< T, C >(obj)
{}

template < typename T, typename C >
MutantStack< T, C > MutantStack< T, C >::operator = (MutantStack< T, C > const & obj)
{
	std::stack< T, C >::operator = (obj);
}

template < typename T, typename C >
MutantStack< T, C >::~MutantStack()
{}

template <typename T, typename C>
typename MutantStack< T, C >::iterator MutantStack< T, C >::begin()
{
	return this->c.begin();
}

template < typename T, typename C >
typename MutantStack< T, C >::iterator MutantStack< T, C >::end()
{
	return this->c.end();
}

#endif
