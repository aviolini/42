/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:50:24 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/23 09:24:20 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _KAREN_H
# define _KAREN_H

#include <iostream>


class Karen
{
	public:
	Karen();
	~Karen();

	void complain( std::string level );

	private:
	void debug (void);
	void info (void);
	void warning (void);
	void error (void);
};

#endif
