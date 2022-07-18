/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:25:44 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/16 23:57:51 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#define SIZE_ARR 5

void print_c(char const & c)
{
	std::cout << "printing char:\t" << c << std::endl;
}

void print_i(int const & i)
{
	std::cout << "printing int:\t" << i << std::endl;
}

void print_f(float const & f)
{
	std::cout << "printing float:\t" << f << std::endl;
}

int main(void)
{
	char * arr_c = createArray('a', SIZE_ARR);
	iter(arr_c, SIZE_ARR, print_c);
	std::cout << std::endl;
	
	int * arr_i = createArray(0, SIZE_ARR);
	iter(arr_i, SIZE_ARR, print_i);
	std::cout << std::endl;
	
	float * arr_f = createArray(0.5f, SIZE_ARR);
	iter(arr_f, SIZE_ARR, print_f);
	std::cout << std::endl;
	
	std::cout << "--------" << std::endl;
	
	iter(arr_c, SIZE_ARR, print);
	std::cout << std::endl;
	iter(arr_i, SIZE_ARR, print);
	std::cout << std::endl;
	iter(arr_f, SIZE_ARR, print);
	
	delete arr_c;
	delete arr_i;
	delete arr_f;
	return 0;
}

