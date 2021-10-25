/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:36:34 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/25 18:54:51 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & obj) : Form(obj), target(obj.target)
{}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & obj)
{
	Form::operator = (obj);
	this->target = obj.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::string const & RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::execute (const Bureaucrat & executor) const
{
	if (!this->getSign())
		throw MyCustomException("Form not signed");
	this->beExecuted(executor);
	std::cout << "TRRR TRRR TRRR TRRR" << std::endl;
	srand(time(NULL));
	if (std::rand() % 2 == 1)
		std::cout << this->target << " has been robotomized successfully 50% of the time." << std::endl;
	else
		std::cout << this->target << " robotimization failure." << std::endl;
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & obj)
{
	o << (const Form &)obj;
	o << "target:\t\t" << obj.getTarget() << std::endl;
	return o;
}
