/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:35:33 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/30 12:47:52 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <exception>

template<typename C>
void test(C & t, int val)
{
	try
	{
		typename C::iterator it = easyfind(t, val);
		std::cout << "FOUND:\t\t" << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
		std::cerr << ":\t" << val << std::endl;
	}
}

template<typename C>
void print(C & t)
{
	std::cout << "print: " << std::endl;
	typename C::iterator it;
	for(it = t.begin(); it != t.end(); it++)
		std::cout << *it << std::endl;
}

int main()
{
	std::list<int>		lst1(1,101);
	std::list<int>		lst2;
	std::vector<int>	v1(1, 301);
	std::vector<int>	v2;
	
	lst1.push_front(100);
	lst1.push_back(102);

	for (int i = 200; i < 210; i++)
		lst2.push_back(i);
	
	v1.push_back(302);
	v1.push_back(303);

	for (int i = 400; i < 410; i++)
		v2.push_back(i);
	
	std::cout << "List1 ";
	print(lst1);
	std::cout << "List2 ";
	print(lst2);
	std::cout << "Vector1 ";
	print(v1);
	std::cout << "Vector2 ";
	print(v2);

	std::cout << "----" << std::endl;
	
	std::cout << "List1 search:" << std::endl;
	test(lst1, 99);
	test(lst1, 100);
	test(lst1, 102);
	test(lst1, 103);
	std::cout << std::endl;

	std::cout << "List2 search:" << std::endl;
	test(lst2, 199);
	test(lst2, 200);
	test(lst2, 209);
	test(lst2, 210);
	std::cout << std::endl;

	std::cout << "Vector1 search:" << std::endl;
	test(v1, 300);
	test(v1, 301);
	test(v1, 303);
	test(v1, 304);
	std::cout << std::endl;

	std::cout << "Vector2 search:" << std::endl;
	test(v2, 399);
	test(v2, 400);
	test(v2, 409);
	test(v2, 410);
	std::cout << std::endl;

	return 0;
}