/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:08:17 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/11 10:57:04 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::toupper

int	main(int ac, char **av)
{	
	if (ac == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int c = 0;
		while (++c < ac)
		{
			std::string s(av[c]);
			unsigned int i = 0;
			while (i < s.size())
				std::cout<<(char )std::toupper(s[i++]);
		}
	}
	std::cout << std::endl;
	return (0);
}