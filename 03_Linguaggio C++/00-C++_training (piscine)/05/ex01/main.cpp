/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:43:41 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/09 00:18:04 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "-------------" << std::endl;
	{
		try
		{
			Form b;
			std::cout << b << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl;
	{
		try
		{
			Form b("ERROR_FORM", 160, 1);
			std::cout << b << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl;
	{
		try
		{
			Form b("ERROR_FORM", 50, 0);
			std::cout << b << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl;
	{
		try
		{
			Form b("FORM_1", 50, 1);
			std::cout << b << std::endl;
			Form c("FORM_2", 50, 1);
			std::cout << c << std::endl;
			Bureaucrat d("BUREAUCRAT",49);
			Bureaucrat e("BUREAUCRAT",51);
			d.signForm(b);
			std::cout << d << std::endl;
			std::cout << b << std::endl;
			e.signForm(c);
			std::cout << e << std::endl;
			std::cout << c << std::endl;
			e.incrementGrade();
			e.signForm(c);
			std::cout << e << std::endl;
			std::cout << c << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl;
	return 0;
}