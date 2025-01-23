/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:21:02 by linyao            #+#    #+#             */
/*   Updated: 2025/01/23 22:30:51 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool   _isSigned;
        int const _gradeToSign;
        int const _gradeToExe;
    public:
        Form();
        ~Form();
        Form(std::string const &name, int const gradeToSign, int const gradeToExe);
        Form(Form const &src);
        Form const &operator=(Form const &src);
        
        std::string const &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExe() const;
        void    beSigned(Bureaucrat const &b);
        
        class	GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class	GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Form const &f);
