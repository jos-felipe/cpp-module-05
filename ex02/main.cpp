/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:40:53 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 13:14:09 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        // Create a bureaucrat and a form
        Bureaucrat bob("Bob", 100);
        Form form1("Tax Form", 90, 100);
        
        // Print initial state
        std::cout << "Initial state:" << std::endl;
        std::cout << bob << std::endl;
        std::cout << form1 << std::endl << std::endl;
        
        // Try to sign the form (should fail - grade too low)
        bob.signForm(form1);
        std::cout << std::endl;
        
        // Promote Bob and try again
        for (int i = 0; i < 15; i++)
            bob.incrementGrade();
        
        std::cout << "After promotion:" << std::endl;
        std::cout << bob << std::endl << std::endl;
        
        // Try to sign again (should succeed)
        bob.signForm(form1);
        std::cout << std::endl << form1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return (0);
}
