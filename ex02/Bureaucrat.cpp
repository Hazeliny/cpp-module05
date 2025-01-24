/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:40:00 by linyao            #+#    #+#             */
/*   Updated: 2025/01/23 23:00:51 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Default constructor of Bureaucrat called." << std::endl;
}
		
Bureaucrat::~Bureaucrat()
{
	std::cout << "Deconstructor of Bureaucrat called." << std::endl;
}
		
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	std::cout << "Bureaucrat assignment constructor of " << this->getName() << " called." << std::endl;
	this->setGrade(grade);
}
		
Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}
		
Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &src)
{
	this->_name = src._name;
	this->_grade = src._grade;
	return (*this);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}
		
std::string const &Bureaucrat::getName() const
{
	return (this->_name);
}
		
int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}
		
void Bureaucrat::increaseGrade()
{
	std::cout << "Grade of " << this->getName() << " is about to be incremented one." << std::endl;
	this->setGrade(this->_grade - 1);
}
		
void Bureaucrat::decreaseGrade()
{
	std::cout << "Grade of " << this->getName() << " is about to be decremented one." << std::endl;
	this->setGrade(this->_grade + 1);
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
