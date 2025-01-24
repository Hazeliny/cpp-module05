/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:03:49 by linyao            #+#    #+#             */
/*   Updated: 2025/01/24 23:04:32 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        PresidentialPardonForm const &operator=(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();
        std::string const &getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &f);
