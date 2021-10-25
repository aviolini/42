/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:54:15 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/08 09:25:03 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete inventory[i];
}

Character::Character(std::string const name):name(name)
{}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	int i = -1;
	while (++i < 4)
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
}

void Character::unequip(int idx)
{
		this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter & target)
{
	this->inventory[idx]->use(target);
}