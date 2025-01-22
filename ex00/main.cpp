/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:37:32 by linyao            #+#    #+#             */
/*   Updated: 2025/01/22 23:47:52 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat *jack = NULL;
    Bureaucrat *vivi = NULL;
    try
    {
        jack = new Bureaucrat("Jack", -2);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
            std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        vivi = new Bureaucrat("Vivi", 151);
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
            std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    if (jack)
        delete jack;
    else
        std::cout << "The 1st object jack wasn't constructed successfully, so now it isn't decontructed." << std::endl;
    if (vivi)
        delete vivi;
    else
        std::cout << "The 2nd object vivi wasn't constructed successfully, so now it isn't decontructed." << std::endl;

    Bureaucrat *a = NULL;
    Bureaucrat *b = NULL;
    try
    {
        a = new Bureaucrat("Sofia", 1);
        std::cout << *a << std::endl;
        a->increaseGrade();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        if (a)
            std::cerr << a->getName() << ": " << e.what() << std::endl;
    }
    try
    {
        b = new Bureaucrat("Bob", 150);
        std::cout << *b << std::endl;
        b->decreaseGrade();
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        if (b)
            std::cerr << b->getName() << ": " << e.what() << std::endl;
    }
    if (a)
        delete a;
    else
        std::cout << "The 3rd object a wasn't constructed successfully, so now it isn't decontructed." << std::endl;
    if (b)
        delete b;
    else
        std::cout << "The 4th object b wasn't constructed successfully, so now it isn't decontructed." << std::endl;
    return (0);
}
