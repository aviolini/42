/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:07:43 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/25 18:17:47 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iostream>
#include <vector>
#include <list>

template< typename T, typename C = std::deque< T > >
class MutantStack : public std::stack< T, C >
{
	public:
		MutantStack< T, C >();
		MutantStack< T, C >(MutantStack const &);
		~MutantStack< T, C >();
		MutantStack operator = (MutantStack const &);

		typedef typename std::stack< T, C >::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

#include "mutantstack.cpp"	//WHY?
							//https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
							//https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
#endif
