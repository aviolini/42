/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:54:00 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/09 16:52:29 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("DefaultForm"), sign(false), grade_to_sign(50), grade_to_exec(1)
{
	std::cout << "DEFAULT CONSTRUCTOR SUCCESS" << std::endl;
}

Form::Form(const std::string name, const int gts, const int gte)
	:name(name), sign(false), grade_to_sign(gts), grade_to_exec(gte)
{
	if (gts < 1 || gte < 1)
		throw Form::GradeTooHighException();
	if (gts > 150 || gte > 150)
		throw Form::GradeTooLowException();
	std::cout << "CONSTRUCTOR SUCCESS" << std::endl;
}

Form::Form(Form const & obj)
	:name(obj.name), sign(obj.sign), grade_to_sign(obj.grade_to_sign), grade_to_exec(obj.grade_to_exec)
{
	std::cout << "COPY CONSTRUCTOR SUCCESS" << std::endl;
}

Form & Form::operator=(Form const & obj)
{
	this->sign = obj.getSign();
	return *this;
}

Form::~Form()
{}

std::string const & Form::getName() const
{
	return name;
}

bool const & Form::getSign() const
{
	return sign;
}

void Form::setSign(Bureaucrat const & obj)
{
	this->beSigned(obj);
	this->sign = true;
}

int const & Form::getGradeToSign() const
{
	return grade_to_sign;
}

int const & Form::getGradeToExec() const
{
	return grade_to_exec; 
}

void Form::beSigned(Bureaucrat const & obj)
{
	if (obj.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream & operator<<(std::ostream &o,Form const & obj)
{
	o << "Form name:\t" << obj.getName() << std::endl;
	o << "is signed:\t" << obj.getSign() << std::endl; 
	o << "gradeToSign:\t" << obj.getGradeToSign() << std::endl; 
	o << "gradeToExec:\t" << obj.getGradeToExec() << std::endl;
	return o;
}
