/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:58:33 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/02 16:01:31 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap():ClapTrap("FragTrapDefautlName")
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const name):ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & obj)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	return *this;
}

void FragTrap::attack(std::string const & target)
{
	std::cout << "FragTrap " << this->name <<  " attack " << target;
	std::cout << " ,causing " << this->attack_damage << " points of damage!";
	std::cout << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap request positive highFivesGuys!" << std::endl;
}
