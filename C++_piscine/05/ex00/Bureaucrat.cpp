/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:11:40 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/09 00:26:06 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("DefaultName"),grade(150)
{
	std::cout << "DEFAULT CONSTRUCTOR SUCCESS" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name):name(name),grade(150)
{
	std::cout << "CONSTRUCTOR SUCCESS" << std::endl;
}

Bureaucrat::Bureaucrat(int grade):name("DefaultName")
{
	Bureaucrat::myexc(grade);	
	std::cout << "CONSTRUCTOR SUCCESS" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name)
{
	Bureaucrat::myexc(grade);	
	std::cout << "CONSTRUCTOR SUCCESS" << std::endl;
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

std::ostream & operator<<(std::ostream &o,Bureaucrat const & obj)
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return o;
}