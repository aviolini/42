/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:09:41 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/25 17:16:45 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string const name )
{
	Zombie *zombieHordeTemp;

	(void)name;
	zombieHordeTemp = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombieHordeTemp[i].setname(name);

	return zombieHordeTemp;
}
