/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSTL.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:26:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/05 11:27:26 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// #include "../vectorOR.hpp"
#include <vector>
#include <stack>
#include "../mapOr.hpp"

// #include <iterator>
// #include <type_traits>


#include "vectorTests.cpp"
#include "stackTests.cpp"
#include "mapTests.cpp"


int main()
{
	// vectorTest< std::vector<int> >();
	// stackTest< std::stack<int, std::vector<int> > > ();
	mapTest<std::map<char,int> >();

	return 0;
}
