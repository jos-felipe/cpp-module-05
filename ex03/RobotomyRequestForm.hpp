/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:50:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 16:38:46 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
  private:
	static const int SIGN_GRADE = 72;
	static const int EXEC_GRADE = 45;

	void makeNoise() const;
	bool attemptRobotomy() const;

  public:
	RobotomyRequestForm();
	explicit RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	virtual void execute(Bureaucrat const &executor) const;
};

#endif