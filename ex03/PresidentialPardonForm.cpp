/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:03:59 by linyao            #+#    #+#             */
/*   Updated: 2025/01/25 21:32:30 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", 25, 5), _target("null")
{}
        
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm assignment constructor called." << std::endl;
    std::cout << *this << std::endl;
}
        
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm::AForm(src), _target(src._target)
{
    *this = src;
}

PresidentialPardonForm const &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    AForm::operator=(src);
    this->_target = src._target;
    return (*this);     
}
        
PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string const &PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}
        
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExe())
        throw (Bureaucrat::GradeTooLowException());
    else if (!this->getIsSigned())
        throw (AForm::GradeNotSignedException());
    else
    {
        std::cout << this->getTarget() << " has been pardoned by  Zaphod Beeblebrox" << std::endl;
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &f)
{
    os << "PresidentialPardonForm name: " << f.getName() << " | isSigned: " << f.getIsSigned()
        << " | gradeToSign: " << f.getGradeToSign() << " | gradeToExe:" << f.getGradeToExe()
        << " | target: " << f.getTarget() << std::endl;
    return (os);
}
