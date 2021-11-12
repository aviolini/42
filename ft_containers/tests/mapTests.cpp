/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:01:37 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/12 16:29:32 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template<typename C>
void mapTest()
{
	// //PAIR////////////
	// ft::pair<std::string, int> pair1("primo", 1);
	// std::cout << "STD::PAIR\t" << pair1.first << " , " << pair1.second << std::endl;
	// ft::pair<std::string, int> pair2("primo", 1);
	// std::cout << "FT::PAIR\t" << pair2.first << " , " << pair2.second << std::endl;
	// //MAKE PAIR///////
	// std::cout << "STD::MAKE_PAIR\t" <<  (std::make_pair<std::string, int> ("secondo", 2)).first << (std::make_pair<std::string, int> ("secondo", 2)).second << std::endl;
	// std::cout << "FT::MAKE_PAIR\t" <<  (ft::make_pair<std::string, int> ("secondo", 2)).first << (ft::make_pair<std::string, int> ("secondo", 2)).second << std::endl;

	// ft::node <ft::pair<std::string,int> > n(pair2);

	// std::cout << n.first << std::endl;

	// ft::tree<ft::pair<std::string,int> > t;
	// t.addnode(pair2);
	
	// ft::tree<ft::pair<std::string,int> >::iterator it1 = t.begin();  //METTERE CONST 
	// std::cout << (*it1).first << std::endl;
	// std::cout << (*it1).second << std::endl;

	

	// ft::tree<ft::pair<std::string,int> > t;
	// t.addnode(pair2);
	// ft::pair<std::string, int> pair3("terzo", 3);
	// ft::pair<std::string, int> pair4("quarto", 4);

	// t.addnode((pair3));
	// t.addnode((pair4));
	
	
	// std::cout << t._b->_content.first << std::endl;

	
	// std::cout << t._b->_r->_content.first << std::endl;


	// ft::tree<ft::pair<std::string,int> >::iterator it1 = t.begin();
	// std::cout << (*it1)._content.first << std::endl;

	
	//MAP
	C test1;
	// // char startC = 'a';
	// // char startN = 1;
	typename C::value_type pair1 ('a', 1);
	// typename C::value_type pair2('b', 2);
	// test1.insert(pair1);
	(void)pair1;
	// (void)pair2;
	(void)test1;

	// for (int i = 0; i < 20; i+=2)
	// 	test1.insert(std::make_pair<char, int>(startC + i,startN + i));
	// for (int i = 0; i < 20; i+=2)
	// 	test1.insert(std::make_pair<char, char>(startC + i,startN + i));
	// typename C::iterator it1 = test1.begin();
	// for (;it1 != test1.end(); ++it1)
	// {
	// 	std::cout << "F: " << (*it1).first << "\tS: " << (*it1).second <<  std::endl;
	// 	// std::cout << "A: " << &(*it1) << "\tA_F: " << &(*it1).first << "\tA_S: " << &(*it1).second << std::endl;
	// }
	
	// std::cout << test1.__tree_.__begin_node_ << std::endl;
	
}