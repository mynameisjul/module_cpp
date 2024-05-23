#include "Zombie.h"

int get_index(int n) {
	std::string	input;
	int			output = -2;

	std::cout << BYEL << "Please enter the index of the zombie you want announced from 0 to " << n - 1 << RESET << std::endl;
	std::cout << YEL << "(you can enter random things but it's not the purpose)" << RESET << std::endl;
	if (!std::getline(std::cin, input) || std::cin.eof())
		return (-1);
	const char *charinput = input.c_str();
	output = atoi(charinput);
	if (output < 0 || output >= n)
		std::cout << RED << "Index is out of range." << RESET << std::endl;
	return (output);
}

std::string get_input(std::string message, std::string color) {
	std::string input;
	
	std::cout << color << message << RESET << std::endl;
	if (!std::getline(std::cin, input) || std::cin.eof())
		return ("");
	return (input);
}

int main(int ac, char **av) {
	std::string	line;

	if (ac != 3)
	{
		std::cout << YEL << "Input format should be ./zombie_horde zombies_name number_of_zombies" << RESET << std::endl;
		return (1);
	}

	// Enters the program
	std::cout << BHYEL << "Welcome to Zombiland" << RESET << std::endl;
	int N = atoi(av[2]);
	char *name = av[1];
	std::string str(name);
	Zombie *horde = zombieHorde(N, name);

	// Loop to interact with user
	while (1)
	{
		int i = -2;

		i = get_index(N);
		if (i == -1)
			break;
		if (i >= 0 && i <= N) {
			std::cout << YEL << "Zombie " << i << " will now announce himself" << RESET << std::endl;
			horde[i].announce();
		}

		if (get_input("Press enter to exit or type anything to keep going", YEL) == "")
			break;
	}
	delete [] horde;
	return (0);
}