#include "animal.h"

int main()
{
	std::string line = "";

	// Enters the program
	std::cout << BHYEL << "Welcome to Happy Animal Hotel" << RESET << std::endl;

	// Loop to interact with user
	while (line != "EXIT")
	{
		std::cout << YEL << "To test the functions please enter one of the following:" << RESET << std::endl;
		std::cout << YEL << "NDOG" << RESET << std::endl;
		std::cout << YEL << "NCAT" << RESET << std::endl;
		std::cout << YEL << "NANIMAL" << RESET << std::endl;
		std::cout << YEL << "SDOG" << RESET << std::endl;
		std::cout << YEL << "SCAT" << RESET << std::endl;
		std::cout << YEL << "SANIMAL" << RESET << std::endl;
		std::cout << YEL << "WRONG" << RESET << std::endl;
		std::cout << YEL << "SUBJ" << RESET << std::endl;
		std::cout << YEL << "or write 'EXIT' to exit the program" << RESET << std::endl;

		// Gets user cmd and protects against ctr+D
		std::getline(std::cin, line);
		if (std::cin.eof())
			return (0);

		// Gets user input for the name if user wants to create a Zombie
		if (line == "NDOG" || line == "NCAT" || line == "NANIMAL")
		{
			// Creates Animal on the stack
			if (line == "NDOG")
				Dog dog;

			if (line == "NCAT")
				Cat cat;

			if (line == "NANIMAL")
				Animal animal;
		}

		if (line == "SDOG" || line == "SCAT" || line == "SANIMAL")
		{
			// Creates Animal on the stack
			if (line == "SDOG")
			{
				Dog dog;
				dog.makeSound();
			}

			if (line == "SCAT")
			{
				Cat cat;
				cat.makeSound();
			}

			if (line == "SANIMAL")
			{
				Animal animal;
				animal.makeSound();
			}
		}

		if (line == "WRONG")
		{
			const WrongAnimal *meta = new WrongAnimal();
			const Animal *j = new Dog();
			const WrongAnimal *i = new WrongCat();
			std::cout << j->getType() << " " << std::endl;
			std::cout << i->getType() << " " << std::endl;
			i->makeSound(); // will not output the cat sound!
			j->makeSound();
			meta->makeSound();
			delete (meta);
			delete (i);
			delete (j);
		}

		if (line == "SUBJ")
		{
			const Animal *meta = new Animal();
			const Animal *j = new Dog();
			const Animal *i = new Cat();
			std::cout << j->getType() << " " << std::endl;
			std::cout << i->getType() << " " << std::endl;
			i->makeSound(); // will output the cat sound!
			j->makeSound();
			meta->makeSound();
			delete (meta);
			delete (i);
			delete (j);
		}

		// Exits program
		if (line == "EXIT")
			break;
	}
	return (0);
}