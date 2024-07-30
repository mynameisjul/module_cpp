#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "bureaucrats.h"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		// ========== OTHER MEMBER FUNCTIONS
		virtual void	exec() const;
		// ========== CONSTRUCTORS AND DESTRUCTOR
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};

#endif /* ROBOTOMYREQUESTFORM_HPP */