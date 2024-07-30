#include "bureaucrats.h"

int main() {
	std::string line = "";

	// INPUT BUREAUCRAT
	std::cout << BBLU << "Please enter the name of the bureaucrat:" << RESET << std::endl;
	std::string name;
	std::getline(std::cin, name);
	if (std::cin.eof())
		return (0);
	std::cout <<  BBLU << "Please enter the grade of the bureaucrat:" << RESET << std::endl;
	std::string grade;
	int			n_grade;
	std::getline(std::cin, grade);
	if (std::cin.eof())
		return (0);
	n_grade = atoi(grade.c_str());

	try {
		// CREATES BUREAUCRAT IF GRADE IS VALID
		Bureaucrat Thierry = Bureaucrat(n_grade, name);

		std::cout << std::endl;
		std::string type = "";
		while (type != "SHRUB" && type != "PRES" && type != "ROBOT") {
			std::cout << BBLU << "What type of form do you want to create?" << RESET << std::endl;
			std::cout << BBLU << "SHRUB - PRES - ROBOT" << RESET << std::endl;
			std::getline(std::cin, type);
			if (std::cin.eof())
				return (0);
		}

		std::string target;
		std::cout << BBLU << "What is the target?" << RESET << std::endl;
		std::getline(std::cin, target);
		if (std::cin.eof())
			return (0);
		
		AForm *testform;
		if (type == "SHRUB")
				testform = new ShrubberyCreationForm(target);
		if (type == "PRES")
				testform = new PresidentialPardonForm(target);
		if (type == "ROBOT")
				testform = new RobotomyRequestForm(target);

		std::cout << std::endl;
		std::cout << BLU << *testform << RESET << std::endl;

		// LOOP TO TEST FUNCTIONS
		while (line != "EXIT")
		{
			std::cout << std::endl;
			std::cout << BBLU << "To test the functions please enter one of the following:" << RESET << std::endl;
			std::cout << BBLU << "INCRGRADE - DECRGRADE - SIGN - EXEC - SEE - EXIT" << RESET << std::endl;

			// GET USER INPUT
			std::getline(std::cin, line);
			if (std::cin.eof())
				return (delete testform, 0);

			// INCREMENT GRADE BLOCK
			if (line == "INCRGRADE") {
			std::cout << std::endl;
				try {
					Thierry.incrementGrade();
					std::cout << Thierry << std::endl;
				}
				catch (Bureaucrat::GradeTooHighException const &e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
			}

			// DECREMENT GRADE BLOCK
			if (line == "DECRGRADE") {
			std::cout << std::endl;
				try {
					Thierry.decrementGrade();
					std::cout << Thierry << std::endl;
				}
				catch (Bureaucrat::GradeTooLowException const &e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
			}

			// SIGN BLOCK
			if (line == "SIGN") {
				std::cout << std::endl;
				try {
					Thierry.signForm(*testform);
				}
				catch (std::exception const &e)  {
					std::cerr << RED << Thierry.getName() << " couldn't sign " << testform->getName() << " because " << e.what() << RESET << std::endl;
				}
			}

			// EXEC BLOCK
			if (line == "EXEC") {
				std::cout << std::endl;
				try {
					Thierry.executeForm(*testform);
				}
				catch (std::exception const &e)  {
					std::cerr << RED << Thierry.getName() << " couldn't sign " << testform->getName() << " because " << e.what() << RESET << std::endl;
				}
			}

			// GENERATES OUTPUT ON BUREAUCRAT AND FORM
			if (line == "SEE") {
				std::cout << std::endl;
				std::cout << Thierry << std::endl;
				std::cout << *testform << std::endl;
			}
		}
		delete testform;
	}
	catch (std::exception const &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
}