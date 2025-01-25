/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:29:50 by linyao            #+#    #+#             */
/*   Updated: 2025/01/25 18:37:09 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;
class AForm;

class Intern
{
    public:
        Intern();
        Intern(Intern const &src);
        Intern const &operator=(Intern const &src);
        ~Intern();
        AForm *makeForm(std::string const &name, std::string const &target);
        class InvalidFormException : public std::exception
        {
            public:
                virtual char const *what() const throw();
        };
};
