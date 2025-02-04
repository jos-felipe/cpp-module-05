/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:31:53 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 11:33:22 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		// Test normal case
		Bureaucrat normal("John", 75);
		std::cout << normal << std::endl;
		// Test increment/decrement
		normal.incrementGrade();
		std::cout << "After increment: " << normal << std::endl;
		normal.decrementGrade();
		std::cout << "After decrement: " << normal << std::endl;
		// Test grade too high
		Bureaucrat high("High", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		// Test grade too low
		Bureaucrat low("Low", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
