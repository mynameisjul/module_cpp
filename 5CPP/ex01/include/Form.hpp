#ifndef FORM_HPP
#define FORM_HPP

#include "bureaucrats.h"

class Bureaucrat;

class Form {
	private:
		std::string		_name;
		bool			_signed;
		unsigned int	_sign_grade;
		unsigned int	_exec_grade;
	public:
		// ========== CONSTRUCTORS AND DESTRUCTOR
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);

		// ========== SETTERS AND GETTERS
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		std::string getName() const;

		// ========== OTHER MEMBER FUNCTIONS
		void	beSigned(Bureaucrat const &i);

		// ========== EXCEPTION CLASS
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw(); 
		};

		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream &o, Form const & i);

#endif /* FORM_HPP */