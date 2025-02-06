/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:15:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/06 12:16:56 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
  private:
	typedef AForm *(Intern::*FormCreator)(const std::string &) const;

	struct					FormType
	{
		std::string			name;
		FormCreator			creator;
	};

	AForm *createShrubberyForm(const std::string &target) const;
	AForm *createRobotomyForm(const std::string &target) const;
	AForm *createPresidentialForm(const std::string &target) const;

	static const FormType	_formTypes[];
	static const int		_formCount = 3;

  public:
	Intern();
	Intern(const Intern &src);
	~Intern();
	Intern &operator=(const Intern &rhs);

	AForm *makeForm(const std::string &formName, const std::string &target);

	class UnknownFormException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

#endif
