/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:01:37 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/24 02:20:59 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template<typename C>
void printTree(C &m, std::string name)
{
	m._tree.print(name);
}

template<typename C>
void printMap(C &m, std::string name)
{
	std::cout << "-----" << name << "-----------------------" << std::endl;
	if (m.empty())
	{
		std::cout << "EMPTY MAP" << std::endl;
		std::cout << "------------------------------" << std::endl;
		return ;
	}
	std::cout << "size:" << m.size() << std::endl;
	std::cout << "content: "<< std::endl;
	typename C::iterator it = m.begin();;
	for (; it != m.end() ; ++it)
		std::cout << "F: " << it->first << "\tS: " << it->second <<  std::endl;
	std::cout << "-----------------------------" << std::endl;
}

template<typename C, typename PAIR>
void mapTest(PAIR (*makepair)(const char, int))
{
	C test1;
	// // char startC = 'a';
	// // char startN = 1;
	typename C::value_type pair1 ('a', 1);
	typename C::value_type pair2('b', 2);
	typename C::value_type pair3('c', 3);
	typename C::value_type pair4('e', 4);
	typename C::value_type pair5('f', 5);
	typename C::value_type pair9('l', 9);
	typename C::value_type pair6('g', 6);
	
	test1.insert(makepair('r', 15));
	test1.insert(pair4);
	test1.insert(pair1);
	test1.insert(pair5);
	test1.insert(pair2);
	test1.insert(pair9);
	test1.insert(pair3);
	test1.insert(pair6);
	test1.insert(makepair('h', 7));
	test1.insert(makepair('i', 8));
	test1.insert(makepair('n', 11));
	test1.insert(makepair('p', 13));
	test1.insert(makepair('m', 10));
	test1.insert(makepair('o', 12));
	// test1.insert(makepair('s', 16));
	
///*	
//SIZE------------------------------------------------------------
	std::cout << "TEST1_SIZE:" <<test1.size() << std::endl;
	// std::cout << "TEST1_MAXSIZE:" <<test1.max_size() << std::endl;
	std::cout << "TEST1_EMPTY:" <<test1.empty() << std::endl;
	C test2;
	std::cout << "TEST2_SIZE:" << test2.size() << std::endl;
	// std::cout << "TEST2_MAXSIZE:" <<test2.max_size() << std::endl;
	std::cout << "TEST2_EMPTY:" <<test2.empty() << std::endl;
// -----------------------------------------------------------------
// FIND------------------------------------------------------------
	int i = 1;
	for (typename C::iterator itfind1 = test1.begin(); itfind1->first != 'm'; ++itfind1)
		++i;
	// std::cout << "I:" << i << std::endl;

	std::cout << (test1.find('m'))->first << std::endl;
	std::cout << (test1.find('m') == test1.end()) << std::endl;
	std::cout << (test1.find('z') == test1.end()) << std::endl;
// -----------------------------------------------------------------
// INSERT-SINGLE---------------------------------------------------------
	// std::cout << ((test1.insert(makepair('o', 12))).first->first) << std::endl;
	// std::cout << ((test1.insert(makepair('o', 12))).second) << std::endl;
	// std::cout << ((test1.insert(makepair('o', 12))).first->first) << std::endl;
	// std::cout << ((test1.insert(makepair('o', 12))).second) << std::endl;
	// printMap(test1, "TEST1");
// -----------------------------------------------------------------
// INSERT-ITERATOR-----------------------------------------------------
	PAIR array1[] = {makepair('a', 1), makepair('b', 2), makepair('c', 3), makepair('d', 4)};
	C test3;
	test3.insert(array1, &array1[4]);
	(void)array1;
	printMap(test3, "TEST3");
// -----------------------------------------------------------------
// INSERT-ITERATOR-----------------------------------------------------
	C test4;
	test4.insert(test1.begin(), test1.end());
	printMap(test4, "TEST4");
// -----------------------------------------------------------------

// ITERATOR-CONSTRUCTOR------------------------------------------------
	C test5(test1.begin(), test1.end());
	// printMap(test5, "TEST5");
// -----------------------------------------------------------------
/*
// ITERATOR++      ------------------------------------------------
	std::cout << "------ITERATOR ++------" << std::endl;
	typename C::iterator it3 = test5.begin();
	// ++it3;
	for (; it3 != test5.end(); it3++)
		std::cout << it3->first << std::endl;
	std::cout << "------------------------------" << std::endl;
// -----------------------------------------------------------------
// ITERATOR--      ------------------------------------------------
	std::cout << "-----ITERATOR --    ------" << std::endl;
	typename C::iterator it4 = test5.end();
	--it4;
	for (; it4 != test5.begin(); it4--)
		std::cout << it4->first << std::endl;
	std::cout << "------------------------------" << std::endl;
// -----------------------------------------------------------------
// REV ITERATOR++      ------------------------------------------------
	std::cout << "-----REV ITERATOR ++-------" << std::endl;
	typename C::reverse_iterator it5 = test5.rend();
	// ++it5;
	for (; it5 != test5.rbegin(); it5--)
		std::cout << it5->first << std::endl;
std::cout << "------------------------------" << std::endl;	
// -----------------------------------------------------------------
// REV ITERATOR--      ------------------------------------------------
	std::cout << "-----REV ITERATOR --   -------" << std::endl;
	typename C::reverse_iterator it6 = test5.rbegin();
	// typename C::reverse_iterator it7 = test5.rend();
	// ++it6;
	for (; it6 != test5.rend(); it6++)
		std::cout << it6->first << std::endl;
	std::cout << "------------------------------" << std::endl;	
// -----------------------------------------------------------------
*/
// COPY-CONSTRUCTOR---------------------------------------------------
	C test6(test5);
	printMap(test6, "TEST6");
// // -----------------------------------------------------------------

// // ASSIGN-OPERATOR---------------------------------------------------
	C test7;
	test7 = test5;
	printMap(test7, "TEST7");
// -----------------------------------------------------------------

// // ERASE---------------------------------------------------
	test1.erase('i');	//OK	//0
	test1.erase('p');	//OK	//2
	test1.erase('g');	//OK	//1
	test1.erase('b');	//OK	//1
	test1.erase('n');	//OK	//3
	test1.erase('l');	//OK	//3
	test1.erase('a');	//OK	//3
	test1.erase('e');	//OK	//3
	test1.erase('r');	//OK	//3
	test1.erase('c');	//OK	//3
	test1.erase('f');	//OK	//3
	test1.erase('h');	//OK	//3
	printMap(test1, "TEST1");
// --INSERT AFTER ERASE--------------------------------KO-------------------------------
	test1.erase('o');
	test1.erase('m');
	printMap(test1, "TEST1");
	test1.insert(makepair('f', 6));
	printMap(test1, "TEST1");
// ---INSERT 1 ELEMENT, ERASE AND REINSERT ------------------OK--------------------------
	C test8;
	test8.insert(makepair('h', 8));
	printMap(test8, "TEST8");
	test8.erase('h');				
	printMap(test8, "TEST8");
	test8.insert(makepair('h', 8));
	printMap(test8, "TEST8");
// ---INSERT 2 ELEMENT, ERASE FIRST AND REINSERT -----------OK---------------------------------
	C test9;
	test9.insert(makepair('h', 8));
	test9.insert(makepair('i', 9));
	printMap(test9, "TEST9");
	test9.erase('h');
	printMap(test9, "TEST9");
	test9.insert(makepair('h', 8));
	printMap(test9, "TEST9");
}