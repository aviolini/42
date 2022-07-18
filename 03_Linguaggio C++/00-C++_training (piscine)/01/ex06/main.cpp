/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:06:15 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/24 13:11:56 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int ac, char **av)
{	
	Karen karen;
	
	if (ac == 1)
	{
		std::cout << "Insert a log level: \"DEBUG\" , \"INFO\", \"WARNING\", \"ERROR\" " << std::endl;
		return 1;
	}
	karen.complain(av[1]);
	return(0);
}
