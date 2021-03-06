/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:01:37 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/30 14:47:15 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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
	std::cout << "======================MAP TEST==================" << std::endl;
	C test1;
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
//SIZE------------------------------------------------------------
	std::cout << "TEST1_SIZE: " << test1.size() << std::endl;
	// std::cout << "TEST1_MAXSIZE: " << test1.max_size() << std::endl;
	std::cout << "TEST1_EMPTY: " << test1.empty() << std::endl;
	C test2;
	std::cout << "TEST2_SIZE: " << test2.size() << std::endl;
	// std::cout << "TEST2_MAXSIZE: " << test2.max_size() << std::endl;
	std::cout << "TEST2_EMPTY: " << test2.empty() << std::endl;
// FIND------------------------------------------------------------
	int i = 1;
	for (typename C::iterator itfind1 = test1.begin(); itfind1->first != 'm'; ++itfind1)
		++i;
	std::cout << (test1.find('m'))->first << std::endl;
	std::cout << (test1.find('m') == test1.end()) << std::endl;
	std::cout << (test1.find('z') == test1.end()) << std::endl;
// FIND CONST ITERATOR------------------------------------------------------------
	std::cout << "FIND CONST ITERATOR" << std::endl;
	typename C::const_iterator itfind11 = test1.find('m');
	std::cout << itfind11->first << std::endl;
	// itfind11 = test1.find('z');
	std::cout << itfind11->first << std::endl;
// INSERT-SINGLE---------------------------------------------------------
	std::cout << ((test1.insert(makepair('o', 12))).first->first) << std::endl;
	std::cout << ((test1.insert(makepair('o', 12))).second) << std::endl;
	std::cout << ((test1.insert(makepair('o', 12))).first->first) << std::endl;
	std::cout << ((test1.insert(makepair('o', 12))).second) << std::endl;
	#if PRINT_TREE
	test1.print("TEST1");
	#else
	printMap(test1, "TEST1");
	#endif
// INSERT-ITERATOR-----------------------------------------------------
	PAIR array1[] = {makepair('f', 6), makepair('b', 2), makepair('c', 3), makepair('e', 5)};
	C test3;
	test3.insert(array1, &array1[4]);
	(void)array1;
	#if PRINT_TREE
	test3.print("TEST3");
	#else
	printMap(test3, "TEST3");
	#endif
// INSERT-ITERATOR-----------------------------------------------------
	C test4;
	test4.insert(test1.begin(), test1.end());
	#if PRINT_TREE
	test4.print("TEST4");
	#else
	printMap(test4, "TEST4");
	#endif
// INSERT-WITH HINT-----------------------------------------------------
	typename C::iterator it2 = test3.end();
	it2--;
	test3.insert(it2, makepair('e', 5));
	test3.insert(it2, makepair('d', 4));
	test3.insert(it2, makepair('a', 1));
	#if PRINT_TREE
	test3.print("TEST3");
	#else
	printMap(test3, "TEST3");
	#endif
// ITERATOR-CONSTRUCTOR------------------------------------------------
	C test5(test1.begin(), test1.end());
// ITERATOR++      ------------------------------------------------
	std::cout << "------ITERATOR ++------" << std::endl;
	typename C::iterator it3 = test5.begin();
	// ++it3;
	for (; it3 != test5.end(); it3++)
		std::cout << it3->first << std::endl;
	std::cout << "------------------------------" << std::endl;
// ITERATOR--      ------------------------------------------------
	std::cout << "-----ITERATOR --    ------" << std::endl;
	typename C::iterator it4 = test5.end();
	--it4;
	for (; it4 != test5.begin(); it4--)
		std::cout << it4->first << std::endl;
	std::cout << "------------------------------" << std::endl;
// REV ITERATOR++      ------------------------------------------------
	std::cout << "-----REV ITERATOR ++-------" << std::endl;
	typename C::reverse_iterator it5 = test5.rbegin();
	// ++it5;
	for (; it5 != test5.rend(); it5++)
		std::cout << it5->first << std::endl;
std::cout << "------------------------------" << std::endl;
// REV ITERATOR--      ------------------------------------------------
	std::cout << "-----REV ITERATOR --   -------" << std::endl;
	typename C::reverse_iterator it6 = test5.rend();
	--it6;
	for (; it6 != test5.rbegin(); it6--)
		std::cout << it6->first << std::endl;
