/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:12:04 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/13 17:39:21 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		std::cout << "--------------------" << std::endl;
		Bureaucrat b("BUREAUCRAT_1", 138);
		std::cout << b << std::endl;
		ShrubberyCreationForm c("/tmp/");
		std::cout << c << std::endl;
		b.execForm(c);
		b.signForm(c);
		std::cout << c << std::endl;
		b.execForm(c);
		b.incrementGrade();
		b.execForm(c);
		
		std::cin.get();
		std::cout << "--------------------" << std::endl;
		Bureaucrat d("BUREAUCRAT_2", 45);
		std::cout << d << std::endl;
		RobotomyRequestForm e("BENDER");
		std::cout << e << std::endl;
		d.execForm(e);
		d.signForm(e);
		std::cout << e << std::endl;
		d.execForm(e);
		
		std::cin.get();
		std::cout << "--------------------" << std::endl;
		Bureaucrat f("BUREAUCRAT_3", 5);
		std::cout << f << std::endl;
		PresidentialPardonForm g("FRY");
		std::cout << g << std::endl;
		f.execForm(g);
		f.signForm(g);
		std::cout << g << std::endl;
		f.execForm(g);
		
		std::cout << "--------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return 0;
}
