/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:03:16 by kpires            #+#    #+#             */
/*   Updated: 2026/01/26 21:30:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define DEFAULT_NAME	"DefaultName"
# define DEFAULT_GRADE	75

# define MINIMAL_GRADE	150
# define MAXIMAL_GRADE	1

# include <exception>
# include <string>

class IBureaucratException : public std::exception
{
	public:
		virtual const char* what() const throw() = 0;
};

class Bureaucrat
{
	public:
		/* >------ Cons/Destructors ------< */
		Bureaucrat(std::string const &name = DEFAULT_NAME, int grade = DEFAULT_GRADE);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &other);

		/* >------ Overloads ------< */
		Bureaucrat	&operator=(Bureaucrat const &other);

		/* >------ Setters ------< */
		void		upGrade();
		void		downGrade();

		/* >------ Getters ------< */
		std::string	getName() const;
		int			getGrade() const;

		/* >------ Exceptions ------< */
		class GradeTooHighException : public IBureaucratException
		{
			public:
				GradeTooHighException() {}
				virtual const char*	what() const throw() { return "Too high"; }
		};
		class GradeTooLowException : public IBureaucratException
		{
			public:
				GradeTooLowException() {}
				virtual const char*	what() const throw() { return "Too low"; }
		};

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &it);

#endif