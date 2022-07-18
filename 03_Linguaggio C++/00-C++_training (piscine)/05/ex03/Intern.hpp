/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 08:35:46 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/10 17:46:30 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const & obj);
		Intern & operator=(Intern const & obj);
		~Intern();
		Form * makeForm (std::string const & nameForm, std::string const & targetForm) const;
		Form * CreateShrubberyCreationForm(std::string const & targetForm) const;
		Form * CreateRobotomyRequestForm(std::string const & targetForm) const;
		Form * CreatePresidentialPardonForm(std::string const & targetForm) const;
		
		class FormNotKnow : public std::exception
		{
			public:
				FormNotKnow(){}
				virtual ~FormNotKnow() throw(){}
				virtual const char* what() const throw();
		};
};

#endif