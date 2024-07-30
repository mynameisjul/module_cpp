#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "bureaucrats.h"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		// ========== OTHER MEMBER FUNCTIONS
		virtual void	exec() const;
		// ========== CONSTRUCTORS AND DESTRUCTOR
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};

#endif /* PRESIDENTIALPARDONFORM_HPP */