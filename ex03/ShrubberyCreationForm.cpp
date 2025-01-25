/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:02:56 by linyao            #+#    #+#             */
/*   Updated: 2025/01/25 21:31:52 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null")
{}
        
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm assignment constructor called." << std::endl;
    std::cout << *this << std::endl;
}
        
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm::AForm(src), _target(src._target)
{
    *this = src;
}
        
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    AForm::operator=(src);
    this->_target = src._target;
    return (*this);
}
        
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
        
std::string const &ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}
        
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExe())
        throw (Bureaucrat::GradeTooLowException());
    else if (!this->getIsSigned())
        throw (AForm::GradeNotSignedException());
    else
    {
        std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());
        if (!ofs)
            throw (std::runtime_error("Failed to create file."));
        ofs << "         /\\        " << std::endl;
        ofs << "        /\\*\\       " << std::endl;
        ofs << "       /\\O\\*\\      " << std::endl;
        ofs << "      /*/\\/\\/\\     " << std::endl;
        ofs << "     /\\O\\/\\*\\/\\    " << std::endl;
        ofs << "    /\\*\\/\\*\\/\\/\\   " << std::endl;
        ofs << "   /\\O\\/\\/*/\\/O/\\  " << std::endl;
        ofs << "         ||         " << std::endl;
        ofs << "         ||         " << std::endl;
        
        ofs.close();
        std::cout << "File " << this->getTarget() << "_shrubbery created with ASCII tree successfully." << std::endl;
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &f)
{
    os << "ShrubberyCreationForm name: " << f.getName() << " | isSigned: " << f.getIsSigned()
        << " | gradeToSign: " << f.getGradeToSign() << " | gradeToExe:" << f.getGradeToExe()
        << " | target: " << f.getTarget() << std::endl;
    return (os);
}
