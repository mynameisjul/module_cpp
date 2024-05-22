#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string get_input() {
	std::string input = "";
	int			i = 0;

	while (input[0] == 0)
	{
		std::cout << "To start, enter a command [ADD, SEARCH, EXIT]" << std::endl;
		if (!std::getline(std::cin, input))
			return ("");
		if (std::cin.eof())
			return ("");
		if (input.compare("ADD") && input.compare("EXIT") && input.compare("SEARCH") && input.compare("HELP"))
			std::cout << "Invalid command. Please try again." << std::endl;
		else
			return (input);
		if (i > 2)
		{
			std::cout << " You seem to have troubles typing." << std::endl;
			std::cout << "To add a new contact, type 'ADD'." << std::endl;
			std::cout << "To search for a contact, type 'SEARCH'." << std::endl;
			std::cout << "To exit type 'EXIT'." << std::endl;
		}
		i++;
	}
	return (input);
}

int	add(PhoneBook &my_phonebook) {
	if (my_phonebook.update_PhoneBook() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	search(PhoneBook &my_phonebook) {
	if (my_phonebook.search_PhoneBook() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int main(void) {
	std::string	cmd;
	PhoneBook	my_phonebook;

	std::cout << "Welcome to your ultra-modern phonebook" << std::endl;
	while (cmd.compare("EXIT"))
	{
		if (!cmd.compare("ADD")){
			if (add(my_phonebook) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (!cmd.compare("SEARCH")){
			if (search(my_phonebook) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		if (std::cin.eof())
			return (EXIT_FAILURE);
		cmd = get_input();
	}
	std::cout << "Phonebook will be exited and deleted . . ." << std::endl;
	return (EXIT_SUCCESS);
}