/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 08:07:55 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/10 08:22:51 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target + "_shrubbery")
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & obj) : target(obj.target)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & obj)
{
	Form::operator = (obj);
	this->target = obj.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string const & ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw MyCustomException("Form not signed");
	this->beExecuted(executor);
	std::ofstream ofs;
	ofs.open(this->target.c_str(),std::ios_base::out | std::ios_base::trunc);// | std::ios_base::binary);
	std::ifstream ifs;
	ifs.open("ascii_tree",std::ios_base::in);// | std::ios_base::binary);
	if (!ofs.is_open() || !ifs.is_open())
		throw MyCustomException("Error open file");
	ofs << ifs.rdbuf();
	ofs.close();
	ifs.close();
}

std::ostream & operator<<(std::ostream &o, ShrubberyCreationForm const & obj)
{
	o << (const Form &)obj;
	o << "target:\t\t" << obj.getTarget() << std::endl;
	return o;
}