// CONST_ITERATOR      ------------------------------------------------
	std::cout << "------CONST_ITERATOR------" << std::endl;
	typename C::const_iterator it31 = test5.begin();
	// ++it3;
	for (; it31 != test5.end(); it31++)
		std::cout << it31->first << std::endl;
	std::cout << "------------------------------" << std::endl;
// COPY-CONSTRUCTOR---------------------------------------------------
	C test6(test1);
	#if PRINT_TREE
	test6.print("TEST6");
	#else
	printMap(test6, "TEST6");
	#endif
// // ASSIGN-OPERATOR---------------------------------------------------
	C test7;
	test7 = test1;
	#if PRINT_TREE
	test7.print("TEST7");
	#else
	printMap(test7, "TEST7");
	#endif
// []---------------------------------------------
	std::cout << "TEST []" << std::endl;
	std::cout << test1['g'] << std::endl;
	std::cout << test1['d'] << std::endl;
	std::cout << test1['q'] << std::endl;
	std::cout << test1['t'] << std::endl;
	std::cout << test1['z'] << std::endl;
	#if PRINT_TREE
	test1.print("TEST1");
	#else
	printMap(test1, "TEST1");
	#endif
	// C test10(test1);
// // ERASE POSITIONS---------------------------------------------
	test1.erase(test1.find('n'));	//OK	//3
	test1.erase(test1.find('h'));	//OK	//3
// // ERASE---------------------------------------------------
	// test1.insert(makepair('t', 22));
	test1.erase('i');	//OK	//0
	test1.erase('p');	//OK	//2
	test1.erase('g');	//OK	//1
	test1.erase('b');	//OK	//1
	test1.erase('l');	//OK	//3
	test1.erase('a');	//OK	//3
	test1.erase('e');	//OK	//3
	test1.erase('r');	//OK	//3
	test1.erase('c');	//OK	//3
	test1.erase('f');	//OK	//3
	test1.erase('v');	//OK	//3
// --INSERT AFTER ERASE--------------------------------KO-------------------------------
	test1.erase('o');
	test1.erase('m');
	#if PRINT_TREE
	test1.print("TEST1");
	#else
	printMap(test1, "TEST1");
	#endif
// // ---INSERT 1 ELEMENT, ERASE AND REINSERT ------------------OK--------------------------
	C test8;
	test8.insert(makepair('h', 8));
	#if PRINT_TREE
	test8.print("TEST8");
	#else
	printMap(test8, "TEST8");
	#endif
	test8.erase('h');				
	#if PRINT_TREE
	test8.print("TEST8");
	#else
	printMap(test8, "TEST8");
	#endif
	test8.insert(makepair('h', 8));
	#if PRINT_TREE
	test8.print("TEST8");
	#else
	printMap(test8, "TEST8");
	#endif
// // ---INSERT 2 ELEMENT, ERASE FIRST AND REINSERT -----------OK---------------------------------
	C test9;
	test9.insert(makepair('h', 8));
	test9.insert(makepair('i', 9));
	#if PRINT_TREE
	test9.print("TEST9");
	#else
	printMap(test9, "TEST9");
	#endif
	test9.erase('h');
	#if PRINT_TREE
	test9.print("TEST9");
	#else
	printMap(test9, "TEST9");
	#endif
	test9.insert(makepair('h', 8));
	#if PRINT_TREE
	test9.print("TEST9");
	#else
	printMap(test9, "TEST9");
	#endif
// // ERASE ITERATORS---------------------------------------------
	C test10;
	test10.insert(makepair('r', 15));
	test10.insert(pair4);
	test10.insert(pair1);
	test10.insert(pair5);
	test10.insert(pair2);
	test10.insert(pair9);
	test10.insert(pair3);
	test10.insert(pair6);
	test10.insert(makepair('h', 7));
	test10.insert(makepair('i', 8));
	test10.insert(makepair('n', 11));
	test10.insert(makepair('p', 13));
	test10.insert(makepair('m', 10));
	test10.insert(makepair('o', 12));
	C test11(test10);
	#if PRINT_TREE
	test10.print("TEST10");
	#else
	printMap(test10, "TEST10");
	#endif
	test10.erase(++test10.begin(), --test10.end());
	#if PRINT_TREE
	test10.print("TEST10");
	#else
	printMap(test10, "TEST10");
	#endif
	test10.erase(test10.begin(), --test10.end());
	#if PRINT_TREE
	test10.print("TEST10");
	#else
	printMap(test10, "TEST10");
	#endif
