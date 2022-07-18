/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:11:21 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/02 17:06:43 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
	
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const & obj);
	~DiamondTrap();
	DiamondTrap &operator=(DiamondTrap const &obj);
	
	void attack(std::string const & target);
	void whoAmI();

	private:
	
	std::string name;
};

#endif
