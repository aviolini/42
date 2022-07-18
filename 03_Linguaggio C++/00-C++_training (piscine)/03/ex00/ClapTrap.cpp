/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:02:43 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/02 17:04:33 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("Default name"),hit_points(10),energy_points(10),attack_damage(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name):name(name),hit_points(10),energy_points(10),attack_damage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->name = obj.name;
	return *this;
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->name <<  " attack " << target;
	std::cout << ",causing " << this->attack_damage << " points of damage!";
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name <<  " take " << amount;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name <<  " is repaired " << amount;
	std::cout << " points!" << std::endl;
}

void ClapTrap::get_info()
{
	std::cout << this->name << std::endl;
	std::cout << this->hit_points << std::endl;
	std::cout << this->energy_points << std::endl;
	std::cout << this->attack_damage << std::endl;
}

