/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:40:49 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/02 17:06:59 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
	
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const & obj);
	~FragTrap();
	FragTrap & operator=(FragTrap const &obj);

	void highFivesGuys(void);
	void attack(std::string const & target);
};

#endif
