/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:20:27 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/10 07:56:33 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & obj);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & obj);
		virtual ~RobotomyRequestForm();
		virtual std::string const & getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;

	private:
		std::string target;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & obj);

#endif
