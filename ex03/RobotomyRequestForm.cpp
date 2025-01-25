/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:03:29 by linyao            #+#    #+#             */
/*   Updated: 2025/01/25 21:32:03 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45), _target("null")
{}
        
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm assignment constructor called." << std::endl;
    std::cout << *this << std::endl;
}
        
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm::AForm(src), _target(src._target)
{
    *this = src;
}
        
RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    AForm::operator=(src);
    this->_target = src._target;
    return (*this);
}
        
RobotomyRequestForm::~RobotomyRequestForm()
{}
        
std::string const &RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}
        
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExe())
        throw (Bureaucrat::GradeTooLowException());
    else if (!this->getIsSigned())
        throw (AForm::GradeNotSignedException());
    else
    {
        srand((unsigned) time(NULL));
        int robotomized = rand() % 2;
        if (robotomized)
            std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->getTarget() << " has failed to be robotomized" << std::endl;
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &f)
{
    os << "RobotomyRequestForm name: " << f.getName() << " | isSigned: " << f.getIsSigned()
        << " | gradeToSign: " << f.getGradeToSign() << " | gradeToExe:" << f.getGradeToExe()
        << " | target: " << f.getTarget() << std::endl;
    return (os);
}
