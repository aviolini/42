/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 07:59:00 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/10 07:56:40 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form 
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & obj);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & obj);
		virtual ~ShrubberyCreationForm();
		virtual std::string const & getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;

	private:
		std::string target;
}; 

std::ostream & operator<<(std::ostream &o,ShrubberyCreationForm const & obj);

#endif
