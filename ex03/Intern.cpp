/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:31:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/06 12:18:57 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Initialize the static array of form types
const Intern::FormType Intern::_formTypes[] = {{"shrubbery creation",
	&Intern::createShrubberyForm}, {"robotomy request",
	&Intern::createRobotomyForm}, {"presidential pardon",
	&Intern::createPresidentialForm}};

const char *Intern::UnknownFormException::what() const throw()
{
	return ("Unknown form type requested");
}

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

AForm *Intern::createShrubberyForm(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyForm(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialForm(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (int i = 0; i < _formCount; i++)
	{
		if (formName == _formTypes[i].name)
		{
			AForm *form = (this->*_formTypes[i].creator)(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	throw UnknownFormException();
}
