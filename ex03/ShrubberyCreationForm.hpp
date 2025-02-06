/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:15:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 14:49:53 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
  private:
	static const int SIGN_GRADE = 145;
	static const int EXEC_GRADE = 137;

	void drawAsciiTree(std::ofstream &outFile) const;

  public:
	ShrubberyCreationForm();
	explicit ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	virtual void execute(Bureaucrat const &executor) const;

	class FileOperationException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

#endif
