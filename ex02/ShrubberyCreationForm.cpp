/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:31:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 16:32:44 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::FileOperationException::what() const throw()
{
	return ("Error during file operation");
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation",
	SIGN_GRADE, EXEC_GRADE, "default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : 
AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &src) : AForm(src)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return (*this);
}

void ShrubberyCreationForm::drawAsciiTree(std::ofstream &outFile) const
{
	outFile << "      *      " << std::endl;
	outFile << "     ***     " << std::endl;
	outFile << "    *****    " << std::endl;
	outFile << "   *******   " << std::endl;
	outFile << "  *********  " << std::endl;
	outFile << "     |||     " << std::endl;
	outFile << "     |||     " << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->checkExecuteRequirements(executor);

	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outFile(filename.c_str());

	if (!outFile.is_open())
		throw FileOperationException();

	drawAsciiTree(outFile);
	outFile << std::endl;
	drawAsciiTree(outFile);

	outFile.close();
}
