/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:38:55 by linyao            #+#    #+#             */
/*   Updated: 2025/01/25 21:20:47 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called." << std::endl;
}
        
Intern::Intern(Intern const &src)
{
    *this = src;
}
        
Intern const &Intern::operator=(Intern const &src)
{
    (void)src;
    return (*this);
}
        
Intern::~Intern()
{
    std::cout << "Intern deconstructor called." << std::endl;
}

static AForm *makeShrubbery(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *makeRobot(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makePresident(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}
        
AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    AForm *(*makeForms[])(std::string const &target) = {&makeShrubbery, &makeRobot, &makePresident};
    std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            std::cout << "Intern creates " << forms[i] << std::endl;
            return (makeForms[i](target));
        }
    }
    throw (Intern::InvalidFormException());
    return (NULL);
}

char const *Intern::InvalidFormException::what() const throw()
{
    return ("Invalid Form Request");
}
