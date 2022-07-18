/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:04:23 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/03 02:04:26 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal(WrongAnimal const & obj);
		virtual ~WrongAnimal();
		WrongAnimal & operator=(WrongAnimal const & obj);
		void makeSound() const;
		std::string const & getType() const;
	protected:
		std::string type;
};

#endif
