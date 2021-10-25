/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:58:36 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/19 14:53:14 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string const &name): weapon(NULL), name(name)
{}

HumanB::~HumanB()
{}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " hasn't weapon " << std::endl;

}

void HumanB::setWeapon(Weapon &weapon_type)
{
	this->weapon = &weapon_type;
}
