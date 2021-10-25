/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:06:15 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/24 15:19:00 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombie("BraiiiiiiinnnzzzZ...");
	zombie.announce();
	
	Zombie *newZombieTemp = newZombie("newZombie1");
	delete(newZombieTemp);

	randomChump("newZombie2");

	return(0);
}
