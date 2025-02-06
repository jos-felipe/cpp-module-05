/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:30:53 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 17:52:35 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Helper function to print section headers
void printHeader(const std::string &header) {
    std::cout << "\n=== " << header << " ===" << std::endl;
}

int main(void)
{
    try
    {
        // Create bureaucrats with different authority levels
        printHeader("Creating Bureaucrats");
        Bureaucrat intern("Intern", 150);        // Lowest rank
        Bureaucrat clerk("Clerk", 72);           // Mid-rank
        Bureaucrat supervisor("Supervisor", 45);  // Higher rank
        Bureaucrat director("Director", 5);       // Highest rank

        // Print initial bureaucrat information
        std::cout << intern << std::endl;
        std::cout << clerk << std::endl;
        std::cout << supervisor << std::endl;
        std::cout << director << std::endl;

        // Test ShrubberyCreationForm (sign: 145, exec: 137)
        printHeader("Testing ShrubberyCreationForm");
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;
        
        // Intern shouldn't be able to sign
        intern.signForm(shrub);
        intern.executeForm(shrub);  // Should fail
        
        // Clerk should be able to sign and execute
        supervisor.signForm(shrub);
		supervisor.executeForm(shrub);  // Should succeed

        // Test RobotomyRequestForm (sign: 72, exec: 45)
        printHeader("Testing RobotomyRequestForm");
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;
        
        // Intern trying to sign (should fail)
        intern.signForm(robotomy);
        
        // Clerk can sign
        clerk.signForm(robotomy);
        
        // But only supervisor or higher can execute
        clerk.executeForm(robotomy);    // Should fail
        supervisor.executeForm(robotomy); // Should succeed

        // Test PresidentialPardonForm (sign: 25, exec: 5)
        printHeader("Testing PresidentialPardonForm");
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        
        // Try with various bureaucrats
        supervisor.signForm(pardon);     // Should fail
        director.signForm(pardon);       // Should succeed
        supervisor.executeForm(pardon);   // Should fail
        director.executeForm(pardon);     // Should succeed

        // Test executing unsigned form
        printHeader("Testing Unsigned Form Execution");
        PresidentialPardonForm unsignedPardon("Zaphod");
        director.executeForm(unsignedPardon);  // Should fail - not signed
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
    
    return (0);
}
