/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:57:48 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/19 14:47:33 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANA_H
# define _HUMANA_H

#include <iostream>
#include "Weapon.hpp"


class HumanA
{
	private:
	Weapon &weapon;
	std::string name;
	
	public:
	HumanA(std::string const &name, Weapon &weapon_type);
	~HumanA();

	void attack();
};

#endif
