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

		// INPUT FORM (exec grade is set at 1 by default)
		std::cout << std::endl;
		std::cout << BBLU << "Please enter the name of the form:" << RESET << std::endl;
		std::string f_name;
		std::getline(std::cin, f_name);
		if (std::cin.eof())
			return (0);
		std::cout <<  BBLU << "Please enter the min grade to sign the form:" << RESET << std::endl;
		std::string sgrade;
		int			n_sgrade;
		std::getline(std::cin, sgrade);
		if (std::cin.eof())
			return (0);
		n_sgrade = atoi(sgrade.c_str());
		// std::cout << BBLU << "Please enter the min grade to execute the form:" << RESET << std::endl;
		// std::string egrade;
		int			n_egrade = 1;
		// std::getline(std::cin, egrade);
		// if (std::cin.eof())
		// 	return (0);
		// n_egrade = atoi(egrade.c_str());
		
		// CREATES FORM IF GRADE IS VALID
		try {
			Form testform(f_name, n_sgrade, n_egrade);

			std::cout << std::endl;
			std::cout << BLU << testform << RESET << std::endl;

			// LOOP TO TEST FUNCTIONS
			while (line != "EXIT")
			{
				std::cout << std::endl;
				std::cout << BBLU << "To test the functions please enter one of the following:" << RESET << std::endl;
				std::cout << BBLU << "INCRGRADE - DECRGRADE - SIGN - SEE - EXIT" << RESET << std::endl;

				// GET USER INPUT
				std::getline(std::cin, line);
				if (std::cin.eof())
					return (0);

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
						Thierry.signForm(testform);
					}
					catch (std::exception const &e)  {
						std::cerr << RED << Thierry.getName() << " couldn't sign " << testform.getName() << " because " << e.what() << RESET << std::endl;
					}
				}

				// GENERATES OUTPUT ON BUREAUCRAT AND FORM
				if (line == "SEE") {
					std::cout << std::endl;
					std::cout << Thierry << std::endl;
					std::cout << testform << std::endl;
				}
			}
		}
		catch (std::exception const &e) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
	catch (std::exception const &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}