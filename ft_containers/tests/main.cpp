/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:13:14 by arrigo            #+#    #+#             */
/*   Updated: 2021/11/17 16:24:41 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#if STD
#include <vector>
#include <stack>
#include <map>
namespace ft = std;
#else
#include "../vector.hpp"
#include "../stack.hpp"
#include "../map.hpp"
#endif

#include "vectorTests.cpp"
#include "stackTests.cpp"
#include "mapTests.cpp"


int main(int argc, char** argv) {

	(void)argc;
	(void)argv;
	
	// vectorTest< ft::vector<int> >();
	// stackTest< ft::stack<int, ft::vector<int> > > ();
	// Form *(Intern:: *methods_arr[3])(std::string const & targetForm) const = {&Intern::CreateShrubberyCreationForm,	&Intern::CreateRobotomyRequestForm,	&Intern::CreatePresidentialPardonForm};
	std::pair<const char, int> (*ptr)(const char, int) = &std::make_pair<const char, int>;
	// std::cout << ptr('a',1).first << std::endl;
	mapTest< ft::map<char,int, std::less<char>, std::allocator<std::pair <const char, int > > >, std::pair<const char, int> >(ptr);   ///NON SI PUO' METTERE FT


	return (0);
}