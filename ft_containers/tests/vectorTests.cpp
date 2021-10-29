/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:27:40 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/29 09:46:42 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template<typename C>
void printVec(C &v)
{
	std::cout << "size:" << v.size() << "\tcapacity:" << v.capacity() << std::endl;
	std::cout << "content: ";
	typename C::iterator it = v.begin();;
	for (; it != v.end() ; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<typename C>
void vectorTest()
{
	// /*
	std::cout << "=================================" << std::endl;
	std::cout<<std::endl;
	std::cout << "--------------DEFAULT CONSTRUCTOR" << std::endl;
		C test1;											//DEFAULT
		printVec(test1);
	std::cout << "--------------FILL CONSTRUCTOR" << std::endl;					
		C test2(10);										//FILL
		printVec(test2);
	std::cout << "--------------FILL CONSTRUCTOR" << std::endl;
		C test3(10,5);										//FILL
		printVec(test3);
	std::cout << "--------------RANGE CONSTRUCTOR" << std::endl;
		C test4(10,5);									//RANGE
		C test5(test4.begin(),test4.end());
		printVec(test4);
		printVec(test5);
	std::cout << "--------------COPY CONSTRUCTOR" << std::endl;
		C test6(10,5);									//FILL
		// test.push_back(6);
		printVec(test6);
		C copy1(test6);									//COPY
		printVec(copy1);

		C empty1;
		C empty2(empty1);
		printVec(empty1);
		printVec(empty2);
	std::cout << "--------------ASSIGNMENT OPERATOR" << std::endl;
		std::cout << "--full in empty--" << std::endl;
		C test7(10,5);									//FILL
		printVec(test7);
		C test8;
		printVec(test8);
		test8 = test7;												//ASSIGNMENT OPERATOR
		printVec(test8);

		std::cout << "--empty in full--" << std::endl;
		C empty3;
		printVec(test7);
		test7 = empty3;												//ASSIGNMENT OPERATOR
		printVec(test7);
		printVec(empty3);

		std::cout << "--more in less--" << std::endl;
		C test9(10,5);
		C test10(3,4);
		printVec(test10);
		printVec(test9);
		test10 = test9;												//ASSIGNMENT OPERATOR
		printVec(test10);
		printVec(test9);
		
		std::cout << "--less in more--" << std::endl;
		C test11(10,5);
		C test12(3,4);
		printVec(test11);
		printVec(test12);
		test11 = test12;												//ASSIGNMENT OPERATOR
		printVec(test11);
		printVec(test12);
	std::cout << "--------------" << std::endl;
	{

	}
	std::cout << "=================================" << std::endl;
		C test13(10,5);
		C copy2(test13);
		C empty4;
		std::cout << "EMPTY:\t" << test13.empty() << std::endl;
		std::cout << "EMPTY:\t" << empty4.empty() << std::endl;
		std::cout << "MAX_SIZE:\t" << test13.max_size() << std::endl;
		std::cout << "SIZE:\t\t" << test13.size() << std::endl;
		std::cout << "CAPACITY:\t" << test13.capacity() << std::endl;
		test13.push_back(6);
		test13.push_back(8);
		std::cout << "SIZE:\t\t" << test13.size() << std::endl;
		std::cout << "CAPACITY:\t" << test13.capacity() << std::endl;
		std::cout << std::endl;
		std::cout << "-------TESTS RESIZE---------" << std::endl;
		printVec(test13);
		
		std::cout << "--PARAM(5)" << std::endl;
		printVec(test13);
		test13.resize(5);
		printVec(test13);
		test13 = copy2;
	
		// std::cout << "COPY: " << std::endl;
		// printVec(copy2);
		std::cout << "--PARAM(6,6)" << std::endl;
		printVec(test13);
		test13.resize(6,6);
		for (int i=0; i < 14; i++)
			test13.push_back(7);
		printVec(test13);
		test13.push_back(7);
		printVec(test13);
		for (int i=0; i < 20; i++)
			test13.pop_back();
		printVec(test13);
		test13 = copy2;

		std::cout << "--PARAM(15)" << std::endl;
		printVec(test13);
		test13.resize(15);
		printVec(test13);
		test13 = copy2;

		std::cout << "--PARAM(15,7)" << std::endl;
		printVec(test13);
		test13.resize(15, 7);
		printVec(test13);
		test13 = copy2;

		std::cout << std::endl;
		std::cout << "-------TESTS RESERVE---------" << std::endl;
		printVec(test13);
		printVec(copy2);

		test13.reserve(15);
		for (int i=0; i < 200; i++)
			test13.push_back(7);
		printVec(test13);
		test13.reserve(400);
		printVec(test13);
		for (int i=0; i < 200; i++)
			test13.pop_back();
		printVec(test13);
		test13 = copy2;
	std::cout<<std::endl;
	
	{
		C test14(10,5);
		std::cout << "--------------OPERATOR[]" << std::endl;
		std::cout << test14[1] << std::endl;
		std::cout << test14[5] << std::endl;
		std::cout << test14[9] << std::endl;
		try
		{
			std::cout << "--------------AT" << std::endl;
			std::cout << test14.at(1) << std::endl;
			std::cout << test14.at(5) << std::endl;
			for (int i=0; i < 20; i++)
				test14.push_back(i);
			std::cout << test14.at(20) << std::endl;
			std::cout << test14.at(21) << std::endl;
			std::cout << test14.at(22) << std::endl;
			std::cout << test14.at(23) << std::endl;
			std::cout << test14.at(100) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "--------------FRONT" << std::endl;
		std::cout << test14.front() << std::endl;

		std::cout << "--------------BACK" << std::endl;
		std::cout << test14.back() << std::endl;
	}
	std::cout<<std::endl;
		std::cout << "--------------PUSH_BACK e POP_BACK" << std::endl;
		
		C test15;
		test15.push_back(1);
		printVec(test15);
		test15.push_back(2);
		printVec(test15);
		test15.push_back(3);
		printVec(test15);
		for (int i = 0; i < 100; ++i)
			test15.push_back(i);
		printVec(test15);
		for (int i = 0; i < 101; ++i)
			test15.pop_back();
		printVec(test15);
	std::cout<<std::endl;

		std::cout << "--------------ASSIGN" << std::endl;

		//RANGE
		C data3;
		for (int i = 0; i < 100; ++i)
			data3.push_back(i);
		printVec(data3);
		C test16;
		test16.assign(data3.begin(), data3.end());
		printVec(test16);
		C test17(150,5);
		test17.assign(data3.begin(), data3.end());
		printVec(test17);
		C test18(150,5);
		test18.assign(data3.begin(), data3.begin() + 10);
		printVec(test18);
		//FILL
		C test19;
		test19.assign(50, 40);
		printVec(test19);
		test19.assign(20, 30);
		printVec(test19);	
		test19.assign(200, 20);
		printVec(test19);

	//	INSERT SINGLE ELEMENT
		C data4;
		for (int i = 0; i < 100; ++i)
			data4.push_back(i);
		printVec(data4);
		data4.insert(data4.begin(), 4);
		printVec(data4);
		for(int i = 0; i < 27; i++)
			data4.insert(data4.begin(), 4);
		printVec(data4);
		data4.insert(data4.begin(),1);
		printVec(data4);
		for(int i = 0; i < 500; i++)
			data4.insert(data4.begin(), 4);
		printVec(data4);
		//	INSERT FILL
		C data5;
		for (int i = 0; i < 100; ++i)
			data5.push_back(i);
		printVec(data5);
		data5.insert(data5.begin(), 5, 4);
		printVec(data5);
		data5.insert(data5.begin(), 24, 4);
		printVec(data5);

		
		data5.insert(data5.begin(), 1);
		printVec(data5);
		data5.insert(data5.begin(), 127, 2);
		printVec(data5);
		data5.insert(data5.begin(), 258, 2);
		printVec(data5);
		
	//	INSERT RANGE
		C data6;
		for (int i = 0; i < 100; ++i)
			data6.push_back(i);
		C test20;
		printVec(data6);
		printVec(test20);
		test20.insert(test20.begin(), data6.begin(), data6.end());
		printVec(test20);
		test20.insert(test20.end(), data6.begin(), data6.begin() + 1);
		printVec(test20);
		for (int i = 0; i < 200; ++i)
			data6.push_back(i);
		test20.insert(test20.begin(), data6.begin(), data6.end());
		printVec(test20);

	// ERASE
		C data7;
		data7.push_back(0);
		data7.erase(data7.begin());
		for (int i = 0; i < 100; ++i)
			data7.push_back(i);
		printVec(data7);
		for (int i = 0; i < 100; ++i)
			data7.push_back(i);
		printVec(data7);
		data7.erase(data7.begin(), data7.begin() + 3);
		printVec(data7);
		data7.erase(data7.begin(), data7.end());
		printVec(data7);
	// SWAP MEMBER
		C data8;
		for (int i = 0; i < 100; ++i)
			data8.push_back(i);
		printVec(data8);
		C test21;
		for (int i = 0; i < 200; ++i)
			test21.push_back(i);
		printVec(test21);
		
		test21.swap(data8);
		printVec(data8);
		printVec(test21);
	// CLEAR
		C data9;
		for (int i = 0; i < 100; ++i)
			data9.push_back(i);
		printVec(data9);
		data9.clear();
		printVec(data9);
	// SWAP NO MEMBER
		C data10;
		for (int i = 0; i < 100; ++i)
			data10.push_back(i);
		printVec(data10);
		C test22;
		for (int i = 0; i < 200; ++i)
			test22.push_back(i);
		printVec(test22);
		
		swap(data10,test22);
		printVec(data10);
		printVec(test22);

	//RELATIONAL OPERATOR--------------------------------------------------------------------
	C data1;
	for (size_t i = 0; i < 80; ++i)
		data1.push_back(i);
	printVec(data1);
	
	C data2(data1);
	printVec(data2);
	///////////////////////////////////////////////////
	std::cout << "==" << std::endl;
	if (data1 == data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	data2.push_back(80);
	if (data1 == data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;	
	data2.pop_back();
	if (data1 == data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl; 
	///////////////////////////////////////////////////
	std::cout << "!=" << std::endl;	
	if (data1 != data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	data2.push_back(80);
	if (data1 != data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
		
	data2.pop_back();
	if (data1 != data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl; 
	///////////////////////////////////////////////////
	std::cout << "<" << std::endl;
	if (data1 < data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
		
	data2.push_back(80);
	if (data1 < data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;	
	data2.pop_back();
	if (data1 < data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	///////////////////////////////////////////////////
	std::cout << "<=" << std::endl;
	if (data1 <= data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
		
	data2.push_back(80);
	if (data1 <= data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;	
	data2.pop_back();
	if (data1 <= data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	///////////////////////////////////////////////////
	std::cout << ">" << std::endl;
	if (data1 > data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
		
	data2.push_back(80);
	if (data1 > data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;	
	data2.pop_back();
	if (data1 > data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	///////////////////////////////////////////////////
	std::cout << ">=" << std::endl;
	if (data1 >= data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
		
	data2.push_back(80);
	if (data1 >= data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;	
	data2.pop_back();
	if (data1 >= data2)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	///////////////////////////////////////////////////
// */
	C test23;
	test23.push_back(9);
	test23.push_back(19);
	test23.push_back(29);
	test23.push_back(39);
	printVec(test23);

	std::cout << "ITERATOR" << std::endl;
	typename C::iterator itB = test23.begin();
	typename C::iterator it2B;
	it2B = itB;

	std::cout << (it2B==itB) << std::endl;
	std::cout << (it2B!=itB) << std::endl;
	std::cout << (it2B>=itB) << std::endl;
	std::cout << (it2B<=itB) << std::endl;
	std::cout << (it2B>itB) << std::endl;
	std::cout << (it2B<itB) << std::endl;
	it2B++;
	std::cout << (it2B==itB) << std::endl;
	std::cout << (it2B!=itB) << std::endl;
	std::cout << (it2B>=itB) << std::endl;
	std::cout << (it2B<=itB) << std::endl;
	std::cout << (it2B>itB) << std::endl;
	std::cout << (it2B<itB) << std::endl;
	std::cout << (it2B<=itB) << std::endl;
	std::cout << (it2B>=itB) << std::endl;
	std::cout << (it2B<itB) << std::endl;
	std::cout << (it2B>itB) << std::endl;
	

	typename C::iterator itE = test23.end()-1;
	std::cout << *itB << std::endl;
	std::cout << *it2B << std::endl;
	std::cout << *itE << std::endl;
	itB++;
	itE--;
	std::cout << *itB << std::endl;
	std::cout << *itE << std::endl;
	++itB;
	--itE;
	std::cout << *itB << std::endl;
	std::cout << *itE << std::endl;
	
	std::cout << "CONST_ITERATOR" << std::endl;
	typename C::const_iterator cItB = test23.begin();
	typename C::const_iterator cItE = test23.end()-1;
	std::cout << *cItB << std::endl;
	std::cout << *cItE << std::endl;

	std::cout << "REV_ITERATOR" << std::endl;
	typename C::reverse_iterator rItB = test23.rbegin();
	typename C::reverse_iterator rIt2B;
	typename C::reverse_iterator rIt3B(itB);
	typename C::reverse_iterator rIt4B(rIt3B);

	std::cout << (rIt3B==rIt4B) << std::endl;
	std::cout << (rIt3B!=rIt4B) << std::endl;
	std::cout << (rIt3B>=rIt4B) << std::endl;
	std::cout << (rIt3B<=rIt4B) << std::endl;
	std::cout << (rIt3B>rIt4B) << std::endl;
	std::cout << (rIt3B<rIt4B) << std::endl;
	rIt3B--;
	std::cout << *(rIt3B) << std::endl;
	std::cout << (rIt3B==rIt4B) << std::endl;
	std::cout << (rIt3B!=rIt4B) << std::endl;
	std::cout << (rIt3B>=rIt4B) << std::endl;
	std::cout << (rIt3B<=rIt4B) << std::endl;
	std::cout << (rIt3B>rIt4B) << std::endl;
	std::cout << (rIt3B<rIt4B) << std::endl;
	std::cout << (rIt3B<=rIt4B) << std::endl;
	std::cout << (rIt3B>=rIt4B) << std::endl;
	std::cout << (rIt3B<rIt4B) << std::endl;
	std::cout << (rIt3B>rIt4B) << std::endl;

	rIt2B = rItB;
	typename C::reverse_iterator rItE = test23.rend();
	std::cout << *rItB << std::endl;
	std::cout << *rIt2B << std::endl;
	rIt3B++;
	rIt4B++;
	std::cout << "\t" << *itB << std::endl;
	std::cout << "\t" << *rIt3B << std::endl;
	std::cout << "\t" << *rIt4B << std::endl;
	rItB++;
	rItE--;
	std::cout << *rItB << std::endl;
	std::cout << *rItE << std::endl;
	++rItB;
	--rItE;
	std::cout << *rItB << std::endl;
	std::cout << *rItE << std::endl;
	
	std::cout << "REV_CONST_ITERATOR" << std::endl;
	typename C::const_reverse_iterator rcItB = test23.rbegin();
	std::cout << *rcItB << std::endl;


//////////////////////ARRAY IN A VECTOR/////////////////////////
	// C test24;
	// typename C::value_type arr[] = {1,2,3,4};
	// test24.assign(arr, &arr[3]);
	// printVec(test24);

	// C test25;
	// typename C::value_type *a = new typename C::value_type;
	// *a = 5;
	// typename C::value_type *b = new typename C::value_type;
	// *b = 6;
	// (void)b;
	// typename C::value_type *c = new typename C::value_type;
	// *c = 7;
	// test25.assign(a, c);	
	// printVec(test25);

	// std::cout << std::endl;	
	// std::cout << "CHAR" << std::endl;
	// C test26;
	// char *d = new char;
	// *d = '5';
	// char *e = new char;
	// *e = '6';
	// (void)e;
	// char *f = new char;
	// *f = '7';
	// test26.assign(d, f);	
	// printVec(test26);

	// std::cout << std::endl;	
	// std::cout << "CHAR2" << std::endl;
	// C test27;
	// char g = '5';
	// char h = '6';
	// (void)h;
	// char i = '7';
	// test27.assign(&i, &g);	
	// printVec(test27);
	
	return ;
}

