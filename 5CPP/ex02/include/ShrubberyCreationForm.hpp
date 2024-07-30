#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "bureaucrats.h"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		// ========== OTHER MEMBER FUNCTIONS
		virtual void	exec() const;
		// ========== CONSTRUCTORS AND DESTRUCTOR
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
};

#endif /* SHRUBBERYCREATIONFORM_HPP */