/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:12:04 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/10 16:46:52 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void createForm(std::string nameForm, std::string targetForm)
{
	Intern i;
	std::cout << "------------" << std::endl;
	Form *f = i.makeForm(nameForm, targetForm);
	delete f;
}

int main()
{
	createForm("ShrubberyCreationForm", "SHRUBBERY");
	createForm("RobotomyRequestForm", "ROBOTMY");
	createForm("PresidentialPardonForm", "PRESIDENTIAL");

	createForm("ShrubberyCreation", "SHRUBBERY");
	createForm("RobotomyRequest", "ROBOTMY");
	createForm("PresidentialPardon", "PRESIDENTIAL");
	
	createForm("Shrubbery Creation", "SHRUBBERY");
	createForm("robotomyrequestform", "ROBOTMY");
	createForm("presidential pardon", "PRESIDENTIAL");
	
	createForm("ShrubberyCreationFor", "SHRUBBERY_ERROR");
	createForm("RobotomyRequestFor", "ROBOTMY_ERROR");
	createForm("PresidentialPardonFor", "PRESIDENTIAL_ERROR");
return 0;
}
