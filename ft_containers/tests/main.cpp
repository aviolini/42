/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:13:14 by arrigo            #+#    #+#             */
/*   Updated: 2021/11/12 15:53:08 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#if STD
#include <vector>
#include <stack>
#include <map>
namespace ft = std;
#else
#include "../vector.hpp"
#include "../stack.hpp"
#include "../map.hpp"
#endif

#include "vectorTests.cpp"
#include "stackTests.cpp"
#include "mapTests.cpp"


int main(int argc, char** argv) {

	(void)argc;
	(void)argv;
	
	// vectorTest< ft::vector<int> >();
	// stackTest< ft::stack<int, ft::vector<int> > > ();
	
	mapTest< ft::map<char,int, std::less<char>, std::allocator<ft::pair<char,int> > > >();

	return (0);
}