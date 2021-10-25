/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:58:48 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/19 14:38:43 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANB_H
# define _HUMANB_H

#include <iostream>
#include "Weapon.hpp"


class HumanB
{
	public:
	HumanB(std::string const &name);
	~HumanB();

	void attack();
	void setWeapon(Weapon &weapon_type);

	private:
	Weapon *weapon;
	std::string name;
};

#endif
