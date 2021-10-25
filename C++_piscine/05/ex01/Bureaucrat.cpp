/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:11:40 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/09 16:51:30 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("DefaultName"),grade(150)
{}

Bureaucrat::Bureaucrat(std::string name):name(name),grade(150)
{}

Bureaucrat::Bureaucrat(int grade):name("DefaultName")
{
	Bureaucrat::myexc(grade);	
}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name)
{
	Bureaucrat::myexc(grade);	
}

Bureaucrat::Bureaucrat(const Bureaucrat & obj)
{
	*this = obj;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & obj)
{
	this->name = obj.getName();
	this->grade = obj.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string const & Bureaucrat::getName() const
{
	return this->name;
}

int const & Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	std::cout << "..increment.." <<std::endl;
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	std::cout << "..decrement.." <<std::endl;
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

void Bureaucrat::myexc(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

void Bureaucrat::signForm(Form & obj)
{
	try
	{
		obj.setSign(*this);
		std::cout << this->getName();
		std::cout << " signs " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName();
		std::cerr << " cannot signs " << obj.getName();
		std::cerr << " because: ";
		std::cerr << e.what() << std::endl;
	}
}

std::ostream & operator<<(std::ostream &o,Bureaucrat const & obj)
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return o;
}