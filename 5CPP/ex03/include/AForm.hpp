#ifndef AFORM_HPP
#define AFORM_HPP

#include "bureaucrats.h"

class Bureaucrat;

class AForm {
	protected:
		std::string		_name;
		bool			_signed;
		unsigned int	_sign_grade;
		unsigned int	_exec_grade;
		std::string		_target;
	public:
		// ========== CONSTRUCTORS AND DESTRUCTOR
						AForm(std::string name, int sign_grade, int exec_grade);
						AForm(const AForm& other);
		virtual 		~AForm();
		AForm& 			operator=(const AForm& other);

		// ========== SETTERS AND GETTERS
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		std::string 	getName() const;

		// ========== OTHER MEMBER FUNCTIONS
		void			beSigned(Bureaucrat const &i);
		void			execute(Bureaucrat const &executor) const;
		virtual void	exec() const;

		// ========== EXCEPTION CLASS
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw(); 
		};

		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream &o, AForm const & i);

#endif /* AFORM_HPP */