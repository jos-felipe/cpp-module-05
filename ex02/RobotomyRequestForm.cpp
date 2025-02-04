/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:06:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 16:45:19 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE, "default") {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE, target) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &rhs) {
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

void RobotomyRequestForm::makeNoise() const {
    std::cout << "* Drilling noises * ";
    std::cout << "Bzzzzzzt! ";
    std::cout << "Whirrrrrr! ";
    std::cout << "Drrrrrill! *" << std::endl;
}

bool RobotomyRequestForm::attemptRobotomy() const {
    return (std::rand() % 2 == 0);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    this->checkExecuteRequirements(executor);

    makeNoise();

    if (attemptRobotomy()) {
        std::cout << this->getTarget() << " has been robotomized successfully!"
            << std::endl;
    } else {
        std::cout << "Robotomy of " << this->getTarget() << " has failed..."
            << std::endl;
    }
}