/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:02:30 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/02 17:02:33 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <string>

int main()
{
	DiamondTrap diamond("diamond");
	DiamondTrap diamond1;

	diamond.attack("diamond1");
	diamond.beRepaired(10);
	diamond1.guardGate();
	diamond1.highFivesGuys();
	diamond.whoAmI();
	diamond1.whoAmI();
	return (0);
}
