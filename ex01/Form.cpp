/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:15:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 13:01:09 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high! Must be between 1 and 150");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low! Must be between 1 and 150");
}

Form::Form() : _name("default"), _signed(false), _gradeToSign(150),
	_gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign,
	int gradeToExecute) : _name(name), _signed(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src.getName()),
	_gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	*this = src;
}

Form::~Form()
{
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		this->_signed = rhs.isSigned();
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::isSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << ":" << std::endl << "Status: " << 
	(form.isSigned() ? "signed" : "not signed") << std::endl << 
	"Grade to sign: " << form.getGradeToSign() << std::endl << 
	"Grade to execute: " << form.getGradeToExecute();
	return (out);
}
