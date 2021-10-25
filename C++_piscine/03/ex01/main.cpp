/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:02:30 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/01 16:58:07 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

int main()
{
	ScavTrap s0;
	ClapTrap c0;
	ScavTrap s("scavtrap");
	ClapTrap c("claptrap");
	
	s0.attack("claptrap");
	s.attack("claptrap");
	c0.attack("claptrap");
	c.attack("scavtrap");

	s0.guardGate();
	s.guardGate();

	return 0;
}

