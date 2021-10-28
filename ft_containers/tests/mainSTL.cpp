/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSTL.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:26:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/28 17:30:44 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../vectorOR.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include "vectorTests.cpp"
#include "stackTests.cpp"
#include "mapTests.cpp"


int main()
{
	vectorTest< std::vector<int> >();
	// stackTest< std::stack<int, std::vector<int> > > ();

	return 0;
}
