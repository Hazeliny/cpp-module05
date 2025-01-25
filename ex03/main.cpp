/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:13:08 by linyao            #+#    #+#             */
/*   Updated: 2025/01/25 18:36:19 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
//#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern		david;
	AForm		*form;
	Bureaucrat	windy("Windy", 30);

	try
	{
		form = david.makeForm("ShrubberyCreationForm", "Mary");
		delete form;
		form = david.makeForm("RobotomyRequestForm", "Shelly");
		delete form;
		form = david.makeForm("PresidentialPardonForm", "Antoni");
		delete form;
		form = david.makeForm("OtherForm", "Lily");
		delete form;
	}
	catch (Intern::InvalidFormException &e)
	{
		std::cout << "Caught InvalidFormException: " << e.what() << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;
	form = david.makeForm("ShrubberyCreationForm", "Fred");
	form->beSigned(windy);
	windy.executeForm(*form);
	delete form;
	
	std::cout << "------------------------------------" << std::endl;
	form = david.makeForm("PresidentialPardonForm", "Georgia");
	windy.signForm(*form);
	windy.executeForm(*form);
	delete form;
	return (0);
}
