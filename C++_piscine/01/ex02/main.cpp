/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:06:15 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/18 19:03:51 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string	*s_ptr = &s;
	std::string &s_ref = s;

	std::cout << "String s:\t" << s << std::endl;
	std::cout << "Address s:\t" << &s << std::endl;
	std::cout << "Address s_ptr:\t" << s_ptr << std::endl;
	std::cout << "Address s_ref:\t" << &s_ref << std::endl;
	std::cout << "String s_ptr:\t" << *s_ptr << std::endl;
	std::cout << "String s_ref:\t" << s_ref << std::endl;
	return(0);
}
