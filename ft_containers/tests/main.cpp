/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:13:14 by arrigo            #+#    #+#             */
/*   Updated: 2021/12/07 01:02:27 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <list>

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

//MY
int main() 
{

	// stackTest< ft::stack<int, ft::vector<int> > > ();			//LEAKS
	// stackTest< ft::stack<int, std::deque<int> > > ();

	vectorTest< ft::vector<int> >();							//LEAKS

	// ft::pair<const char, int> (*ptr)(const char, int) = &ft::make_pair<const char, int>;
	// mapTest< ft::map<char,int, std::less<char>, std::allocator<ft::pair <const char, int > > >, ft::pair<const char, int> >(ptr);
	// ft::vector<int> ciao(5);

	return (0);
}