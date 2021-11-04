/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:01:37 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/04 17:25:04 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../map.hpp"

template<typename C>
void mapTest()
{
	//PAIR////////////
	std::pair<std::string, int> pair1("primo", 1);
	std::cout << "STD::PAIR\t" << pair1.first << " , " << pair1.second << std::endl;
	ft::pair<std::string, int> pair2("primo", 1);
	std::cout << "FT::PAIR\t" << pair2.first << " , " << pair2.second << std::endl;
	//MAKE PAIR///////
	std::cout << "STD::MAKE_PAIR\t" <<  (std::make_pair<std::string, int> ("secondo", 2)).first << (std::make_pair<std::string, int> ("secondo", 2)).second << std::endl;
	std::cout << "FT::MAKE_PAIR\t" <<  (ft::make_pair<std::string, int> ("secondo", 2)).first << (ft::make_pair<std::string, int> ("secondo", 2)).second << std::endl;

	ft::tree<ft::pair<std::string,int> > t;
	t.addnode(pair2);
	ft::pair<std::string, int> pair3("terzo", 3);
	ft::pair<std::string, int> pair4("quarto", 4);

	t.addnode((pair3));
	t.addnode((pair4));
	
	std::cout << t._b->_content.first << std::endl;

	
	std::cout << t._b->_r->_content.first << std::endl;
	





	
}