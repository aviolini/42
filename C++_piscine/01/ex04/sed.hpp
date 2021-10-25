/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:47:09 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/20 17:30:17 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SED_H
# define _SED_H

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>  

class Sed
{
	public:
	Sed();
	~Sed();	

	void replace(std::string const filename, std::string const search, std::string const replace);

};

#endif
