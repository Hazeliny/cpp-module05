/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:13:08 by linyao            #+#    #+#             */
/*   Updated: 2025/01/25 00:02:33 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
//#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("robot");
	PresidentialPardonForm pardon("bigPotato");
	Bureaucrat sara("Sara", 150);
	Bureaucrat jane("Jane", 139);
	Bureaucrat anne("Anne", 3);
	
	{
		try
		{
			std::cout << sara << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			sara.executeForm(shrubbery);
			sara.executeForm(robotomy);
			sara.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	{
		try
		{
			std::cout << sara << std::endl;
			std::cout << jane << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			shrubbery.beSigned(jane);
            jane.executeForm(shrubbery);
			sara.executeForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	{
		try
		{
            std::cout << anne << std::endl;
			robotomy.beSigned(anne);
			pardon.beSigned(anne);
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			
			std::cout << "\n --------------------- \n\n";
			anne.executeForm(shrubbery);
			std::cout << "\n --------------------- \n\n";
			anne.executeForm(robotomy);
			std::cout << "\n --------------------- \n\n";
			anne.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";

	return (0);
}
