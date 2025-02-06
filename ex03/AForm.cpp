/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:46:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 15:01:09 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high! Must be between 1 and 150";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low! Must be between 1 and 150";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150),
    _gradeToExecute(150), _target("default") {
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute,
    const std::string &target) : _name(name), _signed(false),
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
    _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src.getName()),
    _gradeToSign(src.getGradeToSign()),
    _gradeToExecute(src.getGradeToExecute()) {
    *this = src;
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &rhs) {
    if (this != &rhs) {
        _signed = rhs.isSigned();
        _target = rhs.getTarget();
    }
    return *this;
}

std::string AForm::getName() const {
    return this->_name;
}

bool AForm::isSigned() const {
    return this->_signed;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

std::string AForm::getTarget() const {
    return this->_target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

void AForm::checkExecuteRequirements(Bureaucrat const &executor) const {
    if (!this->_signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() << ":" << std::endl
        << "Status: " << (form.isSigned() ? "signed" : "not signed") << std::endl
        << "Grade to sign: " << form.getGradeToSign() << std::endl
        << "Grade to execute: " << form.getGradeToExecute() << std::endl
        << "Target: " << form.getTarget();
    return out;
}