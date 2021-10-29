/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:45:44 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/29 09:45:49 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "../vector.hpp"
#include "../stack.hpp"
#include "../map.hpp"

#include "vectorTests.cpp"
#include "stackTests.cpp"
#include "mapTests.cpp"


int main(int argc, char** argv) {

	(void)argc;
	(void)argv;
	
	vectorTest< ft::vector<int> >();
	// stackTest< ft::stack<int, ft::vector<int> > > ();


	return (0);
}
