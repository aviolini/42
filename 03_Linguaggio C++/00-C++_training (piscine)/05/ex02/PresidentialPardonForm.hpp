/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 00:34:26 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/10 07:56:24 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & obj);
		PresidentialPardonForm & operator = (PresidentialPardonForm const & obj);
		virtual ~PresidentialPardonForm();
		virtual std::string const & getTarget()const;
		virtual void execute(Bureaucrat const & executor) const;

	private:
		std::string target;
};

std::ostream & operator << (std::ostream & o, PresidentialPardonForm const & obj);

#endif
