/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:40:00 by linyao            #+#    #+#             */
/*   Updated: 2025/01/22 17:40:08 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}
		
Bureaucrat::~Bureaucrat()
{}
		
Bureaucrat::Bureaucrat(std::string const &name, int grade)
{}
		
Bureaucrat::Bureaucrat(Bureaucrat const &src)
{}
		
Bureaucrat &Bureaucrat::operator= (Bureaucrat const &src)
{}

void	Bureaucrat::setGrade(int grade)
{}
		
std::string const &Bureaucrat::getName() const
{}
		
int	Bureaucrat::getGrade() const
{}
		
void Bureaucrat::increaseGrade()
{}
		
void Bureaucrat::decreaseGrade()
{}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{

}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{

}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}
