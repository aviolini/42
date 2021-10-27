/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:03:25 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/27 08:57:44 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template< typename T, typename C >
class MutantStack : public T 
{
	public:
		MutantStack< T, C >(){}
		MutantStack< T, C >(MutantStack const & obj) : T(obj){}
		~MutantStack< T, C >();
		MutantStack operator = (MutantStack const & obj)
		{
			T::operator = (obj);
		}
		typedef typename T::container_type::iterator iterator;
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};

template<typename S>
void stackTest()
{
	// S data1;
	typename S::container_type container;
	S data2(container);
	(void)data2;
}