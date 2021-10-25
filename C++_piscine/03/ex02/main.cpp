/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:02:30 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/02 16:03:01 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

int main()
{
	FragTrap f("fragtrap");
	FragTrap f0(f);
	FragTrap f1;
	ScavTrap s("scavtrap");
	ClapTrap c("claptrap");
	
	f1.attack("claptrap");
	f0.attack("claptrap");
	f.attack("claptrap");
	s.attack("claptrap");
	c.attack("fragtrap");

	f.highFivesGuys();
	s.guardGate();
	return 0;
}

