/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:06:15 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/18 17:56:53 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define SIZE 5 

int main()
{
	Zombie *zombie_arr = zombieHorde(SIZE, "Zombie");

	for (int i = 0; i < SIZE; i++)
		zombie_arr[i].announce();
	delete[] zombie_arr;

	return(0);
}

