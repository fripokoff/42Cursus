/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:00:41 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class GradeTooHighException : public IException
{
	public:
		GradeTooHighException() {}
		virtual const char*	what() const throw() { return "Grade too high"; }
};
class GradeTooLowException : public IException
{
	public:
		GradeTooLowException() {}
		virtual const char*	what() const throw() { return "Grade too low"; }
};
class FormAlreadySigned : public IException
{
	public:
		FormAlreadySigned() {}
		virtual const char*	what() const throw() { return "Form already signed"; }
};
class FormNotSigned : public IException
{
	public:
		FormNotSigned() {}
		virtual const char*	what() const throw() { return "Form not signed"; }
};
class FileException : public IException
{
	public:
		FileException() {}
		virtual const char*	what() const throw() { return "Couldn't create or fill the file"; }
};

class AForm
{
	public:
		/* >------ Cons/Destructors ------< */
		AForm(std::string const &name = DEFAULT_NAME,
			int const toSign = DEFAULT_GRADE, int const toExecute = DEFAULT_GRADE);
		virtual ~AForm();
		AForm(AForm const &other);

		/* >------ Get/Setters ------< */
		std::string		getName() const { return _name; }
		int				getIsSigned() const { return _isSigned; }
		int				getGradeToSign() const { return _gradeToSign; }
		int				getGradeToExecute() const { return _gradeToExecute; }
		void			setIsSigned(int isSigned) { _isSigned = isSigned; }

		/* >------ Actions ------< */
		void			beSigned(Bureaucrat const &signatory);
		virtual void	execute(Bureaucrat const &executor) const = 0;

		/* >------ Overloads ------< */
		AForm			&operator=(AForm const &other);

		/* >------ Exceptions ------< */
		
		class AFormException : public GradeTooHighException, public GradeTooLowException,
			public FormAlreadySigned, public FormNotSigned, public FileException
		{
			public:
				AFormException() {};
		};

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &outputStream, AForm const &it);

#endif