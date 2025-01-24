/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:01:50 by linyao            #+#    #+#             */
/*   Updated: 2025/01/23 22:48:27 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExe(150)
{
    std::cout << "Form default constructor called." << std::endl;
}
        
AForm::~AForm()
{
    std::cout << "Form deconstructor called." << std::endl;
}
        
AForm::AForm(std::string const &name, int const gradeToSign, int const gradeToExe) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
    std::cout << "Form assignment constructor of " << this->getName() << " called." << std::endl;
    if (this->getGradeToSign() < 1)
        throw(AForm::GradeTooHighException());
    else if (this->getGradeToExe() < 1)
        throw(AForm::GradeTooHighException());
    else if (this->getGradeToSign() > 150)
        throw(AForm::GradeTooLowException());
    else if (this->getGradeToExe() > 150)
        throw(AForm::GradeTooLowException());
}
        
AForm::AForm(AForm const &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExe(src._gradeToExe)
{
    *this = src;
    std::cout << "Form copy constructor called from " << src.getName() << " to " << this->getName() << std::endl;
}
        
AForm const &AForm::operator=(AForm const &src)
{
    this->_isSigned = src._isSigned;
    return (*this);
}
        
std::string const &AForm::getName() const
{
    return (this->_name);
}
        
bool AForm::getIsSigned() const
{
    return (this->_isSigned);
}
        
int AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}
        
int AForm::getGradeToExe() const
{
    return (this->_gradeToExe);
}
        
void    AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > 1 && b.getGrade() <= this->getGradeToSign())
    {
        this->_isSigned = true;
        std::cout << b.getName() << " signed " << this->getName() << " successfully." << std::endl;
    }
    else
        throw (AForm::GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}   

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
    os << "AForm: " << f.getName() << " | signedStatus: " << f.getIsSigned() 
        << " | GradeToSign: " << f.getGradeToSign() << " | GradeToExe: " << f.getGradeToExe() << std::endl;
    return (os);
}
