/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:03:17 by linyao            #+#    #+#             */
/*   Updated: 2025/01/24 22:42:38 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        RobotomyRequestForm const &operator=(RobotomyRequestForm const &src);
        ~RobotomyRequestForm();
        std::string const &getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &f);
