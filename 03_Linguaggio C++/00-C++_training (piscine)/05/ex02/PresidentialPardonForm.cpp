/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 00:43:29 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/10 08:12:43 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & obj) : Form(obj), target(obj.target)
{}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & obj)
{
	Form::operator=(obj);
	this->target = obj.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string const & PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw MyCustomException("Form not signed");
	this->beExecuted(executor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & obj)
{
	o << (const Form &)obj;
	o << "target:\t\t" << obj.getTarget() << std::endl;
	return o;
}
