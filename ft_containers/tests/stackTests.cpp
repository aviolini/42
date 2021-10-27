/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:03:25 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/27 13:13:09 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template< typename StackBase, typename Container >											//IMPLEMENT ITERATOR IN STACK TO PRINT STACK
class MutantStack : public StackBase
{
	public:
		MutantStack< StackBase, Container >(){}
		MutantStack< StackBase, Container >(MutantStack const & obj) : StackBase(obj){}
		MutantStack< StackBase, Container >(StackBase const & obj) : StackBase(obj){}
		~MutantStack< StackBase, Container >(){}
		MutantStack operator = (MutantStack const & obj)
		{
			StackBase::operator = (obj);
		}
		typedef typename StackBase::container_type::iterator iterator;
		iterator begin()
		{
			return StackBase::c.begin();
		}
		iterator end()
		{
			return StackBase::c.end();
		}
};

template <typename S>
void printStack(S &s)
{
	MutantStack< S, typename S::container_type > ms(s);
	typename MutantStack< S , typename S::container_type >::iterator it;
	for (it = ms.begin();it != ms.end(); ++it)
		std::cout << *it << std::endl;
}

template<typename S>
void stackTest()
{
	S data1;
	std::cout << data1.empty() << std::endl;
	data1.push(1);
	data1.push(2);
	std::cout << data1.size() << std::endl;
	std::cout << data1.empty() << std::endl;
	printStack<S>(data1);
	typename S::container_type container;
	S data2(container);
	printStack< S >(data2);
	data2.push(6);
	data2.push(7);
	data2.push(8);
	printStack< S >(data2);
	std::cout << data2.size() << std::endl;
	std::cout << data2.top() << std::endl;
	data2.pop();
	printStack< S >(data2);
	
	std::cout << (data1 == data2) << std::endl;
	std::cout << (data1 != data2) << std::endl;
	std::cout << (data1 < data2) << std::endl;
	std::cout << (data1 <= data2) << std::endl;
	std::cout << (data1 > data2) << std::endl;
	std::cout << (data1 >= data2) << std::endl;

}