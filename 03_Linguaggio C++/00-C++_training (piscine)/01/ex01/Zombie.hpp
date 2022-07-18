/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:09:53 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/25 17:16:40 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP 
# define _ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void setname(std::string const name);
	void announce();
	
	private:
	std::string name;
};

Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );


#endif
