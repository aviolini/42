/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:47:51 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/15 10:20:48 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error arguments" << std::endl;
		return 1;
	}
	
	Converter::convertAll(av[1]);

	return 0;
}

