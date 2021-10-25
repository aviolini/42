/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:17:55 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/08 09:21:41 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}


MateriaSource::MateriaSource(const MateriaSource & obj)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this != &obj)
	{
		MateriaSource::~MateriaSource();
		for (int i = 0; i < 4; i++)
			this->inventory[i] = obj.inventory[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = -1;
	while (++i < 4)
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] && !this->inventory[i]->getType().compare(type))
			return this->inventory[i]->clone();
	return 0;
}