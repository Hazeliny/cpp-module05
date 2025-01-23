/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:13:08 by linyao            #+#    #+#             */
/*   Updated: 2025/01/23 22:47:33 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form a("form00", -1, 6);
        std::cout << a << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
    try
    {
        Bureaucrat sara("Sara", 16);
        Form b("form01", 18, 60);
        std::cout << sara << std::endl;
        std::cout << b << std::endl;
        sara.signForm(b);
        std::cout << b << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
    try
    {
        Bureaucrat amy("Amy", 88);
        Form c("form02", 38, 60);
        std::cout << amy << std::endl;
        std::cout << c << std::endl;
        amy.signForm(c);
        std::cout << c << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
