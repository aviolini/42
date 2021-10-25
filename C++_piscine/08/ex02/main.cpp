/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:05:09 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/30 13:14:26 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template < typename T>
T test()
{
	T c;
	
	c.push(5);
	c.push(17);
	
	std::cout << "[top]\t" << c.top() << std::endl;
	
	c.pop();
	
	std::cout << "[size]\t" << c.size() << std::endl;
	
	c.push(3);
	c.push(5);
	c.push(737);
	//[...]
	c.push(0);
	
	typename T::iterator it = c.begin();
	std::cout << "[begin]\t" << *it << std::endl;

	typename T::iterator ite = c.end();
	
	std::cout << std::endl;
	std::cout << "[iterator]\t" << std::endl;
	++it;
	--it;
	int i = 0;
	while (it != ite)
	{
		std::cout << "[" << i++ << "]\t" << *it << std::endl;
		++it;
	}
	return c;
}

int main()
{
	{
		std::cout << "Original" << std::endl;
		MutantStack< int > mstack = test< MutantStack<int> >() ;
		std::stack<int>  s(mstack);
	}
	std::cout << "---" << std::endl;
	{
		std::cout << "Test parameter 'deque'" << std::endl;
		MutantStack< int, std::deque<int> > mstack = test< MutantStack< int, std::deque<int> > >() ;
		std::stack< int, std::deque<int> > s(mstack);
	}
	std::cout << "---" << std::endl;
	{
		std::cout << "Test parameter 'vector'" << std::endl;
		MutantStack< int, std::vector<int> > mstack = test< MutantStack< int, std::vector<int> > >() ;
		std::stack< int, std::vector<int> > s(mstack);
	}
	std::cout << "---" << std::endl;
	{
		std::cout << "Test parameter 'list'" << std::endl;
		MutantStack< int, std::list<int> > mstack = test< MutantStack< int, std::list<int> > >() ;
		std::stack< int, std::list<int> > s(mstack);
	}


	return 0;
}
