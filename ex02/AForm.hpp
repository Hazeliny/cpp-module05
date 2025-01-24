/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:21:02 by linyao            #+#    #+#             */
/*   Updated: 2025/01/24 22:10:12 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool   _isSigned;
        int const _gradeToSign;
        int const _gradeToExe;
    public:
        AForm();
        virtual ~AForm();
        AForm(std::string const &name, int const gradeToSign, int const gradeToExe);
        AForm(AForm const &src);
        AForm const &operator=(AForm const &src);
        
        std::string const &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExe() const;
        void    beSigned(Bureaucrat const &b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        
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
        class	GradeNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, AForm const &f);
