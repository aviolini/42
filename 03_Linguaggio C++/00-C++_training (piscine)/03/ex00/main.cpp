/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:02:30 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/01 14:07:41 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap c1;
	ClapTrap c2("C2");
	ClapTrap c3(c2);
	ClapTrap c4;

	c4 = c1;

	c1.attack("C5");
	c2.attack("C6");
	c3.takeDamage(8);
	c4.beRepaired(9);

	return 0;
}
