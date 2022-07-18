/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:06:15 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/20 17:38:35 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error arguments" << std::endl;
		std::cout << "<namefile> <dest> <source>" << std::endl;
		return(1);
	}
	Sed sed;
	try
	{	
		sed.replace(av[1], av[2], av[3]);
	}
	catch(char const *error)
	{
		std::cout << error << std::endl;	
	}
  	catch (const std::ofstream::failure& e)
  	{
  		std::cout << "Error output file: " << e.what() << '\n';
  	}
	return(0);
}