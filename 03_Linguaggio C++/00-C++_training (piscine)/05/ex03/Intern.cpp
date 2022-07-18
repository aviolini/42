/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 08:38:12 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/10 17:46:16 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const & obj)
{
	*this = obj;
}

Intern & Intern::operator=(Intern const & obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern()
{}

const char * Intern::FormNotKnow::what() const throw()
{
	return ("Requested form is not known");
}

Form * Intern::CreateShrubberyCreationForm(std::string const & targetForm) const
{
	return new ShrubberyCreationForm(targetForm);
}

Form * Intern::CreateRobotomyRequestForm(std::string const & targetForm) const
{
	return new RobotomyRequestForm(targetForm);
}

Form * Intern::CreatePresidentialPardonForm(std::string const & targetForm) const
{
	return new PresidentialPardonForm(targetForm);
}

Form * Intern::makeForm(std::string const & nameForm, std::string const & targetForm) const
{
	Form * ret;
	std::string arr[6] =	{"shrubberycreationform", "robotomyrequestform", "presidentialpardonform", \
		"shrubberycreation", "robotomyrequest", "presidentialpardon"};
	Form *(Intern:: *methods_arr[3])(std::string const & targetForm) const = \
	{&Intern::CreateShrubberyCreationForm,	&Intern::CreateRobotomyRequestForm,	&Intern::CreatePresidentialPardonForm};
	std::string name;
	name = nameForm;
	for (std::string::iterator i = name.begin(); i != name.end(); i++)
	{
		*i = std::tolower(*i);
		if (std::isspace(*i))
			name.erase(i--);
	}
	try
	{
		for (int i = 0; i < 6; i++)
			if (arr[i].compare(name) == 0)
			{
				ret = (this->*methods_arr[i % 3])(targetForm);
				std::cout << "Intern creates:" << std::endl;
				std::cout << *ret << std::endl;
				return ret;
			}
		throw FormNotKnow();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return NULL;
}
