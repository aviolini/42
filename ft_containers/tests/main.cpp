/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:13:14 by arrigo            #+#    #+#             */
/*   Updated: 2021/11/30 14:32:44 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>

#if STD
#include <vector>
#include <stack>
#include <map>
namespace ft = std;
#else
#include <vector.hpp>
#include <stack.hpp>
#include <map.hpp>
#endif

#include "vectorTests.cpp"
#include "stackTests.cpp"
#include "mapTests.cpp"

int main() 
{

	stackTest< ft::stack<int, ft::vector<int> > > ();
	stackTest< ft::stack<int, std::deque<int> > > ();

	vectorTest< ft::vector<int> >();

	ft::pair<const char, int> (*ptr)(const char, int) = &ft::make_pair<const char, int>;
	mapTest< ft::map<char,int, std::less<char>, std::allocator<ft::pair <const char, int > > >, ft::pair<const char, int> >(ptr);

	return (0);
}