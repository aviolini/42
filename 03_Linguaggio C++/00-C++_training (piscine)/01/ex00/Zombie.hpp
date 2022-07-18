/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:09:53 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/18 17:15:03 by arrigo           ###   ########.fr       */
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

	void announce();
	
	private:
	std::string name;
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif
