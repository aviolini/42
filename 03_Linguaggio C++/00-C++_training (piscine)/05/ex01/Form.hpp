/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:54:19 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/09 16:51:00 by arrigo           ###   ########.fr       */
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
		~Form();
		
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
		void beSigned(Bureaucrat const & obj);
		std::string const & getName() const;
		bool const & getSign() const;
		void setSign(Bureaucrat const & obj);
		int const & getGradeToSign() const;
		int const & getGradeToExec() const;

	private:
		const std::string name;
		bool sign;
		const int grade_to_sign;
		const int grade_to_exec;
};

std::ostream & operator<<(std::ostream &o, Form const & obj);

#endif