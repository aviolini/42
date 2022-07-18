/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:00:36 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/19 14:39:45 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_H
# define _WEAPON_H

#include <iostream>

class Weapon
{
	public:
	
	Weapon();
	Weapon(std::string const &type);
	~Weapon();

	void	setType(std::string const &type);
	std::string const	getType() const;

	private:
	std::string type;
};

#endif