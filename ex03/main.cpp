/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:46:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/06 12:22:29 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

void	printHeader(const std::string &header)
{
	std::cout << "\n=== " << header << " ===" << std::endl;
}

int	main(void)
{
	try
	{
		// Create bureaucrats with different authority levels
		printHeader("Creating Bureaucrats");
		Bureaucrat director("Director", 5); // Highest rank
		std::cout << director << std::endl;

		// Create an intern
		printHeader("Creating Intern");
		Intern someRandomIntern;

		// Test form creation
		printHeader("Testing Form Creation");

		// Test successful creation
		AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		director.signForm(*rrf);
		director.executeForm(*rrf);
		delete rrf;

		// Test presidential pardon form
		AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");
		director.signForm(*ppf);
		director.executeForm(*ppf);
		delete ppf;

		// Test shrubbery creation form
		AForm *scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
		director.signForm(*scf);
		director.executeForm(*scf);
		delete scf;

		// Test error case with unknown form
		printHeader("Testing Unknown Form");
		AForm *unknown = someRandomIntern.makeForm("coffee making", "Kitchen");
		delete unknown; // This line won't be reached due to exception
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