// // CLEAR---------------------------------------------
	#if PRINT_TREE
	test11.print("TEST11");
	#else
	printMap(test11, "TEST11");
	#endif
	C test12(test11);
	test11.clear();
	#if PRINT_TREE
	test11.print("TEST11");
	#else
	printMap(test11, "TEST11");
	#endif
	test11.insert(makepair('i', 9));
	#if PRINT_TREE
	test11.print("TEST11");
	#else
	printMap(test11, "TEST11");
	#endif
// // OBSERVERVERS---------------------------------------------
	typename C::key_compare key_comp = test11.key_comp();
	std::cout << "KEY COMP: " << key_comp(test11.begin()->first, 'h') << std::endl;
	std::cout << "KEY COMP: " << key_comp(test11.begin()->first, 'l') << std::endl;
	typename C::value_compare value_comp = test11.value_comp();
	(void)value_comp;
	std::cout << "VALUE COMP: " << value_comp(*test11.begin(), makepair('h', 8)) << std::endl;
	std::cout << "VALUE COMP: " << value_comp(*test11.begin(), makepair('l', 10)) << std::endl;
// // COUNT---------------------------------------------
	std::cout << "COUNT: " << test11.count('i') << std::endl;
	std::cout << "COUNT: " << test11.count('v') << std::endl;
// // LOWER BOUND AND UPPER BOUND---------------------------------------------
	C test13(test12);
	#if PRINT_TREE
	test12.print("TEST12");
	#else
	printMap(test12, "TEST12");
	#endif
	typename C::iterator lowB = test12.lower_bound('i');
	typename C::iterator upB = test12.upper_bound('p');
	std::cout << "LOWER BOUND: " << lowB->first << std::endl;
	std::cout << "UPPER BOUND: " << upB->first << std::endl;
	test12.erase(lowB, upB);
	#if PRINT_TREE
	test12.print("TEST12");
	#else
	printMap(test12, "TEST12");
	#endif
// // LOWER BOUND AND UPPER BOUND---------------------------------------------
	C test14(test13);
	#if PRINT_TREE
	test13.print("TEST13");
	#else
	printMap(test13, "TEST13");
	#endif
	typename C::const_iterator ClowB = test13.lower_bound('i');
	typename C::const_iterator CupB = test13.upper_bound('o');
	std::cout << "LOWER BOUND: " << ClowB->first << std::endl;
	std::cout << "UPPER BOUND: " << CupB->first << std::endl;
	#if PRINT_TREE
	test13.print("TEST13");
	#else
	printMap(test13, "TEST13");
	#endif
// // EQUAL RANGE---------------------------------------------
	std::cout << test14.equal_range('g').first->first << std::endl;
	std::cout << test14.equal_range('g').second->first << std::endl;
// // SWAP---------------------------------------------
	std::cout << "SWAP :" << std::endl;
	printMap(test11, "TEST11");
	#if PRINT_TREE
	test13.print("TEST13");
	#else
	printMap(test13, "TEST13");
	#endif
	test13.swap(test11);
	printMap(test11, "TEST11");
	#if PRINT_TREE
	test13.print("TEST13");
	#else
	printMap(test13, "TEST13");
	#endif
	{
	//------------------------PRINT TREE---------------------------------------------
	C test1;
	test1.insert(makepair('r', 15));
	test1.insert(makepair('R', 15));
	test1.insert(makepair('G', 15));
	test1.insert(pair4);
	test1.insert(pair5);
	test1.insert(pair9);
	test1.insert(pair6);
	test1.insert(makepair('h', 7));
	test1.insert(makepair('i', 8));
	test1.insert(makepair('n', 11));
	test1.insert(makepair('A', 11));
	test1.insert(makepair('H', 11));
	test1.insert(makepair('3', 11));
	test1.insert(makepair('6', 11));
	test1.insert(makepair('Z', 11));
	test1.insert(makepair('k', 11));
	test1.insert(makepair('p', 13));
	test1.insert(makepair('m', 10));
	test1.insert(makepair('o', 12));
	test1.insert(makepair('t', 13));
	test1.insert(makepair('v', 12));
	test1.insert(makepair('u', 10));
	test1.insert(makepair('5', 10));
	test1.insert(makepair('z', 12));
	test1.insert(makepair('s', 12));
	test1.insert(makepair('j', 12));
	test1.insert(test12.begin(), test12.end());
	#if PRINT_TREE
	test1.print("TEST1");
	#else
	printMap(test1, "TEST1");
	#endif
	std::cout << "======================END MAP TEST==================" << std::endl;
	}
}