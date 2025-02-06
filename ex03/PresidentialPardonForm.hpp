/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:20 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/04 17:15:42 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	static const int SIGN_GRADE = 25;
	static const int EXEC_GRADE = 5;

	void announcePardon() const;

  public:
	PresidentialPardonForm();
	explicit PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	virtual void execute(Bureaucrat const &executor) const;
};

#endif
