#include "animal.h"

int main()
{
	// Array creation
	AAnimal *animals[100];
	
	int i = 0;
	while (i < 50) {
		animals[i] = new Cat(); 
		i++;}
	while (i < 100) {
		animals[i] = new Dog();
		i++;}

	// Interactive test program
	std::string line = "";
	while (line != "EXIT")
	{
		std::cout << YEL << "To test the functions please enter one of the following:" << RESET << std::endl;
		std::cout << YEL << "MKSOUND" << RESET << std::endl;
		std::cout << YEL << "GETIDEA" << RESET << std::endl;
		std::cout << YEL << "CHANGEIDEA" << RESET << std::endl;
		std::cout << YEL << "or write 'EXIT' to exit the program" << RESET << std::endl;

		// Gets user cmd and protects against ctr+D
		std::getline(std::cin, line);
		if (std::cin.eof())
			return (0);

		if (line == "MKSOUND" || line == "GETIDEA" || line == "CHANGEIDEA")
		{
			std::cout << YEL << "Please enter the animal's index from 0 to 99" << RESET << std::endl;

			// Gets animal index and protects against ctr+D
			std::string index = "";
			std::getline(std::cin, index);
			if (std::cin.eof())
				return (0);
			int n_index = atoi(index.c_str());
			if (n_index < 0 || n_index > 99)
				std::cout << RED << "Wrong index" << RESET << std::endl;
			else {
				if (line == "MKSOUND")
					animals[n_index]->makeSound();

				if (line == "GETIDEA" || line == "CHANGEIDEA")
				{
					// Gets idea index and protects against ctr+D
					std::string idea_index = "";
					std::cout << YEL << "Please enter the idea's index from 0 to 99" << RESET << std::endl;
					std::getline(std::cin, idea_index);
					if (std::cin.eof())
						return (0);
					int n_idea_index = atoi(idea_index.c_str());
					if (n_idea_index < 0 || n_idea_index > 99)
						std::cout << RED << "Wrong index" << RESET << std::endl;
					else {
						if (line == "GETIDEA")
							std::cout << animals[n_index]->getIdea(n_idea_index) << std::endl;
						if (line == "CHANGEIDEA"){
							std::string new_idea = "";
							std::cout << YEL << "Please enter the new idea" << RESET << std::endl;
							std::getline(std::cin, new_idea);
							if (std::cin.eof())
								return (0);
							animals[n_index]->setIdea(n_idea_index, new_idea);
							std::cout << "Idea correctly set" << std::endl;
						}
					}
				}
			}
		}

		// Exits program
		if (line == "EXIT")
			break;
	}

	//If i remove this line: does not compile (AAnimal is an abstract class)
	//AAnimal animal_test;

	for (int i = 0; i < MAX_IDEAS; i++)
	{
		delete animals[i];
	}
	return (0);
}