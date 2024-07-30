#ifndef INTERN_HPP
#define INTERN_HPP

#include "bureaucrats.h"

class Intern {
	public:
		// ========== MEMBER FUNCTIONS
		AForm	*makeForm(std::string name, std::string target);
		// ========== CONSTRUCTORS AND DESTRUCTOR
		Intern();
		Intern(const Intern& other);
		~Intern();
		Intern& operator=(const Intern& other);

		// EXCEPTION
		class BadFormNameException : public std::exception {
			public:
				virtual const char * what() const throw();
		};
};

#endif /* INTERN_HPP */

