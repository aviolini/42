/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:54:19 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/10 07:57:02 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int gts, const int gte);
		Form (Form const & obj);
		Form & operator=(Form const & obj);
		virtual ~Form();
		
		void beSigned(Bureaucrat const & obj) const;
		void beExecuted(Bureaucrat const & obj) const;
		std::string const & getName() const;
		bool const & getSign() const;
		void setSign(Bureaucrat const & obj);
		int const & getGradeToSign() const;
		int const & getGradeToExec() const;
		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual std::string const & getTarget()const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(){}
				virtual ~GradeTooHighException() throw(){}
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(){}
				virtual ~GradeTooLowException() throw(){}
				virtual const char* what() const throw();
		};
		class MyCustomException : public std::exception
		{
		public:
			MyCustomException(std::string err_string):err_string(err_string){}
			virtual ~MyCustomException() throw(){}
			virtual const char* what() const throw();
		private:
			std::string err_string;
		};
	
	private:
		const std::string name;
		bool sign;
		const int grade_to_sign;
		const int grade_to_exec;
};

std::ostream & operator<<(std::ostream &o, Form const & obj);

#endif