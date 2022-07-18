/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:09:26 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/09 00:25:00 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & obj);
		Bureaucrat & operator=(Bureaucrat const & obj);
		~Bureaucrat();

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
		void myexc(int grade);
		std::string const & getName() const;
		int const & getGrade() const;
		void incrementGrade();
		void decrementGrade();

	private:
		std::string name;
		int grade;
};

std::ostream & operator<<(std::ostream &o,Bureaucrat const & obj);

#endif