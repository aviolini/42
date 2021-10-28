/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSTL.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:26:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/28 15:30:29 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectorOR.hpp"
#include <stack>
#include <iostream>
#include <string>
#include "vectorTests.cpp"
#include "stackTests.cpp"
#include "mapTests.cpp"


int main()
{
	vectorTest< std::vector<int> >();
	// stackTest< std::stack<int, std::vector<int> > > ();

	return 0;
}
