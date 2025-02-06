/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:41:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 17:20:45 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE, "default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : 
AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &src) : AForm(src)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return (*this);
}

void PresidentialPardonForm::announcePardon() const
{
	std::cout << this->getTarget() << 
	" has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkExecuteRequirements(executor);

	announcePardon();
}