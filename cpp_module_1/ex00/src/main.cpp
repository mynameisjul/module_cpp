#include "Zombie.h"

int main() {
	std::string	line;

	// Enters the program
	std::cout << BHYEL << "Welcome to Zombiland" << RESET << std::endl;

	// Loop to interact with user
	while (1)
	{
		std::cout << YEL << "To test the functions please enter one of the following:" << RESET << std::endl;
		std::cout << YEL << "NEWZ" << RESET << std::endl;
		std::cout << YEL << "RANDC" << RESET << std::endl;
		std::cout << YEL << "or write 'EXIT' to exit the program" << RESET << std::endl;

		// Gets user cmd and protects against ctr+D
		std::getline(std::cin, line);
		if (std::cin.eof())
			return (0);
		
		// Gets user input for the name if user wants to create a Zombie
		std::string name;
		if (line == "NEWZ" || line == "RANDC")
		{
			std::cout << YEL << "Enter the name of the Zombie:" << RESET << std::endl;
			
			// Gets the name and protects against ctr+D
			std::getline(std::cin, name);
			if (std::cin.eof())
				return (0);

				// Creates Zombie on the heap
			if (line == "NEWZ")
			{
				Zombie *new_zombie;

				new_zombie = newZombie(name);
				delete(new_zombie);
			}

			// Creates Zombie on the stack
			if (line == "RANDC")
			{
				Zombie new_zombie(name);
			}
		}
		
		// Exits program
		if (line == "EXIT")
			break;
	}
	return (0);
}