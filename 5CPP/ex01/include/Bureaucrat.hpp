#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Form.hpp"

class Bureaucrat {
  private:
	std::string 	_name;
	unsigned int	_grade;
  public:
	// Constructors & destructor
	Bureaucrat(int grade, std::string name);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& other);

	// Getters and setters
	unsigned int	getGrade() const;
	std::string		getName() const;
	void			incrementGrade();
	void			decrementGrade();

	// Other member functions
	void			signForm(Form &f) const;

	// Exception classes
	class GradeTooHighException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i );

#endif