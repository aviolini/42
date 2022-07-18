/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:02:21 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/18 09:25:50 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main()
{
	int			i = 1;
	Phonebook	phonebook;
	std::string	s;

	while (!std::cin.eof())
	{
		if (i == 9)
			i = 1;
		std::cout << "Type 'ADD' or 'SEARCH' or 'EXIT'" << std::endl;
		std::cin >> s;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (s.compare("ADD") == 0)
		{
			std::cout << "Add contact num: " << i << std::endl;
			phonebook.add(i);
			i++;
		}
		else if (s.compare("SEARCH") == 0)
			phonebook.search();
		else if (s.compare("EXIT") == 0)
			break ;
	}
	return (0);
}
