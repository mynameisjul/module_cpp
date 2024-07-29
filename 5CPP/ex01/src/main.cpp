#include "bureaucrats.h"

int main() {
	std::string line = "";

	while (line != "EXIT")
	{
		// CREATE BUREAUCRAT
		std::cout << BBLU << "Please enter the name of the bureaucrat:" << RESET << std::endl;
		std::string name;
		std::getline(std::cin, name);
		if (std::cin.eof())
			return (0);
		std::cout << "Please enter the grade of the bureaucrat:" << std::endl;
		std::string grade;
		int			n_grade;
		std::getline(std::cin, grade);
		if (std::cin.eof())
			return (0);
		n_grade = atoi(grade.c_str());
		try {
			Bureaucrat Thierry = Bureaucrat(n_grade, name);

			if (line == "GETGRADE")
				std::cout << "Bureaucrat's grade is " << Thierry.getGrade() << std::endl;

			if (line == "GETNAME")
				std::cout << "Bureaucrat's name is " << Thierry.getName() << std::endl;

			if (line == "INCRGRADE") {
				try {
		Thierry.incrementGrade();
		std::cout << Thierry << std::endl;
				}
				catch (Bureaucrat::GradeTooHighException const &e) {
		std::cerr << "Error: " << e.what() << std::endl;
				}
			}

			if (line == "DECRGRADE") {
				try {
		Thierry.decrementGrade();
		std::cout << Thierry << std::endl;
				}
				catch (Bureaucrat::GradeTooLowException const &e) {
		std::cerr << "Error: " << e.what() << std::endl;
				}
			}

			}
		catch (std::exception const &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		}
		
	}
}