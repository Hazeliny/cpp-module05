/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:01:50 by linyao            #+#    #+#             */
/*   Updated: 2025/01/23 22:48:27 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExe(150)
{
    std::cout << "Form default constructor called." << std::endl;
}
        
Form::~Form()
{
    std::cout << "Form deconstructor called." << std::endl;
}
        
Form::Form(std::string const &name, int const gradeToSign, int const gradeToExe) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
    std::cout << "Form assignment constructor of " << this->getName() << " called." << std::endl;
    if (this->getGradeToSign() < 1)
        throw(Form::GradeTooHighException());
    else if (this->getGradeToExe() < 1)
        throw(Form::GradeTooHighException());
    else if (this->getGradeToSign() > 150)
        throw(Form::GradeTooLowException());
    else if (this->getGradeToExe() > 150)
        throw(Form::GradeTooLowException());
}
        
Form::Form(Form const &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExe(src._gradeToExe)
{
    *this = src;
    std::cout << "Form copy constructor called from " << src.getName() << " to " << this->getName() << std::endl;
}
        
Form const &Form::operator=(Form const &src)
{
    this->_isSigned = src._isSigned;
    return (*this);
}
        
std::string const &Form::getName() const
{
    return (this->_name);
}
        
bool Form::getIsSigned() const
{
    return (this->_isSigned);
}
        
int Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}
        
int Form::getGradeToExe() const
{
    return (this->_gradeToExe);
}
        
void    Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > 1 && b.getGrade() <= this->getGradeToSign())
    {
        this->_isSigned = true;
        std::cout << b.getName() << " signed " << this->getName() << " successfully." << std::endl;
    }
    else
        throw (Form::GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}   

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, Form const &f)
{
    os << "Form: " << f.getName() << " | signedStatus: " << f.getIsSigned() 
        << " | GradeToSign: " << f.getGradeToSign() << " | GradeToExe: " << f.getGradeToExe() << std::endl;
    return (os);
}
