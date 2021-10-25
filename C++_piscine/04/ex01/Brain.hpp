/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:36:48 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/04 00:20:30 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#define SIZE_ARR 100

class Brain
{
	public:
		Brain();
		Brain(Brain const & obj);
		~Brain();
		Brain & operator=(Brain const & obj);
		
		std::string const  & getIdea(int i) const;
		void setIdea(int i, const std::string new_idea);
	private:
		std::string *ideas;
};

#endif
