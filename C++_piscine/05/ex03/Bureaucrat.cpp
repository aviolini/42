/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:11:40 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/10 08:26:18 by arrigo           ###   ########.fr       */
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
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	std::cout << this->getName() << " increment grade!" << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	std::cout << this->getName() << " decrement grade!" << std::endl;
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

void Bureaucrat::signForm(Form & obj) const
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

void Bureaucrat::execForm(Form & obj) const
{
	try
	{
		obj.execute(*this);
		std::cout << this->getName() << " executes " << obj.getTarget() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName();
		std::cerr << " cannot executes " << obj.getTarget();
		std::cerr << " because: ";
		std::cerr << e.what() << '\n';
	}
}

std::ostream & operator<<(std::ostream &o,Bureaucrat const & obj)
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return o;
}